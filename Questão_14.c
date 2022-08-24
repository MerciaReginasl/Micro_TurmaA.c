Questão 14

#include "stm32f4xx.h"
#include "Utility.h"
			
int main(void){

	Configure_Clock(); //  Configura o sistema de clock
			Delay_Start();    // Inicializa as funções delay
			//RCC->AHB1ENR |= 0x05;
			//GPIOA->MODER |= 0x0015;
			//GPIOC->MODER |= 0x0015;
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
			GPIOA->MODER |= 0b01 << 12;
			GPIOA->MODER |= 0b01 << 14;
			GPIOA->MODER |= 0b01 << 10;
			GPIOA->MODER |= 0b01 << 8;
			GPIOA->MODER |= 0b01 << 2;
			GPIOA->MODER |= 0b01 << 4;
			GPIOA->MODER |= 0b01 << 6;


			while(1)
			{

				GPIOA->ODR |= (1 << 1); // liga vermelho 1
				GPIOA->ODR |= (1 << 2); // liga verde 2

				Delay_ms(5000);

				GPIOA->ODR &= ~(1 << 2); // desliga verde 2
				GPIOA->ODR |= (1 << 3); // liga amarelo 2

				Delay_ms(2000);
				GPIOA->ODR &= ~(1 << 3); // desliga amarelo 2
				GPIOA->ODR |= (1 << 4); // liga vermelho 2

				GPIOA->ODR &= ~(1 << 1); // desliga vermelho 1
				GPIOA->ODR |= (1 << 5); // liga verde 2

				Delay_ms(5000);

				GPIOA->ODR &= ~(1 << 5); // desliga verde 1
				GPIOA->ODR |= (1 << 6); // liga amarelo 1

				Delay_ms(2000);

				GPIOA->ODR &= ~(1 << 6); //desliga o amarelo 1
				GPIOA->ODR &= ~(1 << 4); // desliga vermelho 2

			}

}

