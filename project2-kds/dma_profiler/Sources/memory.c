// memory.c
//
// Zachary Vogel & James Pentz
// ECEN 5013
// 2/11/2016

// includes
#include "memory.h"
#include "MKL25Z4.h"

int8_t reverse(uint32_t * str, uint32_t length)
{
    // declare variables
    uint32_t string_inc = 0;
    error_codes status;
    
    // validate input parameters
    if(length <= 0)
    {
    	//printf("Error");
		return status=FAIL;
	}
    else if(!str)
    {
		return status=FAIL;
    }
    // string reversal
    for(string_inc=0; string_inc < length/2; string_inc++)
    {
		m_swap(&str[0 + string_inc], &str[(length-1) - string_inc]);
	}

    return status=PASS;
}

uint8_t m_swap(uint32_t *a, uint32_t *b) {
    uint32_t temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

//No functional difference between this and memcpy
int8_t memmove_(uint32_t * src, uint32_t * dst, uint32_t length)
{
    return memcpy_(src,dst,length);    

}


//I'm just going to copy the string to a new location avoiding the overlap completely.
//we could go through and check where the overlap occurs and only copy from there, this would probably be more efficient
int8_t memcpy_(uint32_t * src, uint32_t * dst, uint32_t length)
{
    error_codes stat;
    if((src==NULL)|(dst==NULL)|(length<=0))
    {
        return stat=FAIL;
    }

    DMA_SAR0 = (uint32_t) src;
    DMA_DAR0 = (uint32_t) dst;


    DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_BCR_MASK & length;
    DMA0->DMA[0].DCR|=DMA_DCR_SSIZE(1)|DMA_DCR_DSIZE(1)|DMA_DCR_SINC_MASK|DMA_DCR_DINC_MASK|DMA_DCR_START_MASK;


    return stat=PASS;
}

int8_t memzero(uint32_t * src, uint32_t length)
{
    error_codes stat;
    if((src==NULL)|(length<=0))
    {
        return stat=FAIL;
    }
    uint32_t i;
    for(i=0;i<length;i++){
        *src=0;
        src++;
    }
    return stat=PASS;
}

