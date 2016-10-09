/*
 * RHReliableDatagram_wrapper.c
 *
 *  Created on: 05.10.2016
 *      Author: ellboy
 */

#include "RHReliableDatagram_wrapper.h"
#include "RHReliableDatagram.h"
#include <debug.h>

#ifdef __cplusplus
extern "C" {
#endif

RHReliableDatagram manager;

void RHReliableDatagram_setTimeout(uint16_t timeout) {
	manager.setTimeout(timeout);
}

void RHReliableDatagram_setRetries(uint8_t retries) {
	manager.setRetries(retries);
}

uint8_t RHReliableDatagram_retries() {
	return manager.retries();
}

bool RHReliableDatagram_sendtoWait(uint8_t* buf, uint8_t len, uint8_t address) {
	return manager.sendtoWait(buf, len, address);
}

bool RHReliableDatagram_recvfromAck(uint8_t* buf, uint8_t* len, uint8_t* from, uint8_t* to, uint8_t* id, uint8_t* flags) {
	return manager.recvfromAck(buf, len, from, to, id, flags);
}

bool RHReliableDatagram_recvfromAckTimeout(uint8_t* buf, uint8_t* len, uint16_t timeout, uint8_t* from, uint8_t* to, uint8_t* id, uint8_t* flags) {
	return manager.recvfromAckTimeout(buf, len, timeout, from, to, id, flags);
}

uint32_t RHReliableDatagram_retransmissions() {
	return manager.retransmissions();
}

void RHReliableDatagram_resetRetransmissions() {
	manager.resetRetransmissions();
}

#ifdef __cplusplus
}
#endif
