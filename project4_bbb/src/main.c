// main.c
//
// James Pentz & Zachary Vogel
// ECEN 5013
// 5/2/2016

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<stdint.h>
#include<linux/spi/spidev.h>
#include "gpio.h"

#define SPI_PATH "/dev/spidev1.0"

int transfer(int fd, unsigned char send[], unsigned char receive[], int length){
   struct spi_ioc_transfer transfer;           //the transfer structure
   transfer.tx_buf = (unsigned long) send;     //the buffer for sending data
   transfer.rx_buf = (unsigned long) receive;  //the buffer for receiving data
   transfer.len = length;                      //the length of buffer
   transfer.speed_hz = 250000;                //the speed in Hz
   transfer.bits_per_word = 8;                 //bits per word
   transfer.delay_usecs = 0;                   //delay in us

   // send the SPI message (all of the above fields, inc. buffers)
   int status = ioctl(fd, SPI_IOC_MESSAGE(1), &transfer);
   if (status < 0) {
      perror("SPI: SPI_IOC_MESSAGE Failed");
      return -1;
   }
   return receive[0];
}

int main(){
   int fd, i=0;                   //file handle and loop counter
   unsigned char value, null=0x00;         //sending only a single char
   uint8_t bits = 8, mode = 3;             //8-bits per word, SPI mode 3
   uint32_t speed = 250000;               //Speed is 250 KHz
   uint8_t buf[1];

   // The following calls set up the SPI bus properties
   if ((fd = open(SPI_PATH, O_RDWR))<0){
      perror("SPI Error: Can't open device.");
      return -1;
   }
   if (ioctl(fd, SPI_IOC_WR_MODE, &mode)==-1){
      perror("SPI: Can't set SPI mode.");
      return -1;
   }
   if (ioctl(fd, SPI_IOC_RD_MODE, &mode)==-1){
      perror("SPI: Can't get SPI mode.");
      return -1;
   }
   if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits)==-1){
      perror("SPI: Can't set bits per word.");
      return -1;
   }
   if (ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits)==-1){
      perror("SPI: Can't get bits per word.");
      return -1;
   }
   if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed)==-1){
      perror("SPI: Can't set max speed HZ");
      return -1;
   }
   if (ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed)==-1){
      perror("SPI: Can't get max speed HZ.");
      return -1;
   }

   // Check that the properties have been set
   printf("SPI Mode is: %d\n", mode);
   printf("SPI Bits is: %d\n", bits);
   printf("SPI Speed is: %d\n\n", speed);

   i = 1;
   int rd_config_reg[2] = {0x00, 0xff};
   int wr_config_reg[2] = {0x20, 0x03};
   int config_reg_params = 0x03;
   int get_val = 1;
   int dummy_data = 0xff;

   gpio_export(117);
   gpio_set_dir(117,GPIO_DIR_OUTPUT);
   gpio_set_value(117, 1);
   usleep(100000);
   usleep(100000);
   usleep(100000);

   gpio_set_value(117, 0);
   transfer(fd, (unsigned char*) &wr_config_reg, (unsigned char*) &buf, 2);
   //transfer(fd, (unsigned char*) &config_reg_params, &null, 1);
   gpio_set_value(117, 1);
   printf("status maybe: %02x\n", buf[0]);

   for(;;){
  
      usleep(100000); 
      usleep(100000);  

      gpio_set_value(117,0);
      transfer(fd, (unsigned char*) &rd_config_reg, (unsigned char*) &buf, 2);
      //transfer(fd, (unsigned char*) &dummy_data,(unsigned char*) &buf, 1);
      gpio_set_value(117,1); 
      printf("config reg maybe: %02x, %02x\n", buf[0], buf[1]); 
    
      usleep(100000);
      usleep(100000);
      usleep(100000); 

   /*// Loop from 0 to 255 and light the LED bar as a binary counter
   for (i=0; i<255; i++)
   {
      // This function can send and receive data, just sending here
      if (transfer(fd, (unsigned char*) &i, &null, 1)==-1){
         perror("Failed to update the display");
         return -1;
      }
      printf("%4d\r", i);   //print the number on the same line
      fflush(stdout);       //need to flush the output, no \n
      usleep(100000);       //sleep for 100ms each loop
   }*/
   }
   close(fd);               //close the file
   return 0;
}
