/*
 * profiler.c
 *
 *  Created on: Mar 13, 2016
 *      Author: jimmy
 */
#include "profiler.h"

uint8_t a[5000];
uint8_t ai[5000];
uint8_t * ptr1;
uint8_t * ptr2;
int8_t error;
int i;
extern volatile uint16_t micro_seconds;

void profiler(){

	//src_arrays_t src_arrays;
	//dst_arrays_t dst_arrays;

	// fill up all 4 arrays with 0xaa bytes
	for(i = 0; i < 5000; i++){
		a[i] = 0xaa;
		ai[i] = 0;
	}

	// loop through arrays for each function
	ptr1 = (uint8_t *) a[0];
	ptr2 = (uint8_t *) ai[0];

	micro_seconds = 0;
	memmove_(ptr1, ptr2, 10);
	micro_seconds = 0;
	memzero(ptr2, 11);

	micro_seconds = 0;
	memmove_(ptr1, ptr2, 100);
	micro_seconds = 0;
	memzero(ptr2, 101);

	micro_seconds = 0;
	memmove_(ptr1, ptr2, 1000);
	micro_seconds = 0;
	memzero(ptr2, 1001);

	micro_seconds = 0;
	memmove_(ptr1, ptr2, 5000);
	micro_seconds = 0;
	memzero(ptr2, 5001);
	micro_seconds = 0;

	return;
}