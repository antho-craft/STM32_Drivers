#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "tim.h"

int timestamp = 0;

//Connect a jumper wire between PA5 & PA6 (D12 & D13)
int main(void)
{
	tim2_pa5_output_compare();
	tim3_pa6_input_capture();
	while(1)
	{
		/*Wait until edge is captured*/
		while(!(TIM3->SR & SR_CC1IF)){}
		/*Read captured value*/
		timestamp = TIM3->CCR1;
	}
}






