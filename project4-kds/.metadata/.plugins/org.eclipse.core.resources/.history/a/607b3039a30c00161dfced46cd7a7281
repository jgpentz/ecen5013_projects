/*
 * nRF24L01.h
 *
 *  Created on: Apr 25, 2016
 *      Author: jimmy
 */

#ifndef SOURCES_NRF24L01_H_
#define SOURCES_NRF24L01_H_

// All of the Nordic Commands
#define NORDIC_RD_REG 0x00
#define NORDIC_WR_REG 0x20
#define NORDIC_CONFIG_REG 0x00
#define NORDIC_RF_SETUP_REG 0x06
#define NORDIC_STATUS_REG 0x07
#define NORDIC_TX_ADDR 0x10
#define NORDIC_FIFO_STATUS_REG 0x17
#define NORDIC_RX_PAYLOAD 0x61
#define NORDIC_TX_PAYLOAD 0xa0
#define NORDIC_TX_FLUSH 0xe1
#define NORDIC_RX_FLUSH 0xe2
#define NORDIC_PWR_UP 0x02
#define NORDIC_PWR_DOWN 0x00
#define NORDIC_PRIM_RX 0x01
#define NORDIC_PRIM_TX 0x00
#define DUMMY_BYTE 0x00

void write_config(uint8_t config_command);
void read_config(uint8_t * config_data);

#endif /* SOURCES_NRF24L01_H_ */
