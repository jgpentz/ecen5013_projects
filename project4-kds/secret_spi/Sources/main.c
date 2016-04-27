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

    for (;;) {
    	if(i == 1000000){
    		write_config(config_stuff);
    		config_stuff = 0x00;
    		read_config(&config_stuff);
    	}
         i++;
    }

    return 0;
}
