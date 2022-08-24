#include "stm32f4xx.h"
#include "Utility.h"
			
Questão 5

int main(void){

	Configure_Clock(); //  Configura o sistema de clock
		Delay_Start();    // Inicializa as funções delay
		RCC->AHB1ENR |= 0x05;
		GPIOC->MODER |= 0x1;
		GPIOA->MODER |= 0x1000;
		while(1)
		{
			Delay_ms(1000);
			for (int i = 0 ; i < 4 ; i++)
			{
				GPIOA->BSRRL = 0x0040; // deixa asaida do pino 6 em 0 (acende)
				GPIOC->BSRRH = 0x0001; //deixa a saida do pino 0 em 1 (apita)
				Delay_ms(150);
				GPIOC->BSRRL = 0x0001; // deixa asaida do pino 0 em 0 (para de apitar)
				GPIOA->BSRRH = 0x0040; //deixa a saida do pino 6 em 1 (apaga)

				Delay_ms(150);
			}
		}
}
