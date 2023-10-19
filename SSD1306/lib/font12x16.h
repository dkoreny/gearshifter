
#ifndef __FONT12x16_H__
#define __FONT12x16_H__

/*

*/

/*
{0x00,0x00,0x3F,0x0C,0x7F,0x1C,0x63,0x38,0x63,0x30,
0x63,0x30,
0x63,0x30,
0x63,0x30,
0x63,0x30,
0xE3,0x38,

0xC3,0x1F,
0x83,0x0F},  // 0x35

// 24 elements
// 
// font is 12x16  ?!
// 

00000000 00000000
00111111 00001100
01111111 00011100
01010011 00111000
01010011 00110000
01010011 00110000
01010011 00110000
01010011 00110000
01010011 00110000
11100011 00111000
11000011 00011111
10000011 00001111


  SSSSSS    SS  
 SSSSSSS    SS  
 S S  SS  SSS   
 S S  SS  SS   
 S S  SS  SS     
 S S  SS  SS    
 S S  SS  SS    
SSS   SS  SSS   
SS    SS   SSSSS
S     SS    SSSS      
 

 {0x00,0x00,0x3F,0x0C,0x7F,0x1C,0x63,0x38, 0x63,0x30, 0x63,0x30, 0x63,0x30, 0x63,0x30, 

 0x63,0x30,

 0xE3,0x38,0xC3,0x1F,0x83,0x0F}, // 0x35

{0x00,0x00,0x0c,0x0F,0x1C,0x7F,0x38,0x63,0x30,0x63,0x30,0x63,0x30,0x63,0x30,0x63,0x30,0x63,0x38,0xe3,0x1F,0xc3,0x0f,0x83}, //0x35 reversed

*/
 

  // includes
  #include <avr/pgmspace.h>

  // Characters definition
  // -----------------------------------
  // number of columns for chars
  #define CHARS_COLS_LENGTH  24

