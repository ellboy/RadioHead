/*
 * ChibiosInterface.cpp
 *
 *  Created on: 22.09.2016
 *      Author: ellboy
 */

#include <RadioHead.h>
#include "ChibiosInterface.h"
#include <debug.h>
#include <stdlib.h>

#include "hal.h"
#include "nil.h"

#include "ArudinoProMiniChibios.h"

#include "board.h"
#define ChibiosSPI SPID1

/*!
 * \brief Pure-virtual workaround.
 *
 * The avr-libc does not support a default implementation for handling
 * possible pure-virtual calls. This is a short and empty workaround for this.
 */
extern "C" {
  void __cxa_pure_virtual()
  {
    // put error handling here
  }
}


void SPIClass::begin()
{
	//print_dbg("Debug: %s\r\n", __func__);

//  //Set SPI Defaults
//  uint16_t divider = BCM2835_SPI_CLOCK_DIVIDER_256;
//  uint8_t bitorder = BCM2835_SPI_BIT_ORDER_MSBFIRST;
//  uint8_t datamode = BCM2835_SPI_MODE0;
//
//  begin(divider, bitorder, datamode);

	static const SPIConfig spicfg = {
				IOPORTSPI1,
				2,
				SPI_MODE_0,
				SPI_MSB_FIRST,
				SPI_SCK_FOSC_128,
				NULL
		//spicallback

				//  /* HW dependent part.*/
				//  GPIOB,
				//  12,
				//  SPI_CR1_DFF
				};

	spiStart(&SPID1, &spicfg); /* Setup transfer parameters.       */

}

//void SPIClass::begin(uint16_t divider, uint8_t bitOrder, uint8_t dataMode)
//{
//	print_dbg("Debug: %s, param: divider=%d, bitOrder=%d, dataMode=%d\r\n", __func__, divider, bitOrder, dataMode);
////  setClockDivider(divider);
////  setBitOrder(bitOrder);
////  setDataMode(dataMode);
////
////  //Set CS pins polarity to low
////  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, 0);
////
////  bcm2835_spi_begin();
////
////  //Initialize a timestamp for millis calculation
////  gettimeofday(&RHStartTime, NULL);
//}

void SPIClass::end()
{
	//print_dbg("Debug: %s\r\n", __func__);
//  //End the SPI
//  bcm2835_spi_end();
}

//void SPIClass::setBitOrder(uint8_t bitOrder)
//{
//	print_dbg("Debug: %s, param: bitOrder=%d\r\n", __func__, bitOrder);
////  //Set the SPI bit Order
////  bcm2835_spi_setBitOrder(bitOrder);
//}

//void SPIClass::setDataMode(uint8_t mode)
//{
//	print_dbg("Debug: %s, param: mode=%d\r\n", __func__, mode);
////  //Set SPI data mode
////  bcm2835_spi_setDataMode(mode);
//}

//void SPIClass::setClockDivider(uint16_t rate)
//{
//	print_dbg("Debug: %s\r\n", __func__);
////  //Set SPI clock divider
////  bcm2835_spi_setClockDivider(rate);
//}

byte SPIClass::transfer(byte _data)
{
	byte rxbuf;

//	print_dbg("Debug: %s, TX data=%d\r\n", __func__, (uint8_t)_data);
//	print_dbg("Debug: %s, RX data=%d\r\n", __func__, (uint8_t)rxbuf);
	spiExchange(&ChibiosSPI, sizeof(_data), &_data, &rxbuf);

	return rxbuf;

//  //Set which CS pin to use for next transfers
//  bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
//  //Transfer 1 byte
//  byte data;
//  data = bcm2835_spi_transfer((uint8_t)_data);
//  return data;
}

void pinMode(unsigned char pin, unsigned char mode) {

	//print_dbg("Debug: %s, param: mode=%d\r\n", __func__, mode);

	if (mode == OUTPUT) {
		palSetPadMode(pins[pin].port, pins[pin].pad, PAL_MODE_OUTPUT_PUSHPULL);
	} else {
		palSetPadMode(pins[pin].port, pins[pin].pad, PAL_MODE_INPUT);
	}
}

void digitalWrite(unsigned char pin, unsigned char value)
{
	//print_dbg("Debug: %s, param: pin=%d(%s, %d), value=%d\r\n", __func__, pin, pins[pin].port_str, pins[pin].pad, value);

	palWritePad(pins[pin].port, pins[pin].pad, value);

}

#ifndef ST2MS
#define ST2MS(n) (((n) * 1000UL + NIL_CFG_ST_FREQUENCY - 1UL) /              \
		NIL_CFG_ST_FREQUENCY)
#endif

unsigned long millis() {
//	print_dbg("Debug: %s\r\n", __func__);
//	print_dbg("Debug TODO: %s\r\n", __func__);
//

//
//	print_dbg("Debug: %s\r\n", __func__);
//	print_dbg("1 ms = %d ticks\r\n", MS2ST(1));
//	print_dbg("now time = %d\r\n", ST2MS(chVTGetSystemTimeX()));
//	chThdSleepMilliseconds(10);
//	print_dbg("now time = %d\r\n", chVTGetSystemTimeX());

	return ST2MS(ST2MS(chVTGetSystemTimeX()));

//  //Declare a variable to store current time
//  struct timeval RHCurrentTime;
//  //Get current time
//  gettimeofday(&RHCurrentTime,NULL);
//  //Calculate the difference between our start time and the end time
//  unsigned long difference = ((RHCurrentTime.tv_sec - RHStartTime.tv_sec) * 1000);
//  difference += ((RHCurrentTime.tv_usec - RHStartTime.tv_usec)/1000);
//  //Return the calculated value
//  return difference;
}

void delay(unsigned long ms) {
	//print_dbg("Debug: %s: %d\r\n", __func__, ms);
	chThdSleepMilliseconds(ms);

}

long random(long min, long max) {
	//print_dbg("Debug: %s\r\n", __func__);
	long diff = max - min;
	long ret = diff * rand() + min;
	return ret;
}
