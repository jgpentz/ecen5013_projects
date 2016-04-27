#include "MKL25Z4.h"

uint8_t global_uninit;
uint16_t global_zeroinit = 0;
uint32_t global_nonzeroinit = 1337;
const uint32_t const_var = 0x1337;
const uint8_t const_string[] = "ECEN5013 - Embedded Software Essentials";

struct foo {
	uint8_t c;			// 1 byte
	uint8_t pad[4];		// 4 bytes
	uint8_t *p;			// 4 bytes
	uint32_t x;			// 4 bytes
}__attribute__((packed));

struct foo1 {
	uint8_t c;			// 1 byte
	uint8_t pad[4];		// 4 bytes
	uint8_t *p;			// 4 bytes
	uint32_t x;			// 4 bytes
}__attribute__((packed, aligned(2)));

struct foo structy;
struct foo1 structyy;

int main(void)
{
	uint8_t local_uninit;
	uint16_t local_zeroinit = 0;
	uint32_t local_nonzeroinit = 1337;

	structyy.c = 1;
	while(1){
	}
    return 0;
}

void foo(void){
	static uint8_t static_uninit;
	static uint16_t static_zeroinit = 0;
	static uint32_t static_nonzeroinit = 1337;
}
