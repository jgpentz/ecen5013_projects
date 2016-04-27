#include "MKL25Z4.h"
#include "stdint.h"

static int i = 0;

int main(void)
{
    /* Never leave main */
    return 0;
}

char * itoa(uint8_t * buffer, int32_t num, uint32_t base, uint32_t length){
	uint8_t sign;

	// validate inputs
	if(!buffer || base < 0)
		return 0;

	// check for sign of number
	sign = num;
	if(sign < 0)
		num = -num;

	// recursively convert from itoa
	while(num > 0){
		*buffer++ = num % base + '0';
		num /= 10;
	}

	// add negative sign

	// add terminator

	// reverse number

}
