#include "stm32f4xx.h"
void SystemInit() {
		(*((int*)0xE000ED88))|=0x0F00000;
}

void delayy(){
	int dummy=0xFFFFFF;
	while(dummy--);
}

void delay2(){
	int dummy=0xFFFF;
	while(dummy--);
}

int main (){
	unsigned char disp[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	
	int tim = 0;

	RCC->AHB1ENR = 0x3F; //1010, Port B and Port D are clocked
	GPIOE->MODER = 0x00005555;// 0101 0101 0101 0101
	GPIOB->MODER = 0x00000055;
	
	
	
	while(1){
		
			GPIOB->ODR = 1 << 1;		
			GPIOE->ODR =   disp[count1];
			delay2();
		
			GPIOB->ODR = 1 << 0;
			GPIOE->ODR =   disp[count2];
			delay2();
		
		tim++;
		
		if(tim > 31){	

			tim = 0;
			
			if(count1 <= 9)
			{
				count1++;
			}
			else
			{
				count1 = 0;
				count2++;
				
				if(count2 > 9){
					count2 = 0;
					count1 = 0;
					count3++;
				}
			}
		}
		

		
	
		}
	
}