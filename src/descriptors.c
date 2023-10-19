
#ifndef _DESCRIPTORS_H
#define _DESCRIPTORS_H

/*

[2897756.995640] input: LUFA Library Danny's G29 GearShifter as 
	/devices/pci0000:00/0000:00:14.0/usb2/2-6/2-6:1.0/0003:03EB:2043.00BB/input/input185
[2897756.995827] hid-generic 0003:03EB:2043.00BB: input,hidraw5: 
	USB HID v1.11 Joystick [LUFA Library Danny's G29 GearShifter] on usb-0000:00:14.0-6/input0

[2897774.394133] input: LUFA Library Danny's G29 GearShifter as 
	/devices/pci0000:00/0000:00:14.0/usb2/2-6/2-6:1.0/0003:03EB:2043.00BC/input/input186
[2897774.394255] hid-generic 0003:03EB:2043.00BC: input,hidraw5: 
	USB HID v1.11 Joystick [LUFA Library Danny's G29 GearShifter] on usb-0000:00:14.0-6/input0


*/

#include "descriptors.h"

/*
	- dont require x/y/z axis
	- We are converting "gear" positions into button pushes

	These are read from the ADC's;
	1st gear
	2nd gear
	3rd gear
	4th gear
	5th gear
	6th gear

	Reverse:
	This is an external button; when it's active _and_ the device is in 6th gear,
  this is considered "reverse" beep beep beep beep.....
*/

const USB_Descriptor_HIDReport_Datatype_t PROGMEM JoystickReport[] =
{
	HID_DESCRIPTOR_JOYSTICK(-32, 32, -16, 32, 8)
};


// This can stay as is (from the Joystick example)
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor =
{
	.Header									= {.Size = sizeof(USB_Descriptor_Device_t), \
															.Type = DTYPE_Device},
	.USBSpecification				= VERSION_BCD(1,1,0),
	.Class									= USB_CSCP_NoDeviceClass,
	.SubClass								= USB_CSCP_NoDeviceSubclass,
	.Protocol								= USB_CSCP_NoDeviceProtocol,
	.Endpoint0Size					= FIXED_CONTROL_ENDPOINT_SIZE,
	.VendorID								= 0x03EB,
	.ProductID							= 0x2043,
	.ReleaseNumber					= VERSION_BCD(0,0,1),
	.ManufacturerStrIndex		= STRING_ID_Manufacturer,
	.ProductStrIndex				= STRING_ID_Product,
	.SerialNumStrIndex			= NO_DESCRIPTOR,
	.NumberOfConfigurations	= FIXED_NUM_CONFIGURATIONS
};

// From the Joystick example, this can stay as is.

const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor =
{
	.Config =
	{
		.Header 								= 
			{.Size = sizeof(USB_Descriptor_Configuration_Header_t), \
			.Type = DTYPE_Configuration},

		.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
		.TotalInterfaces        = 1,
		.ConfigurationNumber    = 1,
		.ConfigurationStrIndex  = NO_DESCRIPTOR,
		.ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED | USB_CONFIG_ATTR_SELFPOWERED),
		.MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
	},

	.HID_Interface =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), 
			.Type = DTYPE_Interface},
		.InterfaceNumber        = INTERFACE_ID_Joystick,
		.AlternateSetting       = 0x00,
		.TotalEndpoints         = 1,
		.Class                  = HID_CSCP_HIDClass,
		.SubClass               = HID_CSCP_NonBootSubclass,
		.Protocol               = HID_CSCP_NonBootProtocol,
		.InterfaceStrIndex      = NO_DESCRIPTOR
	},

	.HID_JoystickHID =
	{
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), 
			.Type = HID_DTYPE_HID},
		.HIDSpec                = VERSION_BCD(1,1,1),
		.CountryCode            = 0x00,
		.TotalReportDescriptors = 1,
		.HIDReportType          = HID_DTYPE_Report,
		.HIDReportLength        = sizeof(JoystickReport)
	},

	.HID_ReportINEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), 
			.Type = DTYPE_Endpoint},
		.EndpointAddress        = JOYSTICK_EPADDR,
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = JOYSTICK_EPSIZE,
		.PollingIntervalMS      = 0x05
		}
};

const USB_Descriptor_String_t PROGMEM \
	LanguageString = USB_STRING_DESCRIPTOR_ARRAY(LANGUAGE_ID_ENG);

const USB_Descriptor_String_t PROGMEM \
	ManufacturerString = USB_STRING_DESCRIPTOR(L"LUFA Library");

const USB_Descriptor_String_t PROGMEM \
	ProductString = USB_STRING_DESCRIPTOR(L"Danny's G29 GearShifter");

uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
	const uint16_t wIndex,
	const void** const DescriptorAddress)
{
	const uint8_t  DescriptorType   = (wValue >> 8);
	const uint8_t  DescriptorNumber = (wValue & 0xFF);
	const void* Address = NULL;
	uint16_t    Size    = NO_DESCRIPTOR;

	switch (DescriptorType)
	{
		case DTYPE_Device:
			Address = &DeviceDescriptor;
			Size    = sizeof(USB_Descriptor_Device_t);
			break;
		case DTYPE_Configuration:
			Address = &ConfigurationDescriptor;
			Size    = sizeof(USB_Descriptor_Configuration_t);
			break;
		case DTYPE_String:
			switch (DescriptorNumber)
			{
				case STRING_ID_Language:
					Address = &LanguageString;
					Size    = pgm_read_byte(&LanguageString.Header.Size);
					break;
				case STRING_ID_Manufacturer:
					Address = &ManufacturerString;
					Size    = pgm_read_byte(&ManufacturerString.Header.Size);
					break;
				case STRING_ID_Product:
					Address = &ProductString;
					Size    = pgm_read_byte(&ProductString.Header.Size);
					break;
			} 
			break;
		case HID_DTYPE_HID:
			Address = &ConfigurationDescriptor.HID_JoystickHID;
			Size    = sizeof(USB_HID_Descriptor_HID_t);
			break;
		case HID_DTYPE_Report:
			Address = &JoystickReport;
			Size    = sizeof(JoystickReport);
			break;
	}

	*DescriptorAddress = Address;
	return Size;
}

#endif