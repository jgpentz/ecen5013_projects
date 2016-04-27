#include "MKL25Z4.h"
#include "timer.h"
#include "memory.h"

static volatile uint32_t micro_seconds;

int main(void)
{
	dma_timer_init();




	return 0;
}

extern void TPM0_IRQHandler(){
	// clear interrupt
	__disable_irq();
	TPM0_SC |= TPM_SC_TOF_MASK;
	micro_seconds = micro_seconds + 1;
	__enable_irq();
}
