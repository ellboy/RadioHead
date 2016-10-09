/*
 * ChibiosInterface.h
 *
 *  Created on: 29.08.2016
 *      Author: ellboy
 */

#ifndef RADIOHEAD_RHUTIL_CHIBIOSINTERFACE_H_
#define RADIOHEAD_RHUTIL_CHIBIOSINTERFACE_H_

// #include <RHGenericSPI.h>

//#include <RadioHead.h>

#include <stdint.h>

//#include <RHNRFSPIDriver.h>
//#include <RHGenericDriver.h>
//#include <RHHardwareSPI.h>

//class RHGenericSPI;

//#include <RHNRFSPIDriver.h>
//#include <RHHardwareSPI.h>

#include "chprintf.h"

typedef unsigned char byte;

#ifndef NULL
  #define NULL 0
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef HIGH
#define HIGH 1
#endif

#ifndef OUTPUT
  #define OUTPUT 1
#endif

class SPIClass
{
  public:
    static byte transfer(byte _data);
    // SPI Configuration methods
    static void begin(); // Default
    //static void begin(uint16_t, uint8_t, uint8_t);
    static void end();
//    static void setBitOrder(uint8_t);
//    static void setDataMode(uint8_t);
//    static void setClockDivider(uint16_t);
};

extern SPIClass SPI;

void RasPiSetup();

void pinMode(unsigned char pin, unsigned char mode);

void digitalWrite(unsigned char pin, unsigned char value);

unsigned long millis();

void delay (unsigned long delay);

long random(long min, long max);


#endif /* RADIOHEAD_RHUTIL_CHIBIOSINTERFACE_H_ */
