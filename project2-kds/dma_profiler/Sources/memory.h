// memory.h
//
// Zachary Vogel & James Pentz
// ECEN 5013
// 2/11/2016

#ifndef _MEMORY_H
#define _MEMORY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
uint8_t m_swap(uint32_t *a, uint32_t *b);

typedef enum {
	PASS=0,
	FAIL
} error_codes;

int8_t memmove_(uint32_t * src, uint32_t * dst, uint32_t length);

int8_t memcpy_(uint32_t * src, uint32_t * dst, uint32_t length);

int8_t memzero(uint32_t * src, uint32_t length);

int8_t reverse(uint32_t * str, uint32_t length);

#endif
