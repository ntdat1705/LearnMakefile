#include "gpio.h"

void GPIO_InitPC13(void)
{
	RCC->APB2ENR |= (1 << 4); /* Or  0b10000 --> Anabling Preiph GPIOC */
	GPIOC->CRH &= ~(0xF << 20);  /* Reset the PORT C PIN 13 */
	GPIOC->CRH |= (3 << 20);  /* Set Port C PIN 13 as Output  */
	GPIOC->BSRR  |= (1 << 13);     /* Set Port C Pin 13 */
}

void GPIO_InitPA0(void)
{
	RCC->APB2ENR |= (1 << 2); //Anabling Preiph GPIOA */
	GPIOA->CRL &= ~(0xF << 0);/* Reset the PORT A PIN 0 */
	GPIOA->CRL |= (1 << 3);/* Set Port A PIN 0 as Input  */
	GPIOA->BSRR  |= (1 << 0);/* Set Port A PIN 0 as Input with pull up */
}

void GPIO_SetPinPC13(void)
{
	GPIOC->BSRR  |= (1 << 13);
}
void GPIO_ResetPinPC13(void)
{
	GPIOC->BRR  |= (1 << 13);
}

void GPIO_TogglePinPC13(void)
{
	GPIOC->ODR ^= (1 << 13);
}

uint8_t GPIO_ReadPinPA0(void)
{
	if(((GPIOA->IDR)&(1 << 0)) == 0)
	{
		return 0;
	}else{
		return 1;
	}
}

void GPIO_InitExtiPA0(void)
{
	EXTI->PR |= (1 << 0); //clear it
	RCC->APB2ENR |= (1 << 0); //Anabling Preiph AFIO */
	AFIO->EXTICR[0] &= ~(0xF << 0); //EXTI0 PAx
	EXTI->RTSR &= ~(1 << 0); //falling trigger
	EXTI->FTSR |= (1 << 0); //falling trigger
	EXTI->SWIER &= ~(1 << 0);
	EXTI->EMR &= ~(1 << 0);
	EXTI->IMR |= (1 << 0); //mask on line 0
	NVIC->IP[0] = 0;
	NVIC->ISER[0] |= (1 << 6); //enable it
}