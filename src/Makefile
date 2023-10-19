# Based on Makefile from LUFA_HOME/Demos/Device/ClassDriver/Joystick
# Updated to include:
# - Custom code
# - OLED driver
# - atmega32u4 target uC.
# - Board is actually an ADAFRUITU4 breakout.

MCU          = atmega32u4
ARCH         = AVR8
BOARD        = ADAFRUITU4
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = dkmain
SRC          = $(TARGET).c descriptors.c $(LUFA_SRC_USB) $(LUFA_SRC_USBCLASS) ../SSD1306/lib/ssd1306.c ../SSD1306/lib/twi.c
LUFA_PATH    = ../lufa-LUFA-210130/LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -IConfig/ -I../SSD1306/ -I./
LD_FLAGS     =

# -fno-jump-tables 
# Default target
all:

# Include LUFA-specific DMBS extension modules
DMBS_LUFA_PATH ?= $(LUFA_PATH)/Build/LUFA
include $(DMBS_LUFA_PATH)/lufa-sources.mk
include $(DMBS_LUFA_PATH)/lufa-gcc.mk

# Include common DMBS build system modules
DMBS_PATH      ?= $(LUFA_PATH)/Build/DMBS/DMBS
include $(DMBS_PATH)/core.mk
include $(DMBS_PATH)/cppcheck.mk
include $(DMBS_PATH)/doxygen.mk
include $(DMBS_PATH)/dfu.mk
include $(DMBS_PATH)/gcc.mk
include $(DMBS_PATH)/hid.mk
include $(DMBS_PATH)/avrdude.mk
include $(DMBS_PATH)/atprogram.mk
