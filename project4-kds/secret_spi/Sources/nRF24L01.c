/*
 * nRF24L01.c
 *
 *  Created on: Apr 25, 2016
 *      Author: jimmy
 */

#include "MKL25Z4.h"
#include "nRF24L01.h"
#include "spi.h"

void write_config(uint8_t config_command){
	spi_send_byte(NORDIC_WR_REG | NORDIC_CONFIG_REG);	// Initiate a write to the config reg
	spi_send_byte(config_command);						// Send config command
	spi_send_byte(DUMMY_BYTE);						// Send config command
	spi_send_byte(DUMMY_BYTE);						// Send config command
	spi_send_byte(DUMMY_BYTE);						// Send config command
}

void read_config(uint8_t * config_data){
	uint8_t tmp_data;
	uint8_t dummy_data;
	spi_send_byte(NORDIC_RD_REG | NORDIC_CONFIG_REG);	// Initiate a read to the config reg
	spi_receive_byte((uint8_t *)&tmp_data);				// receive important first byte
	spi_receive_byte((uint8_t *)&dummy_data);
	spi_receive_byte((uint8_t *)&dummy_data);
	spi_receive_byte((uint8_t *)&dummy_data);
	*config_data = tmp_data;
}
