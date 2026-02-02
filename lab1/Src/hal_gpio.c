#include <stdint.h>
#include <stm32f0xx_hal.h>
#include <stm32f0xx_hal_gpio.h>

/*
PC6 (RED LED) - General Purpose Output: (GPIOC, Pin6), 13 -> 0, 12 ->1
              - GPIOC_OTYPER - Push-Pull Output Type: 6 -> 0
              - GPIOC_OSPEEDR - Low Speed: 13 -> x, 12 -> 0
              - GPIOC_PUPDR - No Pull-Up or Pull-Down: 13 -> 0, 12 -> 0
PC7 (BLUE LED) - General Purpose Output: (GPIOC, Pin7), 15 -> 0, 14 ->1
              - GPIOC_OTYPER - Push-Pull Output Type: 7 -> 0
              - GPIOC_OSPEEDR - Low Speed: 15 -> x, 14 -> 0
              - GPIOC_PUPDR - No Pull-Up or Pull-Down: 15 -> 0, 14 -> 0
PC8 (ORANGE LED) - General Purpose Output: (GPIOC, Pin8), 17 -> 0, 16 ->1
              - GPIOC_OTYPER - Push-Pull Output Type: 8 -> 0
              - GPIOC_OSPEEDR - Low Speed: 17 -> x, 16 -> 0
              - GPIOC_PUPDR - No Pull-Up or Pull-Down: 17 -> 0, 16 -> 0
PC9 (GREEN LED) - General Purpose Output: (GPIOC, Pin9), 19 -> 0, 18 ->1
              - GPIOC_OTYPER - Push-Pull Output Type: 9 -> 0
              - GPIOC_OSPEEDR - Low Speed: 19 -> x, 18 -> 0
              - GPIOC_PUPDR - No Pull-Up or Pull-Down: 19 -> 0, 18 -> 0
PA0 (USER BUTTON) - Digital Input: (GPIOa, Pin0), 1 -> 0, 0 -> 0
              - GPIOA_OSPEEDR - Low Speed: 1 -> x, 0 -> 0
              - GPIOxA_PUPDR - Pull-Down Resistor: 1 -> 1, 0 -> 0
*/


void My_HAL_GPIO_Init(GPIO_TypeDef  *GPIOx)
{
    if (GPIOx == GPIOA) 
    {
        // PA0
        GPIOx->MODER &= ~((1 << 1) | (1 << 0));
        GPIOx->OSPEEDR &= ~((1 << 1) | (1 << 0));
        GPIOx->PUPDR &= ~(( 1 << 1) | (1 << 0));
        GPIOx->PUPDR |= (1 << 1);
    }
    else if (GPIOx == GPIOC) 
    {
        // PC6
        GPIOx->MODER &= ~((1 << 13 ) | (1 << 12));
        GPIOx->MODER |= (1 << 12);
        GPIOx->OTYPER &= ~(1 << 6);
        GPIOx->OSPEEDR &= ~((1 << 13) | (1 << 12));
        GPIOx->PUPDR &= ~((1 << 13) | (1 << 12));

        // PC7
        GPIOx->MODER &= ~((1 << 15) | (1 << 14));
        GPIOx->MODER |= (1 << 14);
        GPIOx->OTYPER &= ~(1 << 7);
        GPIOx->OSPEEDR &= ~((1 << 15) | (1 << 14));
        GPIOx->PUPDR &= ~((1 << 15) | (1 << 14));

        // PC8
        GPIOx->MODER &= ~((1 << 17) | (1 << 16));
        GPIOx->MODER |= (1 << 16);
        GPIOx->OTYPER &= ~(1 << 8);
        GPIOx->OSPEEDR &= ~((1 << 17) | (1 << 16));
        GPIOx->PUPDR &= ~((1 << 17) | (1 << 16));

        // PC9
        GPIOx->MODER &= ~((1 << 19) | (1 << 18));
        GPIOx->MODER |= (1 << 18);
        GPIOx->OTYPER &= ~(1 << 9);
        GPIOx->OSPEEDR &= ~((1 << 19) | (1 << 18));
        GPIOx->PUPDR &= ~((1 << 19) | (1 << 18));
    }
}


/*
void My_HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin)
{
}
*/


GPIO_PinState My_HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{   
    return (GPIOx->IDR & GPIO_Pin);
}


void My_HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (PinState == GPIO_PIN_SET) 
    {
        GPIOx->ODR |= GPIO_Pin;
    } else 
    {
        GPIOx->ODR &= ~GPIO_Pin;
    }
}

void My_HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->ODR ^= GPIO_Pin;
}

