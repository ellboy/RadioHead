/*
 * RH_NRF24_wrapper.h
 *
 *  Created on: 26.08.2016
 *      Author: ellboy
 */

#ifndef RH_NRF24_WRAPPER_H_
#define RH_NRF24_WRAPPER_H_

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "configuration.h"

typedef struct RH_NRF24 RH_NRF24;
typedef struct RHGenericSPI RHGenericSPI;

bool RH_NRF24_init(uint8_t chipEnablePin, uint8_t slaveSelectPin, RHGenericSPI *spi);
bool RH_NRF24_setChannel(uint8_t channel);
bool RH_NRF24_setRF(DataRate data_rate, TransmitPower power);
bool RH_NRF24_available(void);
bool RH_NRF24_recv(uint8_t* buf, uint8_t* len);
bool RH_NRF24_send(const uint8_t* data, uint8_t len);
bool RH_NRF24_waitPacketSent(void);
uint8_t RH_NRF24_maxMessageLength(void);
bool RH_NRF24_waitAvailableTimeout(uint16_t timeout);
bool RH_NRF24_waitAvailable(void);

#ifdef __cplusplus
}
#endif


#endif /* RH_NRF24_WRAPPER_H_ */
