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
	FGPIOD_PCOR |= (1<<0);
	spi_send_byte(NORDIC_WR_REG | NORDIC_CONFIG_REG);	// Initiate a write to the config reg
	spi_send_byte(config_command);						// Send config command
	spi_send_byte(DUMMY_BYTE);						// Send config command
	spi_send_byte(DUMMY_BYTE);						// Send config command
	spi_send_byte(DUMMY_BYTE);						// Send config command
	FGPIOD_PSOR |= (1<<0);
}

void read_config(uint8_t * config_data){
	uint8_t tmp_data;
	uint8_t dummy_data;
	uint8_t dummy_data1, dummy_data2, dummy_data3;
	FGPIOD_PCOR |= (1<<0);
	spi_send_byte(NORDIC_RD_REG | NORDIC_CONFIG_REG);	// Initiate a read to the config reg
	spi_receive_byte((uint8_t *)&tmp_data);				// receive important first byte
	spi_receive_byte((uint8_t *)&dummy_data1);
	spi_receive_byte((uint8_t *)&dummy_data2);
	spi_receive_byte((uint8_t *)&dummy_data3);
	FGPIOD_PSOR |= (1<<0);
	*config_data = tmp_data;
}
