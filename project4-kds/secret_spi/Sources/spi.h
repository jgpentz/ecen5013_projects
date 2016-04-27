/*
 * spi.h
 *
 *  Created on: Apr 22, 2016
 *      Author: jimmy
 */

#ifndef SOURCES_SPI_H_
#define SOURCES_SPI_H_

#include "stdint.h"

void spi_init(void);
void spi_send_byte(uint8_t data);
void spi_receive_byte(uint8_t * data);



#endif /* SOURCES_SPI_H_ */
