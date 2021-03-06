// memory.c
//
// Zachary Vogel & James Pentz
// ECEN 5013
// 2/11/2016

// includes
#include "memory.h"
#include "MKL25Z4.h"

int32_t reverse(uint8_t * str, uint32_t length)
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

uint8_t m_swap(uint8_t *a, uint8_t *b){
    uint8_t temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

//No functional difference between this and memcpy
int32_t memmove_(uint8_t * src, uint8_t * dst, uint32_t length)
{
    return memcpy_(src,dst,length);    

}


//I'm just going to copy the string to a new location avoiding the overlap completely.
//we could go through and check where the overlap occurs and only copy from there, this would probably be more efficient
int32_t memcpy_(uint8_t * src, uint8_t * dst, uint32_t length)
{
    error_codes stat;
    if((src==NULL)|(dst==NULL)|(length<=0))
    {
        return stat=FAIL;
    }

    DMA_SAR0 = src;
    DMA_DAR0 = dst;

    uint8_t temp[length];
    uint32_t i;
    for(i=0;i<length;i++)
    {
        temp[i]=*src;
        src++;
    }
    for(i=0;i<length;i++)
    {
        *dst=temp[i];
        dst++;
    }


    return stat=PASS;
}

int32_t memzero(uint8_t * src, uint32_t length)
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

