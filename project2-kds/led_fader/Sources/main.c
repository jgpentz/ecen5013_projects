#include "MKL25Z4.h"
#include "ports.h"
#include "timer.h"
#include "sine_table.h"
#include "memory.h"
#include "string.h"
#include "dma.h"
//#include "profiler.h"

static int redled_cnt = 0;
static int greenled_cnt = 244;
static int blueled_cnt = 122;
volatile uint32_t micro_seconds;
int i;
uint8_t a[5000];
uint8_t ai[5000];
uint8_t * ptr1;
uint8_t * ptr2;

int main(void)
{
	//led_timer_init();
	//portb_setup();
	porte_setup();
	profiling_timer_init();
	dma_init();
	//profiler();

	for(i=0; i<5000; i++){
		a[i] = 0xaa;
		ai[i]= 0;
	}
	ptr1 = (uint8_t *) &a[0];
	ptr2 = (uint8_t *) &ai[0];

	micro_seconds = 0;
	//memmove_(ptr1, ptr2, 5000);
	//micro_seconds = 0;
	strcpy(ptr1, ptr2);
	//micro_seconds = 0;
	//memset(ptr1, 0, 1000);
	//micro_seconds = 0;
	//reverse(ptr1, 101);
	//micro_seconds = 0;
	//reverse(ptr1, 11);
	//memset(ptr1, 0, 1000);

	i = 0;
	// loop forever
	while(1){
	}
    return 0;
}

extern void TPM0_IRQHandler(){
	// clear interrupt
	__disable_irq();
	TPM0_SC |= TPM_SC_TOF_MASK;

	// check if index has reached the end of the sinewave_data array
	if(blueled_cnt == 512)
		blueled_cnt = 0;

	// assign output led colors
	TPM0_C1V = sinewave_data[blueled_cnt];

	blueled_cnt++;
	__enable_irq();
}

extern void TPM1_IRQHandler(){
	// clear interrupt
	__disable_irq();
	TPM1_SC |= TPM_SC_TOF_MASK;


	// increment usecond counter
	micro_seconds = micro_seconds + 1;

	__enable_irq();
}

extern void TPM2_IRQHandler(){
	// clear interrupt
	__disable_irq();
	TPM2_SC |= TPM_SC_TOF_MASK;

	// check if index has reached the end of the sinewave_data array
	if(redled_cnt == 512)
		redled_cnt = 0;
	if(greenled_cnt == 512)
		greenled_cnt =0;

	// assign output led colors
	TPM2_C0V = sinewave_data[redled_cnt];
	TPM2_C1V = sinewave_data[greenled_cnt];

	redled_cnt++;
	greenled_cnt++;
	__enable_irq();
}
