/*
 * RHReliableDatagram_wrapper.h
 *
 *  Created on: 05.10.2016
 *      Author: ellboy
 */

#ifndef RHRELIABLEDATAGRAM_WRAPPER_H_
#define RHRELIABLEDATAGRAM_WRAPPER_H_

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

typedef struct RHReliableDatagram RHReliableDatagram;


 /// Sets the minimum retransmit timeout. If sendtoWait is waiting for an ack
    /// longer than this time (in milliseconds),
    /// it will retransmit the message. Defaults to 200ms. The timeout is measured from the end of
    /// transmission of the message. It must be at least longer than the the transmit
    /// time of the acknowledgement (preamble+6 octets) plus the latency/poll time of the receiver.
    /// For fast modulation schemes you can considerably shorten this time.
    /// Caution: if you are using slow packet rates and long packets
    /// you may need to change the timeout for reliable operations.
    /// The actual timeout is randomly varied between timeout and timeout*2.
    /// \param[in] timeout The new timeout period in milliseconds
    void RHReliableDatagram_setTimeout(uint16_t timeout);

    /// Sets the maximum number of retries. Defaults to 3 at construction time.
    /// If set to 0, each message will only ever be sent once.
    /// sendtoWait will give up and return false if there is no ack received after all transmissions time out
    /// and the retries count is exhausted.
    /// param[in] retries The maximum number a retries.
    void RHReliableDatagram_setRetries(uint8_t retries);

    /// Returns the currently configured maximum retries count.
    /// Can be changed with setRetries().
    /// \return The currently configured maximum number of retries.
    uint8_t RHReliableDatagram_retries();

    /// Send the message (with retries) and waits for an ack. Returns true if an acknowledgement is received.
    /// Synchronous: any message other than the desired ACK received while waiting is discarded.
    /// Blocks until an ACK is received or all retries are exhausted (ie up to retries*timeout milliseconds).
    /// If the destination address is the broadcast address RH_BROADCAST_ADDRESS (255), the message will
    /// be sent as a broadcast, but receiving nodes do not acknowledge, and sendtoWait() returns true immediately
    /// without waiting for any acknowledgements.
    /// \param[in] address The address to send the message to.
    /// \param[in] buf Pointer to the binary message to send
    /// \param[in] len Number of octets to send
    /// \return true if the message was transmitted and an acknowledgement was received.
    bool RHReliableDatagram_sendtoWait(uint8_t* buf, uint8_t len, uint8_t address);

    /// If there is a valid message available for this node, send an acknowledgement to the SRC
    /// address (blocking until this is complete), then copy the message to buf and return true
    /// else return false.
    /// If a message is copied, *len is set to the length..
    /// If from is not NULL, the SRC address is placed in *from.
    /// If to is not NULL, the DEST address is placed in *to.
    /// This is the preferred function for getting messages addressed to this node.
    /// If the message is not a broadcast, acknowledge to the sender before returning.
    /// You should be sure to call this function frequently enough to not miss any messages
    /// It is recommended that you call it in your main loop.
    /// \param[in] buf Location to copy the received message
    /// \param[in,out] len Available space in buf. Set to the actual number of octets copied.
    /// \param[in] from If present and not NULL, the referenced uint8_t will be set to the SRC address
    /// \param[in] to If present and not NULL, the referenced uint8_t will be set to the DEST address
    /// \param[in] id If present and not NULL, the referenced uint8_t will be set to the ID
    /// \param[in] flags If present and not NULL, the referenced uint8_t will be set to the FLAGS
    /// (not just those addressed to this node).
    /// \return true if a valid message was copied to buf
    bool RHReliableDatagram_recvfromAck(uint8_t* buf, uint8_t* len, uint8_t* from = NULL, uint8_t* to = NULL, uint8_t* id = NULL, uint8_t* flags = NULL);

    /// Similar to recvfromAck(), this will block until either a valid message available for this node
    /// or the timeout expires. Starts the receiver automatically.
    /// You should be sure to call this function frequently enough to not miss any messages
    /// It is recommended that you call it in your main loop.
    /// \param[in] buf Location to copy the received message
    /// \param[in,out] len Available space in buf. Set to the actual number of octets copied.
    /// \param[in] timeout Maximum time to wait in milliseconds
    /// \param[in] from If present and not NULL, the referenced uint8_t will be set to the SRC address
    /// \param[in] to If present and not NULL, the referenced uint8_t will be set to the DEST address
    /// \param[in] id If present and not NULL, the referenced uint8_t will be set to the ID
    /// \param[in] flags If present and not NULL, the referenced uint8_t will be set to the FLAGS
    /// (not just those addressed to this node).
    /// \return true if a valid message was copied to buf
    bool RHReliableDatagram_recvfromAckTimeout(uint8_t* buf, uint8_t* len,  uint16_t timeout, uint8_t* from = NULL, uint8_t* to = NULL, uint8_t* id = NULL, uint8_t* flags = NULL);

    /// Returns the number of retransmissions
    /// we have had to send since starting or since the last call to resetRetransmissions().
    /// \return The number of retransmissions since initialisation.
    uint32_t RHReliableDatagram_retransmissions();

    /// Resets the count of the number of retransmissions
    /// to 0.
    void RHReliableDatagram_resetRetransmissions();

#ifdef __cplusplus
}
#endif

#endif /* RHRELIABLEDATAGRAM_WRAPPER_H_ */
