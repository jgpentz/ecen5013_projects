// James Pentz

#include "MKL25Z4.h"
#include "spi.h"
#include "nRF24L01.h"

static int i = 0;

int main(void)
{
	uint8_t config_stuff;

	spi_init();

	config_stuff = NORDIC_PWR_UP | NORDIC_PRIM_RX;

	//spi_send_byte(ch);
	//spi_receive_byte(&ch);

    for (;;) {
    	if(i == 1000000){
    		write_config(config_stuff);
    		config_stuff = 0x00;
    		read_config(&config_stuff);
    		/*spi_receive_byte(&ch);
    		ch = 0xaa;
			spi_send_byte(ch);
			spi_receive_byte(&ch);*/
    	}
         i++;
    }
    /* Never leave main */
    return 0;
}
