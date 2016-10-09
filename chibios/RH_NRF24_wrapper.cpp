/*
 * RH_NRF24_wrapper.cpp
 *
 *  Created on: 18.09.2016
 *      Author: ellboy
 */

#include <stdint.h>
#include "RH_NRF24_wrapper.h"
#include <RH_NRF24.h>
#include <debug.h>

#ifdef __cplusplus
extern "C" {
#endif

// slaveSelect = PB2(10), chipEnable = PC0(14)
//RH_NRF24 nrf24(14,10);
RH_NRF24 nrf24;

bool RH_NRF24_init(uint8_t chipEnablePin, uint8_t slaveSelectPin, RHGenericSPI *spi) {

	//print_dbg("Debug: %s\r\n", __func__);
	nrf24.setChipEnablePin(chipEnablePin);
	nrf24.setSlaveSelectPin(slaveSelectPin);

	return nrf24.init();

}

bool RH_NRF24_setChannel(uint8_t channel) {
	//print_dbg("Debug: %s\r\n", __func__);
	return nrf24.setChannel(channel);
}

bool RH_NRF24_setRF(DataRate data_rate, TransmitPower  power) {
	//print_dbg("Debug: %s\r\n", __func__);
	return nrf24.setRF((RH_NRF24::DataRate)data_rate, (RH_NRF24::TransmitPower)power);
}

bool RH_NRF24_available() {
	//print_dbg("Debug: %s\r\n", __func__);
	return nrf24.available();
}

bool RH_NRF24_recv(uint8_t* buf, uint8_t* len) {
	//print_dbg("Debug: %s\r\n", __func__);
	return nrf24.recv(buf, len);
}

bool RH_NRF24_send(const uint8_t* data, uint8_t len) {
	//print_dbg("Debug: %s\r\n", __func__);
	return nrf24.send(data, len);
}

bool RH_NRF24_waitPacketSent() {
	//print_dbg("Debug: %s\r\n", __func__);
	return nrf24.waitPacketSent();
}

uint8_t RH_NRF24_maxMessageLength() {
	return nrf24.maxMessageLength();
}

bool RH_NRF24_waitAvailableTimeout(uint16_t timeout) {
	return nrf24.waitAvailableTimeout(timeout);
}

bool RH_NRF24_waitAvailable(void) {
	nrf24.waitAvailable();
	return true;
}
#ifdef __cplusplus
}
#endif
