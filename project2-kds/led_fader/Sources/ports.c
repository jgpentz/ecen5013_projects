/*
 * ports.c
 *
 *  Created on: Feb 28, 2016
 *      Author: jimmy
 */

#include "ports.h"
#include "MKL25Z4.h"

void portb_setup(){

	// Enable PortB clock
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

	// Enable PortD clock
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	// Configure mode to be TPM
	PORTB_PCR18 |= PORT_PCR_MUX(3);
	PORTB_PCR19 |= PORT_PCR_MUX(3);
	PORTD_PCR1 |= PORT_PCR_MUX(4);
}

void porte_setup(){
	// Enable PortE clock
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;

	// Configure mode to be TPM
	PORTE_PCR20 |= PORT_PCR_MUX(3);
}
