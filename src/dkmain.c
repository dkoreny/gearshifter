#include <avr/io.h>
#include "gearshifter.h"

/*
Layout 
- Global definitions
- LUFA required definitions and callback functions


*/


/* Globals */

uint8_t ssd1306_addr;					// SSD1306 i2c address
uint16_t yaxis_value, xaxis_value; 	// Current x and y axis ADC values.
uint8_t current_gear;					// Current gear selection
uint8_t reverse_gear;					// Current state of reverse switch
uint8_t usb_connected;					// usb connection state (0=dead,1=connected)
char test_adc_value_x[ADC_MAX_LEN], \
	test_adc_value_y[ADC_MAX_LEN], \
	gear_string[GS_MAX_LEN];


// Required for LUFA - stores last report - only sends deltas. 
static uint8_t PrevJoystickHIDReportBuffer[sizeof(USB_JoystickReport_Data_t)];

USB_ClassInfo_HID_Device_t Joystick_HID_Interface =
	{
		.Config =
			{
				.InterfaceNumber              = INTERFACE_ID_Joystick,
				.ReportINEndpoint             =
					{
						.Address              = JOYSTICK_EPADDR,
						.Size                 = JOYSTICK_EPSIZE,
						.Banks                = 1,
					},
				.PrevReportINBuffer           = PrevJoystickHIDReportBuffer,
				.PrevReportINBufferSize       = sizeof(PrevJoystickHIDReportBuffer),
			},
	};


/* LUFA USB connect event handler */
void EVENT_USB_Device_Connect(void)
{
	usb_connected=1; 
}

/* LUFA USB disconnect event handler */
void EVENT_USB_Device_Disconnect(void)
{
	usb_connected=0;	
}

/* LUFA USB config change event handler */
void EVENT_USB_Device_ConfigurationChanged(void)
{
	bool ConfigSuccess = true;
	ConfigSuccess &= HID_Device_ConfigureEndpoints(&Joystick_HID_Interface);
	USB_Device_EnableSOFEvents();
}

/* LUFA Control Request event handler */
void EVENT_USB_Device_ControlRequest(void)
{
	HID_Device_ProcessControlRequest(&Joystick_HID_Interface);
}

/* LUFA Start of Frame event handler */
void EVENT_USB_Device_StartOfFrame(void)
{
	HID_Device_MillisecondElapsed(&Joystick_HID_Interface);
}

/* LUFA (local impl) callback for creating events to send to host 
   Use current gear position to set the Button bit ask in the joystick report
*/
bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
	uint8_t* const ReportID,
	const uint8_t ReportType,
	void* ReportData,
	uint16_t* const ReportSize)
{
	USB_JoystickReport_Data_t* JoystickReport = (USB_JoystickReport_Data_t*)ReportData;
	JoystickReport->Button=(1<<current_gear);
	*ReportSize = sizeof(USB_JoystickReport_Data_t);
	return false; // false 
}

/** LUFA HID class driver callback function for rx data from host to device.
 * We don't use this, as we only send things to the host.
 * It's required to compile.
 */
void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
	const uint8_t ReportID,
	const uint8_t ReportType,
	const void* ReportData,
	const uint16_t ReportSize)
{
	
}


/*
	Initialise the ADC

	ADC input pins 
	PORTF - pin 4 (x-axis)
	PORTF - pin 6 (y-axis)

*/
void adc_init(void)
{
	DDRF=0x00;			// configure adc as input
	PORTF=0x00;			// ensure pullups are disabled
	ADCSRA|=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS1|1<<ADPS0);	// 0x80;	// set 7th bit to 1 to enable ADC
	DIDR0|=(1<<ADC4D)|(1<<ADC6D);		// disable digitial input buffer
	ADMUX|= (1<<REFS0); // Internal reference
}