static const uint8_t FONTS[][CHARS_COLS_LENGTH] PROGMEM ={
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x20
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0xFF,0x33,0xFF,0x33,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x21
{0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x22
{0x00,0x00,0x00,0x02,0x10,0x1E,0x90,0x1F,0xF0,0x03,0x7E,0x02,0x1E,0x1E,0x90,0x1F,0xF0,0x03,0x7E,0x02,0x1E,0x00,0x10,0x00},	// 0x23
{0x00,0x00,0x00,0x00,0x78,0x04,0xFC,0x0C,0xCC,0x0C,0xFF,0x3F,0xFF,0x3F,0xCC,0x0C,0xCC,0x0F,0x88,0x07,0x00,0x00,0x00,0x00},	// 0x24
{0x00,0x00,0x00,0x30,0x38,0x38,0x38,0x1C,0x38,0x0E,0x00,0x07,0x80,0x03,0xC0,0x01,0xE0,0x38,0x70,0x38,0x38,0x38,0x1C,0x00},	// 0x25
{0x00,0x00,0x00,0x00,0x00,0x1F,0xB8,0x3F,0xFC,0x31,0xC6,0x21,0xE2,0x37,0x3E,0x1E,0x1C,0x1C,0x00,0x36,0x00,0x22,0x00,0x00},	// 0x26
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x27,0x00,0x3F,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x27
{0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x03,0xFC,0x0F,0xFE,0x1F,0x07,0x38,0x01,0x20,0x01,0x20,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x28
{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x20,0x01,0x20,0x07,0x38,0xFE,0x1F,0xFC,0x0F,0xF0,0x03,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x29
{0x00,0x00,0x00,0x00,0x98,0x0C,0xB8,0x0E,0xE0,0x03,0xF8,0x0F,0xF8,0x0F,0xE0,0x03,0xB8,0x0E,0x98,0x0C,0x00,0x00,0x00,0x00},	// 0x2A
{0x00,0x00,0x00,0x00,0x80,0x01,0x80,0x01,0x80,0x01,0xF0,0x0F,0xF0,0x0F,0x80,0x01,0x80,0x01,0x80,0x01,0x00,0x00,0x00,0x00},	// 0x2B
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB8,0x00,0xF8,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x2C
{0x00,0x00,0x00,0x00,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x00,0x00,0x00,0x00},	// 0x2D
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x2E
{0x00,0x00,0x00,0x18,0x00,0x1C,0x00,0x0E,0x00,0x07,0x80,0x03,0xC0,0x01,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00},	// 0x2F
{0x00,0x00,0xF8,0x07,0xFE,0x1F,0x06,0x1E,0x03,0x33,0x83,0x31,0xC3,0x30,0x63,0x30,0x33,0x30,0x1E,0x18,0xFE,0x1F,0xF8,0x07},	// 0x30
{0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x30,0x0C,0x30,0x0E,0x30,0xFF,0x3F,0xFF,0x3F,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x00},	// 0x31
{0x00,0x00,0x1C,0x30,0x1E,0x38,0x07,0x3C,0x03,0x3E,0x03,0x37,0x83,0x33,0xC3,0x31,0xE3,0x30,0x77,0x30,0x3E,0x30,0x1C,0x30},	// 0x32
{0x00,0x00,0x0C,0x0C,0x0E,0x1C,0x07,0x38,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xE7,0x39,0x7E,0x1F,0x3C,0x0E},	// 0x33
{0x00,0x00,0xC0,0x03,0xE0,0x03,0x70,0x03,0x38,0x03,0x1C,0x03,0x0E,0x03,0x07,0x03,0xFF,0x3F,0xFF,0x3F,0x00,0x03,0x00,0x03},	// 0x34
{0x00,0x00,0x0c,0x0F,0x1C,0x7F,0x38,0x63,0x30,0x63,0x30,0x63,0x30,0x63,0x30,0x63,0x30,0x63,0x38,0xe3,0x1F,0xc3,0x0f,0x83}, //0x35 reversed{0x00,0x00,0xC0,0x0F,0xF0,0x1F,0xF8,0x39,0xDC,0x30,0xCE,0x30,0xC7,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x39,0x80,0x1F,0x00,0x0F},	// 0x36
{0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x30,0x03,0x3C,0x03,0x0F,0xC3,0x03,0xF3,0x00,0x3F,0x00,0x0F,0x00,0x03,0x00},	// 0x37
{0x00,0x00,0x00,0x0F,0xBC,0x1F,0xFE,0x39,0xE7,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xE7,0x30,0xFE,0x39,0xBC,0x1F,0x00,0x0F},	// 0x38
{0x00,0x00,0x3C,0x00,0x7E,0x00,0xE7,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x38,0xC3,0x1C,0xC3,0x0E,0xE7,0x07,0xFE,0x03,0xFC,0x00},	// 0x39
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x1C,0x70,0x1C,0x70,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x3A
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x9C,0x70,0xFC,0x70,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x3B
{0x00,0x00,0x00,0x00,0xC0,0x00,0xE0,0x01,0xF0,0x03,0x38,0x07,0x1C,0x0E,0x0E,0x1C,0x07,0x38,0x03,0x30,0x00,0x00,0x00,0x00},	// 0x3C
{0x00,0x00,0x00,0x00,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x00,0x00},	// 0x3D
{0x00,0x00,0x00,0x00,0x03,0x30,0x07,0x38,0x0E,0x1C,0x1C,0x0E,0x38,0x07,0xF0,0x03,0xE0,0x01,0xC0,0x00,0x00,0x00,0x00,0x00},	// 0x3E
{0x00,0x00,0x1C,0x00,0x1E,0x00,0x07,0x00,0x03,0x00,0x83,0x37,0xC3,0x37,0xE3,0x00,0x77,0x00,0x3E,0x00,0x1C,0x00,0x00,0x00},	// 0x3F
{0x00,0x00,0xF8,0x0F,0xFE,0x1F,0x07,0x18,0xF3,0x33,0xFB,0x37,0x1B,0x36,0xFB,0x37,0xFB,0x37,0x07,0x36,0xFE,0x03,0xF8,0x01},	// 0x40
{0x00,0x00,0x00,0x38,0x00,0x3F,0xE0,0x07,0xFC,0x06,0x1F,0x06,0x1F,0x06,0xFC,0x06,0xE0,0x07,0x00,0x3F,0x00,0x38,0x00,0x00},	// 0x41
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xE7,0x30,0xFE,0x39,0xBC,0x1F,0x00,0x0F,0x00,0x00},	// 0x42
{0x00,0x00,0xF0,0x03,0xFC,0x0F,0x0E,0x1C,0x07,0x38,0x03,0x30,0x03,0x30,0x03,0x30,0x07,0x38,0x0E,0x1C,0x0C,0x0C,0x00,0x00},	// 0x43
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x03,0x30,0x03,0x30,0x03,0x30,0x03,0x30,0x07,0x38,0x0E,0x1C,0xFC,0x0F,0xF0,0x03,0x00,0x00},	// 0x44
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0x03,0x30,0x03,0x30,0x00,0x00},	// 0x45
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0xC3,0x00,0xC3,0x00,0xC3,0x00,0xC3,0x00,0xC3,0x00,0xC3,0x00,0x03,0x00,0x03,0x00,0x00,0x00},	// 0x46
{0x00,0x00,0xF0,0x03,0xFC,0x0F,0x0E,0x1C,0x07,0x38,0x03,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC7,0x3F,0xC6,0x3F,0x00,0x00},	// 0x47
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xFF,0x3F,0xFF,0x3F,0x00,0x00},	// 0x48
{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x30,0x03,0x30,0xFF,0x3F,0xFF,0x3F,0x03,0x30,0x03,0x30,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x49
{0x00,0x00,0x00,0x0E,0x00,0x1E,0x00,0x38,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x38,0xFF,0x1F,0xFF,0x07,0x00,0x00},	// 0x4A
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0xC0,0x00,0xE0,0x01,0xF0,0x03,0x38,0x07,0x1C,0x0E,0x0E,0x1C,0x07,0x38,0x03,0x30,0x00,0x00},	// 0x4B
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x00},	// 0x4C
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x1E,0x00,0x78,0x00,0xE0,0x01,0xE0,0x01,0x78,0x00,0x1E,0x00,0xFF,0x3F,0xFF,0x3F,0x00,0x00},	// 0x4D
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x0E,0x00,0x38,0x00,0xF0,0x00,0xC0,0x03,0x00,0x07,0x00,0x1C,0xFF,0x3F,0xFF,0x3F,0x00,0x00},	// 0x4E
{0x00,0x00,0xF0,0x03,0xFC,0x0F,0x0E,0x1C,0x07,0x38,0x03,0x30,0x03,0x30,0x07,0x38,0x0E,0x1C,0xFC,0x0F,0xF0,0x03,0x00,0x00},	// 0x4F
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x83,0x01,0x83,0x01,0x83,0x01,0x83,0x01,0x83,0x01,0xC7,0x01,0xFE,0x00,0x7C,0x00,0x00,0x00},	// 0x50
{0x00,0x00,0xF0,0x03,0xFC,0x0F,0x0E,0x1C,0x07,0x38,0x03,0x30,0x03,0x36,0x07,0x3E,0x0E,0x1C,0xFC,0x3F,0xF0,0x33,0x00,0x00},	// 0x51
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x83,0x01,0x83,0x01,0x83,0x03,0x83,0x07,0x83,0x0F,0xC7,0x1D,0xFE,0x38,0x7C,0x30,0x00,0x00},	// 0x52
{0x00,0x00,0x3C,0x0C,0x7E,0x1C,0xE7,0x38,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC7,0x39,0x8E,0x1F,0x0C,0x0F,0x00,0x00},	// 0x53
{0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0xFF,0x3F,0xFF,0x3F,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},	// 0x54
{0x00,0x00,0xFF,0x07,0xFF,0x1F,0x00,0x38,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x38,0xFF,0x1F,0xFF,0x07,0x00,0x00},	// 0x55
{0x00,0x00,0x07,0x00,0x3F,0x00,0xF8,0x01,0xC0,0x0F,0x00,0x3E,0x00,0x3E,0xC0,0x0F,0xF8,0x01,0x3F,0x00,0x07,0x00,0x00,0x00},	// 0x56
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x00,0x1C,0x00,0x06,0x80,0x03,0x80,0x03,0x00,0x06,0x00,0x1C,0xFF,0x3F,0xFF,0x3F,0x00,0x00},	// 0x57
{0x00,0x00,0x03,0x30,0x0F,0x3C,0x1C,0x0E,0x30,0x03,0xE0,0x01,0xE0,0x01,0x30,0x03,0x1C,0x0E,0x0F,0x3C,0x03,0x30,0x00,0x00},	// 0x58
{0x00,0x00,0x03,0x00,0x0F,0x00,0x3C,0x00,0xF0,0x00,0xC0,0x3F,0xC0,0x3F,0xF0,0x00,0x3C,0x00,0x0F,0x00,0x03,0x00,0x00,0x00},	// 0x59
{0x00,0x00,0x03,0x30,0x03,0x3C,0x03,0x3E,0x03,0x33,0xC3,0x31,0xE3,0x30,0x33,0x30,0x1F,0x30,0x0F,0x30,0x03,0x30,0x00,0x00},	// 0x5A
{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x03,0x30,0x03,0x30,0x03,0x30,0x03,0x30,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x5B
{0x00,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x00,0xC0,0x01,0x80,0x03,0x00,0x07,0x00,0x0E,0x00,0x1C,0x00,0x18},	// 0x5C
{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x30,0x03,0x30,0x03,0x30,0x03,0x30,0xFF,0x3F,0xFF,0x3F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x5D
{0x00,0x00,0x60,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00,0x60,0x00},	// 0x5E
{0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0},	// 0x5F
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x7E,0x00,0x4E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x60
{0x00,0x00,0x00,0x1C,0x40,0x3E,0x60,0x33,0x60,0x33,0x60,0x33,0x60,0x33,0x60,0x33,0x60,0x33,0xE0,0x3F,0xC0,0x3F,0x00,0x00},	// 0x61
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0xC0,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0xE0,0x38,0xC0,0x1F,0x80,0x0F,0x00,0x00},	// 0x62
{0x00,0x00,0x80,0x0F,0xC0,0x1F,0xE0,0x38,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0xC0,0x18,0x80,0x08,0x00,0x00},	// 0x63
{0x00,0x00,0x80,0x0F,0xC0,0x1F,0xE0,0x38,0x60,0x30,0x60,0x30,0x60,0x30,0xE0,0x30,0xC0,0x30,0xFF,0x3F,0xFF,0x3F,0x00,0x00},	// 0x64
{0x00,0x00,0x80,0x0F,0xC0,0x1F,0xE0,0x3B,0x60,0x33,0x60,0x33,0x60,0x33,0x60,0x33,0x60,0x33,0xC0,0x13,0x80,0x01,0x00,0x00},	// 0x65
{0x00,0x00,0xC0,0x00,0xC0,0x00,0xFC,0x3F,0xFE,0x3F,0xC7,0x00,0xC3,0x00,0xC3,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x66
{0x00,0x00,0x80,0x03,0xC0,0xC7,0xE0,0xCE,0x60,0xCC,0x60,0xCC,0x60,0xCC,0x60,0xCC,0x60,0xE6,0xE0,0x7F,0xE0,0x3F,0x00,0x00},	// 0x67
{0x00,0x00,0xFF,0x3F,0xFF,0x3F,0xC0,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0xE0,0x00,0xC0,0x3F,0x80,0x3F,0x00,0x00,0x00,0x00},	// 0x68
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x60,0x30,0xEC,0x3F,0xEC,0x3F,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x69
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xE0,0x00,0xC0,0x60,0xC0,0xEC,0xFF,0xEC,0x7F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x6A
{0x00,0x00,0x00,0x00,0xFF,0x3F,0xFF,0x3F,0x00,0x03,0x80,0x07,0xC0,0x0F,0xE0,0x1C,0x60,0x38,0x00,0x30,0x00,0x00,0x00,0x00},	// 0x6B
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x03,0x30,0xFF,0x3F,0xFF,0x3F,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x6C
{0x00,0x00,0xE0,0x3F,0xC0,0x3F,0xE0,0x00,0xE0,0x00,0xC0,0x3F,0xC0,0x3F,0xE0,0x00,0xE0,0x00,0xC0,0x3F,0x80,0x3F,0x00,0x00},	// 0x6D
{0x00,0x00,0x00,0x00,0xE0,0x3F,0xE0,0x3F,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0xE0,0x00,0xC0,0x3F,0x80,0x3F,0x00,0x00},	// 0x6E
{0x00,0x00,0x80,0x0F,0xC0,0x1F,0xE0,0x38,0x60,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0xE0,0x38,0xC0,0x1F,0x80,0x0F,0x00,0x00},	// 0x6F
{0x00,0x00,0xE0,0xFF,0xE0,0xFF,0x60,0x0C,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0xE0,0x1C,0xC0,0x0F,0x80,0x07,0x00,0x00},	// 0x70
{0x00,0x00,0x80,0x07,0xC0,0x0F,0xE0,0x1C,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x60,0x0C,0xE0,0xFF,0xE0,0xFF,0x00,0x00},	// 0x71
{0x00,0x00,0x00,0x00,0xE0,0x3F,0xE0,0x3F,0xC0,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0xE0,0x00,0xC0,0x00,0x00,0x00},	// 0x72
{0x00,0x00,0xC0,0x11,0xE0,0x33,0x60,0x33,0x60,0x33,0x60,0x33,0x60,0x33,0x60,0x3F,0x40,0x1E,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x73
{0x00,0x00,0x60,0x00,0x60,0x00,0xFE,0x1F,0xFE,0x3F,0x60,0x30,0x60,0x30,0x60,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x74
{0x00,0x00,0xE0,0x0F,0xE0,0x1F,0x00,0x38,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x18,0xE0,0x3F,0xE0,0x3F,0x00,0x00},	// 0x75
{0x00,0x00,0x60,0x00,0xE0,0x01,0x80,0x07,0x00,0x1E,0x00,0x38,0x00,0x38,0x00,0x1E,0x80,0x07,0xE0,0x01,0x60,0x00,0x00,0x00},	// 0x76
{0x00,0x00,0xE0,0x07,0xE0,0x1F,0x00,0x38,0x00,0x1C,0xE0,0x0F,0xE0,0x0F,0x00,0x1C,0x00,0x38,0xE0,0x1F,0xE0,0x07,0x00,0x00},	// 0x77
{0x00,0x00,0x60,0x30,0xE0,0x38,0xC0,0x1D,0x80,0x0F,0x00,0x07,0x80,0x0F,0xC0,0x1D,0xE0,0x38,0x60,0x30,0x00,0x00,0x00,0x00},	// 0x78
{0x00,0x00,0x00,0x00,0x60,0x00,0xE0,0x81,0x80,0xE7,0x00,0x7E,0x00,0x1E,0x80,0x07,0xE0,0x01,0x60,0x00,0x00,0x00,0x00,0x00},	// 0x79
{0x00,0x00,0x60,0x30,0x60,0x38,0x60,0x3C,0x60,0x36,0x60,0x33,0xE0,0x31,0xE0,0x30,0x60,0x30,0x20,0x30,0x00,0x00,0x00,0x00},	// 0x7A
{0x00,0x00,0x00,0x00,0x80,0x00,0xC0,0x01,0xFC,0x1F,0x7E,0x3F,0x07,0x70,0x03,0x60,0x03,0x60,0x03,0x60,0x00,0x00,0x00,0x00},	// 0x7B
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xBF,0x3F,0xBF,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x7C
{0x00,0x00,0x00,0x00,0x03,0x60,0x03,0x60,0x03,0x60,0x07,0x70,0x7E,0x3F,0xFC,0x1F,0xC0,0x01,0x80,0x00,0x00,0x00,0x00,0x00},	// 0x7D
{0x00,0x00,0x10,0x00,0x18,0x00,0x0C,0x00,0x04,0x00,0x0C,0x00,0x18,0x00,0x10,0x00,0x18,0x00,0x0C,0x00,0x04,0x00,0x00,0x00},	// 0x7E
{0x00,0x00,0x00,0x0F,0x80,0x0F,0xC0,0x0C,0x60,0x0C,0x30,0x0C,0x30,0x0C,0x60,0x0C,0xC0,0x0C,0x80,0x0F,0x00,0x0F,0x00,0x00},	// 0x7F
};

#endif