#ifndef _GEARSHIFTER_H_
#define _GEARSHIFTER_H_

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <string.h>
#include <util/delay.h>

#include "descriptors.h"

#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Platform/Platform.h>
#define ADC_MAX_LEN 8
#define GS_MAX_LEN 4
#define YAXIS_ADC_CHANNEL 6
#define XAXIS_ADC_CHANNEL 4

// OLED DISPLAY
#include "lib/ssd1306.h"

// define gear selections; these are used to set bits
// for the Joystick HID device buttons.

#define GEAR_NEUTRAL	0
#define GEAR_01				1
#define GEAR_02				2
#define GEAR_03				3
#define GEAR_04				4
#define GEAR_05				5
#define GEAR_06				6
#define GEAR_REVERSE	7
#define REVERSE_BUTTON (1<<PIND4)

/*	
	Threshold configuration. Calibrated/tweaked in real time.
	These determine where the gear shifter is located x/y coords.
*/

// less than this its in left position so gear 1/2
#define THRESHOLD_LEFT	0x160

// greater than this it's in the right positiuon, so gear 5/6/r
#define THRESHOLD_RIGHT 0x250  

// greater than this it's at the top, so 1,3,5
#define THRESHOLD_TOP  0x2f0

// Less than this it's at bottom, so 2,4,6,r
#define THRESHOLD_BOTTOM 0xc0


/* 

We only have 7 buttons. 1,2,3,4,5,6 and reverse (8) - forgot about nuteral

Although we have a hardware "joystick" connected to the board, it's
an analog one so we'll convert the analog signals (ADC) to button presses

1st Gear ADC -> send button 1 
2nd Gear ADC -> send button 2
3rd Gear ADC -> send button 3
4th Gear ADC -> send button 4
5th Gear ADC -> send button 5
6th Gear ADC -> send button 6
R in 6th only -> send button 7

*/

// Need to keep state?! or will this do it for us?

// typedef struct _usb_joystick_report_data_t
// {
//       int8_t x;
//       int8_t y;
//       int8_t z;
// 	uint8_t button;		
// } usb_joystick_report_data_t;

void adc_init(void);
uint16_t adc_read(uint8_t channel);


/* Required prototypes for LUFA */

void EVENT_USB_Device_Connect(void);
void EVENT_USB_Device_Disconnect(void);
void EVENT_USB_Device_ConfigurationChanged(void);
void EVENT_USB_Device_ControlRequest(void);
void EVENT_USB_Device_StartOfFrame(void);

bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                         uint8_t* const ReportID,
                                         const uint8_t ReportType,
                                         void* ReportData,
                                         uint16_t* const ReportSize);
void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                          const uint8_t ReportID,
                                          const uint8_t ReportType,
                                          const void* ReportData,
                                          const uint16_t ReportSize);

typedef struct
{
	int8_t  X; /**< Current absolute joystick X position, as a signed 8-bit integer */
	int8_t  Y; /**< Current absolute joystick Y position, as a signed 8-bit integer */
	int8_t  Z; /**< Current absolute joystick Z position, as a signed 8-bit integer */
	uint8_t Button; /**< Bit mask of the currently pressed joystick buttons */
} USB_JoystickReport_Data_t;

/** LED mask for the library LED driver, to indicate that the USB interface is not ready. */
#define LEDMASK_USB_NOTREADY      LEDS_LED1

/** LED mask for the library LED driver, to indicate that the USB interface is enumerating. */
#define LEDMASK_USB_ENUMERATING  (LEDS_LED2 | LEDS_LED3)

/** LED mask for the library LED driver, to indicate that the USB interface is ready. */
#define LEDMASK_USB_READY        (LEDS_LED2 | LEDS_LED4)

/** LED mask for the library LED driver, to indicate that an error has occurred in the USB interface. */
#define LEDMASK_USB_ERROR        (LEDS_LED1 | LEDS_LED3)

/* Function Prototypes: */
void init_usb(void);

void EVENT_USB_Device_Connect(void);
void EVENT_USB_Device_Disconnect(void);
void EVENT_USB_Device_ConfigurationChanged(void);
void EVENT_USB_Device_ControlRequest(void);
void EVENT_USB_Device_StartOfFrame(void);

bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                         uint8_t* const ReportID,
                                         const uint8_t ReportType,
                                         void* ReportData,
                                         uint16_t* const ReportSize);
void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                          const uint8_t ReportID,
                                          const uint8_t ReportType,
                                          const void* ReportData,
                                          const uint16_t ReportSize);

#endif