/*
	Read value from adc channel;
	only Port Fn is supported.
*/ 
uint16_t adc_read(uint8_t channel)
{
	uint16_t	adc_result;
	uint8_t read_attempts;

	read_attempts=2;				// read twice (re: datasheet reference)
	while((read_attempts--)>0)
	{
		ADMUX=(1<<REFS0)|(channel&0x0f);	
		ADCSRA|=(1<<ADSC)|(1<<ADPS1)|(1<<ADPS1|1<<ADPS0);	// start conversion 
		while ((ADCSRA & (1<<ADSC))); 							// wait for conversion 
		_delay_us(10);													// settttle	
	}
	adc_result=ADC;												// read result 
	return adc_result;											// return to caller
}

/*
	Configure PORTD as input
	This is for the reverse signal.
*/
void gpio_init(void)
{
	DDRD=0x00;	// configure port d as input
}


/*
	Get current state of reverse switch;
	return 1 (active) 0 (not active) 
*/
uint8_t get_reverse_state(void)
{
	if (PIND&(1<<PIND4))
		_delay_us(10);				// poor mans debouning. I cant find my schmits.
	return (PIND&(1<<PIND4)) >> 4;  //debounce?
}

/*
	Use threshold values to calculate the current gear selection
	Input: 
		x_axis -> ADC value
		y_axis -> ADC value
	Returns: Current gear. (0-7) 
*/
uint8_t calulate_gear_position(uint16_t x_axis, uint16_t y_axis)
{
	uint8_t gear;
	gear=current_gear;

	if (x_axis<THRESHOLD_LEFT) 				// stick is over to left
	{
		if (y_axis>THRESHOLD_TOP) 				// at top, so first gear
			gear=GEAR_01;
		else if (y_axis < THRESHOLD_BOTTOM) // at bottom so 2nd gear
			gear=GEAR_02;
		// else
		// 	gear=GEAR_NEUTRAL;			// in between, no gear, neutral
	}
	else if (x_axis>THRESHOLD_RIGHT) 		// stick is over to the right
	{
		if (y_axis>THRESHOLD_TOP)				// at the top, so 5th
			gear=GEAR_05;
		else if (y_axis<THRESHOLD_BOTTOM)	// at bottom, so, sixth
			gear=GEAR_06+reverse_gear;			// are we in reverse?
		// else
		// 	gear=GEAR_NEUTRAL;				// out of gear, so neutral
	}
	// else if (y_axis < THRESHOLD_TOP && y_axis > THRESHOLD_BOTTOM) // centered, no gear, neutral
	// 	gear=GEAR_NEUTRAL;
	else
	{
		if (y_axis>THRESHOLD_TOP)				// stick in middle, and top, so 3rd 
			gear=GEAR_03;
		else if (y_axis<THRESHOLD_BOTTOM) 	// stick in middle and bottom, so 4th
			gear=GEAR_04;	
	}
	return gear;
}

/*
Initialise ATMEGA32u4 USB Peripheral.

From atmega32u4 datasheet 57, 58.
- Disable interrupts
- Disable watchdog  ( re-enable this before the main loop)
- Update pre-scaler
- Enable Interrupts
- Init LUFA USB 
*/
void init_usb(void)
{
	cli();
	wdt_reset();
	wdt_disable();
	clock_prescale_set(clock_div_1);
	sei();
	USB_Init();
}

/*
	Draw debug screen's header
*/
void display_dbg_header(void) 
{
	SSD1306_SetPosition (0, 0);
	SSD1306_ClearScreen ();
	SSD1306_DrawLine (0, MAX_X, 0, 0);
	SSD1306_SetPosition (1, 1);
	SSD1306_DrawString ("Danny's GS Converter");
}

