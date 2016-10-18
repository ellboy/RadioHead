/*
 * configuration.h
 *
 *  Created on: 17.10.2016
 *      Author: ellboy
 */

#ifndef RADIOHEAD_CHIBIOS_CONFIGURATION_H_
#define RADIOHEAD_CHIBIOS_CONFIGURATION_H_


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


#endif /* RADIOHEAD_CHIBIOS_CONFIGURATION_H_ */
