#include "stm32f4xx.h"

#define MASK_13_14   0x14000000  
#define ODR__13_14   0x6000     


void tact_diod(int mask, int odr)
{
	 RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN; // включаем тактирование
	 GPIOG->MODER =  mask;//0x4000000;
	 GPIOG->OTYPER = 0;
	 GPIOG->OSPEEDR = 0;
	 GPIOG->ODR =   odr;//0x2000;	
}

int main(void)
{
	 
	 tact_diod(MASK_13_14,ODR__13_14);
	
	 while(1)
	 {
		 for(int i = 0; i<=  1000000; i++) 
		 {
			 if (i < 500000) GPIOG->ODR = 0x2000;
			 if (i > 500000) GPIOG->ODR = 0x0;
		 }
	 }
}
