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


//struct NRF24;
typedef struct RH_NRF24 RH_NRF24;
typedef struct RHGenericSPI RHGenericSPI;
//typedef enum DataRate DataRate;
//typedef enum TransmitPower TransmitPower;

/// \brief Defines convenient values for setting data rates in setRF()
typedef enum {
	DataRate1Mbps = 0,   ///< 1 Mbps
	DataRate2Mbps,       ///< 2 Mbps
	DataRate250kbps      ///< 250 kbps
} DataRate;

/// \brief Convenient values for setting transmitter power in setRF()
/// These are designed to agree with the values for RF_PWR in RH_NRF24_REG_06_RF_SETUP
/// To be passed to setRF();
typedef enum {
// Add 20dBm for nRF24L01p with PA and LNA modules
	TransmitPowerm18dBm = 0,        ///< On nRF24, -18 dBm
	TransmitPowerm12dBm,            ///< On nRF24, -12 dBm
	TransmitPowerm6dBm,             ///< On nRF24, -6 dBm
	TransmitPower0dBm,              ///< On nRF24, 0 dBm
//// Sigh, different power levels for the same bit patterns on RFM73:
//// On RFM73P-S, there is a Tx power amp, so expect higher power levels, up to 20dBm. Alas
//// there is no clear documentation on the power for different settings :-(
//	RFM73TransmitPowerm10dBm = 0,   ///< On RFM73, -10 dBm
//	RFM73TransmitPowerm5dBm,        ///< On RFM73, -5 dBm
//	RFM73TransmitPowerm0dBm,        ///< On RFM73, 0 dBm
//	RFM73TransmitPower5dBm          ///< On RFM73, 5 dBm. 20dBm on RFM73P-S2 ?

} TransmitPower;

extern int RH_NRF24_MAX_MESSAGE_LEN;

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

//void NRF24_destroy(RH_NRF24 *p);
//int NRF24_getA(RH_NRF24 *p);
//void NRF24_setA(RH_NRF24 *p, int a);

#ifdef __cplusplus
}
#endif


#endif /* RH_NRF24_WRAPPER_H_ */
