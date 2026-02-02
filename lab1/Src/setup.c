#include "main.h"s

/**
* @brief Enable AHB peripheral clock register on GPIOC
*/
void HAL_RCC_GPIOC_CLK_ENABLE() 
{
    RCC->APBENR |= RCC_AHBENR_GPIOCEN; 
}