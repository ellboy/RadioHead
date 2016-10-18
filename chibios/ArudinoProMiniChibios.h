/*
 * ArudinoProMiniChibios.h
 *
 *  Created on: 25.09.2016
 *      Author: ellboy
 */

#ifndef RADIOHEAD_RHUTIL_ARUDINOPROMINICHIBIOS_H_
#define RADIOHEAD_RHUTIL_ARUDINOPROMINICHIBIOS_H_

#include <avr/pgmspace.h>

#include "hal.h"

typedef struct
{
	char port_str[10];
    ioportid_t port;
    uint16_t pad;
} GPIOPin;

//A - IOPORT1
//B - IOPORT2
//C - IOPORT3
//D - IOPORT4

const GPIOPin pins[]  PROGMEM =
{
		{"IOPORT4", IOPORT4, 0},	// 0 - PD0
		{"IOPORT4", IOPORT4, 1},	// 1 - PD1
		{"IOPORT4", IOPORT4, 2},   // 2 - PD2
		{"IOPORT4", IOPORT4, 3},	// 3 - PD3
		{"IOPORT4", IOPORT4, 4},	// 4 - PD4
		{"IOPORT4", IOPORT4, 5},	// 5 - PD5
		{"IOPORT4", IOPORT4, 6},	// 6 - PD6
		{"IOPORT4", IOPORT4, 7},	// 7 - PD7
		{"IOPORT2", IOPORT2, 0},	// 8 - PB0
		{"IOPORT2", IOPORT2, 1},	// 9 - PB1
		{"IOPORT2", IOPORT2, 2},	// 10 - PB2
		{"IOPORT2", IOPORT2, 3},	// 11 - PB3
		{"IOPORT2", IOPORT2, 4},	// 12 - PB4
		{"IOPORT2", IOPORT2, 5},	// 13 - PB5
		{"IOPORT3", IOPORT3, 0},	// 14 - PC0
		{"IOPORT3", IOPORT3, 1},	// 15 - PC1
		{"IOPORT3", IOPORT3, 2},	// 16 - PC2
		{"IOPORT3", IOPORT3, 3},	// 17 - PC3
};


#endif /* RADIOHEAD_RHUTIL_ARUDINOPROMINICHIBIOS_H_ */
