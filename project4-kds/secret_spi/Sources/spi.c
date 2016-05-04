/*
 * spi.c
 *
 *  Created on: Apr 22, 2016
 *      Author: jimmy
 */

#include "spi.h"
#include "MKL25Z4.h"

void spi_init(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;	// Enable clock to port A
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;	// Enable clock to port D
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;	// Enable clock to SPI0

	PORTA_PCR16 = PORT_PCR_MUX(1);		// Set PTA16 to alt 1 (GPIO) (CEN)

	PORTD_PCR0 = PORT_PCR_MUX(1);		// Set PTD0 to alt 1 (SPI0_PCS0)
	FGPIOD_PDDR |= (1 << 0);			// Set PTD0 as GPIO Output
	FGPIOD_PSOR |= (1 << 0);			// Initialize pin to 1

	PORTD_PCR1 = PORT_PCR_MUX(2);		// Set PTD1 to alt 2 (SPI0_SCK)
	PORTD_PCR2 = PORT_PCR_MUX(2);		// Set PTD2 to alt 2 (SPI0_MOSI)
	PORTD_PCR3 = PORT_PCR_MUX(2);		// Set PTD3 to alt 2 (SPI0_MISO)

	FGPIOA->PDDR = (1 << 16);			// Set PTA16 as GPIO Output
	FGPIOA->PCOR = (1 << 16);


	SPI0->C1 = SPI_C1_MSTR_MASK; // Set SPI0 as master and configure auto-SS

	// Set Prescaler = 2 and Baud Rate Divider = 4 for a baud rate of 250Kbps
	SPI0->BR = (SPI_BR_SPPR(0x02) | SPI_BR_SPR(0x04));

	SPI0->C1 |= SPI_C1_SPE_MASK; // Enable SPI0
}

// Write char to the SPI0 data register
uint8_t spi_send_byte(uint8_t data){
	uint8_t ret_data;
	while(!(SPI0_S & SPI_S_SPTEF_MASK))  // Wait until Transmit buffer is empty
		__asm("nop");
	SPI0->D = data;						 // Transmit Data
	while(!(SPI0_S & SPI_S_SPRF_MASK));  // Wait until Transmit buffer is empty
	ret_data = SPI0->D;
	return ret_data;
}

// Read char from the SPI0 data register
void spi_receive_byte(uint8_t * data){
	while(!(SPI0_S & SPI_S_SPTEF_MASK)) 				   // Wait until Transmit buffer is empty
		__asm("nop");
	SPI0->D = 0xff;										   // Transmit dummy data
	while((SPI0->S & SPI_S_SPRF_MASK) != SPI_S_SPRF_MASK)  // Wait until Receive buffer is full
		__asm("nop");
	*data = SPI0->D;									   // Read data

}
