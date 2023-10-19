/* LUFA LIBRARY configuration file 
	Based on example in LUFA_HOME/Demos/Device/ClassDriver/Joystick
*/

#ifndef _LUFA_CONFIG_H_
#define _LUFA_CONFIG_H_

	#if (ARCH == ARCH_AVR8)
		/* General USB Driver Related Tokens: */
		#define USE_STATIC_OPTIONS               (USB_DEVICE_OPT_FULLSPEED | USB_OPT_REG_ENABLED | USB_OPT_AUTO_PLL)
		#define USB_DEVICE_ONLY

		/* USB Device Mode Driver Related Tokens: */
		#define USE_FLASH_DESCRIPTORS
		#define FIXED_CONTROL_ENDPOINT_SIZE      8
		#define FIXED_NUM_CONFIGURATIONS         1

	#elif (ARCH == ARCH_XMEGA)

	/* General USB Driver Related Tokens: */
		#define USE_STATIC_OPTIONS               (USB_DEVICE_OPT_FULLSPEED | USB_OPT_RC32MCLKSRC | USB_OPT_BUSEVENT_PRIHIGH)
		/* USB Device Mode Driver Related Tokens: */
		#define USE_FLASH_DESCRIPTORS
		#define FIXED_CONTROL_ENDPOINT_SIZE      8
		#define FIXED_NUM_CONFIGURATIONS         1
		#define MAX_ENDPOINT_INDEX               1
	#else
		#error Unsupported architecture for this LUFA configuration file.
	#endif
#endif
