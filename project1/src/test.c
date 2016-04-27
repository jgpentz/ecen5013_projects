#include "test.h"

void memtest()
{
    char a[]="Hello World";
    char b[]="Hello World";
    char c[]="Hello World";
    char d[]="Hello World";
    uint8_t * ptr1,*ptr2;
    printf("original string %s\n", a);
    printf("testing reverse\n");
    ptr1=(uint8_t *)&b[0];
    reverse(ptr1,11);
    printf("reversed : %s\n",(char*)ptr1);
    printf("reversed with 5 digits\n");
    reverse(ptr1,11);
    reverse(ptr1,5);
    printf("%s\n",(char *)ptr1);
    printf("error test\n");
    printf("passing a non-positive length\n");
    printf("return=%d\n",reverse(ptr1,0));
    printf("passing a null pointer\n");
    printf("return=%d\n",reverse(NULL,2));

    printf("\n\n Testing memcpy\n");
    ptr1=(uint8_t *)&a[0];
    ptr2=(uint8_t *)&a[5];
    printf("one pointer is looking at the original string, the other 5 units down\n");
    memcpy(ptr1,ptr2,11);
    printf("first string: %s\n second string: %s\n",(char *)ptr1,(char *)ptr2);
    printf("now testing for null pointers and non-positive length\n");
    printf("Null first pointer:\n0=success, non-zero=fail, return value=%d\n",memcpy_(NULL,ptr2,5));
    printf("Null second pointer:\n0=success, non-zero=fail, return value=%d\n",memcpy_(ptr1,NULL,5));
    printf("0 string length:\n 0=success, non-zero=fail, return value=%d\n",memcpy_(ptr1,ptr2,0));
    
    printf("\n\n Same exact tests for memmove because it is implemented the same\n");
    ptr1=(uint8_t *)&c[0];
    ptr2=(uint8_t *)&c[5];
    printf("one pointer is looking at the original string, the other 5 units down\n");
    memcpy(ptr1,ptr2,11);
    printf("first string: %s\n second string: %s\n",(char *)ptr1,(char *)ptr2);
    printf("now testing for null pointers and non-positive length\n");
    printf("Null first pointer:\n0=success, non-zero=fail, return value=%d\n",memmove_(NULL,ptr2,5));
    printf("Null second pointer:\n0=success, non-zero=fail, return value=%d\n",memmove_(ptr1,NULL,5));
    printf("0 string length:\n 0=success, non-zero=fail, return value=%d\n",memmove_(ptr1,ptr2,0));

    printf("\n\n memzero test\n");
    ptr1=(uint8_t *)&d[0];
    memzero(ptr1,11);
    printf("String zero'd out:");
    uint8_t i;
    for(i=0;i<11;i++)
    {
        printf("%d,",d[i]);
    }
    printf("\n Now let's test Null and zero length\n");
    printf("Null pointer:\n0=success, non-zero=fail, return value=%d\n",memzero(NULL,5));
    printf("0 string length:\n 0=success, non-zero=fail, return value=%d\n",memzero(ptr1,0));
    printf("That should do it\n");
}
