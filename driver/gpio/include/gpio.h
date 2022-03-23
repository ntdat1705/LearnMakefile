#ifndef __GPIO_H
#define __GPIO_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "core_cm3.h"

void GPIO_InitPC13(void);
void GPIO_InitPA0(void);
void GPIO_InitExtiPA0(void);
void GPIO_SetPinPC13(void);
void GPIO_ResetPinPC13(void);
void GPIO_TogglePinPC13(void);
uint8_t GPIO_ReadPinPA0(void);

#endif