/*
	Display debug/nerd information about current state of converter.
	i.e.: 
	Current USB state: connected/not connected.
	x/y axis ADC measurements in hex
	Current gear position
*/
void display_dbg_data(void)
{
	display_dbg_header();		// display header 

	// Display usb connection data.
	SSD1306_SetPosition (1, 3);
	if (!usb_connected)
		SSD1306_DrawString ("USB DISCONNECTED");
	else
		SSD1306_DrawString ("USB CONNECTED     ");


	// Display y_axis ADC value
	memset(test_adc_value_y,0,ADC_MAX_LEN);
	sprintf(test_adc_value_y,"0x%.4x",yaxis_value);
	SSD1306_SetPosition (50, 5);
	SSD1306_DrawString (test_adc_value_y);

	// Display x-axist ADC value
	memset(test_adc_value_x,0,ADC_MAX_LEN);
	sprintf(test_adc_value_x,"0x%.4x",xaxis_value);
	SSD1306_SetPosition (2, 5);
	SSD1306_DrawString (test_adc_value_x);

	// Display current gear position
	memset(gear_string,0,GS_MAX_LEN);
 	sprintf(gear_string,"%d",current_gear);
	SSD1306_SetPosition(2, 7);
	SSD1306_DrawString("gear");
	SSD1306_SetPosition(40,7);
	SSD1306_DrawString(gear_string);
	SSD1306_UpdateScreen(ssd1306_addr);
}

/*
	Display current gear using ASCII art. (full description in the readme.)
*/

void display_ascii_font(void)
{ 
	uint8_t character;
	uint8_t i, j, char_byte, xoffset, yoffset;

	xoffset=41;  // midpoint=64; go back 15 pixels; so, ~49  -> can we calc? #define
	yoffset=1;   // todo #define

	character=current_gear+16+0x20;  // convert to ascii  TODO: Fix me with #define
	
	// Patch 0th and 7th gears for N and R respectively; fall through on others
	if (current_gear==0) character='N';
	else if (current_gear==7) character='R';	

	SSD1306_SetPosition (0, 0);
	SSD1306_ClearScreen ();
	i=0;

	while (i < CHARS_COLS_LENGTH) 
	{
		char_byte=pgm_read_byte(&FONTS[character-32][i++]);
		for (j=0;j<8;j++)
		{
			if (( char_byte & 1<<j ) == 1<<j)
			{
			// pixels, line number (0-7)
				SSD1306_SetPosition((i<<3)+xoffset,j+yoffset);  // mul 5 will have them touching and it looks weird. 
				SSD1306_DrawChar(character);
  			}
		}
	}
	SSD1306_UpdateScreen(ssd1306_addr);
}

// Entry point
int main(void)
{
	usb_connected=0;
	void (*update_display_fn)(void);		// fn pointer for display functions
	ssd1306_addr = SSD1306_ADDR;			// set i2c address of oled display
	SSD1306_Init (ssd1306_addr);			// init OLED display
	adc_init();									// init adc for reading gear position

	// do some initial reads so we can setup the display mode
	reverse_gear=get_reverse_state(); 				// reset if not in reverse anymore.
	yaxis_value=adc_read(YAXIS_ADC_CHANNEL);  	// read y axis
	xaxis_value=adc_read(XAXIS_ADC_CHANNEL);		// and again
	current_gear=calulate_gear_position(xaxis_value,yaxis_value);
	//display_dbg_data();

	// if in 4th, enable debug screen
	if ( current_gear == 4 )
	{
		update_display_fn=display_dbg_data;
	}
	else
	{
		update_display_fn=display_ascii_font;
	}


	init_usb();						// Init LUFA USB stuff
	GlobalInterruptEnable();	// Required for LUFA USB stuff
	wdt_reset();					// Clear watchdog timer (reset if something goes awry)
	wdt_enable(WDTO_500MS);		// should be _plenty_ (loop is fast)

	for (;;)
	{	
		wdt_reset();
		reverse_gear=get_reverse_state(); 			// Check reverse switch state
		yaxis_value=adc_read(YAXIS_ADC_CHANNEL);  // read y axis
		xaxis_value=adc_read(XAXIS_ADC_CHANNEL);	// read x axis position
		current_gear=calulate_gear_position(xaxis_value,yaxis_value);  // calc gear position
		update_display_fn(); 		// update display
		HID_Device_USBTask(&Joystick_HID_Interface);	// Check USB internals for new report
		USB_USBTask();					// send usb report if we have a new one
	}
  
  return 0; // Unreachable! :-) 
}