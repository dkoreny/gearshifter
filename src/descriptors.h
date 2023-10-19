// Based on Joystick example in LUFAHOME/Demos/Device/ClassDriver/Joystick/
// removed most of the comments; handy for the demo, but a bit verbose for me.
// reformated for my taste

#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

#include <avr/pgmspace.h>
#include <LUFA/Drivers/USB/USB.h>

typedef struct
{
	USB_Descriptor_Configuration_Header_t Config;
	USB_Descriptor_Interface_t	HID_Interface;
	USB_HID_Descriptor_HID_t		HID_JoystickHID;
	USB_Descriptor_Endpoint_t		HID_ReportINEndpoint;
} USB_Descriptor_Configuration_t;

enum InterfaceDescriptors_t
{
	INTERFACE_ID_Joystick = 0, /**< Joystick interface desciptor ID */
};

enum StringDescriptors_t
{
	STRING_ID_Language     = 0, /**< Supported Languages string descriptor ID (must be zero) */
	STRING_ID_Manufacturer = 1, /**< Manufacturer string ID */
	STRING_ID_Product      = 2, /**< Product string ID */
};

#define JOYSTICK_EPADDR              (ENDPOINT_DIR_IN | 1)
#define JOYSTICK_EPSIZE              8

uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
			                                  const uint16_t wIndex,
		                                    const void** const DescriptorAddress)
		                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

#endif

