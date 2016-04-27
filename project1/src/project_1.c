// project_1.c
//
// Zachary Vogel & James Pentz
// ECEN 5013
// 2/11/2016
#include "memory.h"

#define LENGTH 32

void project_1_report()
{
    uint8_t a[LENGTH];
    uint8_t * aptr_1=&a[0];
    uint8_t * aptr_2=&a[LENGTH/4];
    uint8_t * aptr_3=&a[LENGTH/2];

    uint32_t i;
    for(i=0;i<LENGTH/2;i++)
    {
        *(aptr_1+i)=i+1;
    }
    if(memzero(aptr_3,LENGTH/2))
    {
        printf("failure\n");
        return;
    }
    if(memcpy_(aptr_1,aptr_3,LENGTH/4))
    {
        printf("failure\n");
        return;
    }
    if(memmove_(aptr_2,aptr_1,LENGTH/2))
    {
         printf("failure\n");
         return;
    }
    if(reverse(aptr_1,LENGTH))
    {
        printf("failure\n");
        return;
    }
    printf("Cell Number:");
    for(i=0;i<LENGTH/2;i++)
    {   
        if(i<10)
        {
            printf("%d , ",i);
        }
        else
        {
            printf("%d, ",i);
        }
    }
    printf("\nValue      :");
    for(i=0;i<LENGTH/2;i++)
    {
        if(a[i]<10)
        {
            printf("%d , ",a[i]);
        }
        else{
            printf("%d, ",a[i]);
        }
    }
    printf("\nCell Number:");
    for(i=LENGTH/2;i<LENGTH;i++)
    {   
        if(i<10)
        {
            printf("%d , ",i);
        }
        else
        {
            printf("%d, ",i);
        }
    }
    printf("\nValue      :");
    for(i=LENGTH/2;i<LENGTH;i++)
    {
        if(a[i]<10)
        {
            printf("%d , ",a[i]);
        }
        else{
            printf("%d, ",a[i]);
        }
    }
    printf("\n");
    return;
}
