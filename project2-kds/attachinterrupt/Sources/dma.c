/*
 * dma.c
 *
 *  Created on: Mar 13, 2016
 *      Author: jimmy
 */
#include "dma.h"
#include "MKL25Z4.h"

void dma_init(){
	// enable clock to dma mux
	SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
}
