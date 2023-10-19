/** 
 * --------------------------------------------------------------------------------------+
 * @desc        Two Wire Interface / I2C Communication
 * --------------------------------------------------------------------------------------+
 *              Copyright (C) 2020 Marian Hrinko.
 *              Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       06.09.2020
 * @file        twi.c
 * @tested      AVR Atmega16, ATmega8, Atmega328
 *
 * @depend      twi.h
 * --------------------------------------------------------------------------------------+
 * @usage       Master Transmit Operation
 */
 
// include libraries
#include "twi.h"

/**
 * @desc    TWI init - initialize frequency
 *
 * @param   void
 *
 * @return  void
 */
void TWI_Init (void)
{
  // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Calculation fclk:
  //
  // fclk = (fcpu)/(16+2*TWBR*4^Prescaler) m16
  // fclk = (fcpu)/(16+2*TWBR*Prescaler) m328p
  // -------------------------------------------------------------------------------------
  // Calculation TWBR:
  // 
  // TWBR = {(fcpu/fclk) - 16 } / (2*4^Prescaler)
  // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // @param1 value of TWBR (m16) 
  //  fclk = 400kHz; TWBR = 3
  //  fclk = 100kHz; TWBR = 20
  // @param1 value of TWBR (m328p)
  //  fclk = 400kHz; TWBR = 2
  // @param2 value of Prescaler = 1

/*

DKNotes: 

Corruption on oled display; it does not happen often; once over 6 hour soak test.
Since most of the other code looks ok, I started checking here before I blame the
display.  Soldering was good. I did it ;-) It is connected to the breakout board
using dupont connections (I made with knipplex crimper, so they are good).

Re-testing. :-) 

Datasheet: atmel-7766-avr-atmega16u4-32u4_datahsheet.pdf
  page 231:
    "TWBR should be 10 or higher if TWI operates in master mode."
    So, TWBR needs to be at least 10, the only way to get to 400KHz is to disable 
    the prescaler. i.e.: set to 0. 

  atmega32u4:
    400khz = 16000000/((16+2*12) * 4^0) = 400000

sclfreq = cpuclock / (16+2*TWBR) * 4^TWPS (00,01,10,11 [0,1,2,4])

    100Khz = 16000000/((16+2*12)*4^1) = 100000;
    so, TWI_FREQ(12,1) = 100Khz :-) 


*/
#if defined(__AVR_ATmega16__) || \
   defined(__AVR_ATmega8__) || \
   defined(__AVR_ATmega328P__) 
  TWI_FREQ (2, 1);  // TODO: this may be causing corrupted display on atmega32u4 (666khz!)
#elif  defined(__AVR_ATmega32U4__)
  TWI_FREQ (12,0); // atmega32u4 (test 1); this should be 400khz for atmega32u4 running @16MHz
#endif

}

/**
 * @desc    TWI MT Start
 *
 * @param   void
 *
 * @return  char
 */
char TWI_MT_Start (void)
{
  // null status flag
  TWI_TWSR &= ~0xA8;
  // START
  // -------------------------------------------------------------------------------------
  // request for bus
  TWI_START();
  // wait till flag set
  TWI_WAIT_TILL_TWINT_IS_SET();
  // test if start or repeated start acknowledged
  if ((TWI_STATUS != TWI_START_ACK) && (TWI_STATUS != TWI_REP_START_ACK)) {
    // return status
    return TWI_STATUS;
  }
  // success
  return SUCCESS;
}

/**
 * @desc    TWI Send address + write
 *
 * @param   char
 *
 * @return  char
 */
char TWI_MT_Send_SLAW (char address)
{
  // SLA+W
  // -------------------------------------------------------------------------------------
  TWI_TWDR = (address << 1);
  // enable
  TWI_ENABLE();
  // wait till flag set
  TWI_WAIT_TILL_TWINT_IS_SET();

  // test if SLA with WRITE acknowledged
  if (TWI_STATUS != TWI_MT_SLAW_ACK) {
    // return status
    return TWI_STATUS;
  }
  // success
  return SUCCESS;
}

/**
 * @desc    TWI Send data
 *
 * @param   char
 *
 * @return  char
 */
char TWI_MT_Send_Data (char data)
{
  // DATA
  // -------------------------------------------------------------------------------------
  TWI_TWDR = data;
  // enable
  TWI_ENABLE();
  // wait till flag set
  TWI_WAIT_TILL_TWINT_IS_SET();

  // test if data acknowledged
  if (TWI_STATUS != TWI_MT_DATA_ACK) {
    // return status
    return TWI_STATUS;
  }
  // success
  return SUCCESS;
}

/**
 * @desc    TWI Send address + read
 *
 * @param   char
 *
 * @return  char
 */
char TWI_MR_Send_SLAR (char address)
{
  // SLA+R
  // -------------------------------------------------------------------------------------
  TWI_TWDR = (address << 1) | 0x01;
  // enable
  TWI_ENABLE();
  // wait till flag set
  TWI_WAIT_TILL_TWINT_IS_SET();

  // test if SLA with READ acknowledged
  if (TWI_STATUS != TWI_MR_SLAR_ACK) {
    // return status
    return TWI_STATUS;
  }
  // success
  return SUCCESS;
}

/**
 * @desc    TWI stop
 *
 * @param   void
 *
 * @return  void
 */
void TWI_Stop (void)
{
  // End TWI
  // -------------------------------------------------------------------------------------
  // send stop sequence
  TWI_STOP ();
  // wait for TWINT flag is set
//  TWI_WAIT_TILL_TWINT_IS_SET();
}
