#include "stm32f4xx.h"

void SystemInit() {
		(*((int*)0xE000ED88))|=0x0F00000;
}

	

void delayy_microsec(int micro){
	int dummy=4*micro;
	while(dummy--);
}


int main (){
	unsigned char disp[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  int count1 = 0;
	int count2 = 1;
	RCC->AHB1ENR = 0xA; //1010, Port B and Port D are clocked
	GPIOD->MODER = 0x00005555;
	GPIOB->MODER = 0x00000055;
	
	//for(count1=0;count1<10;count1++)
	//delayy();
  //for(count2=0;count2<10;count2++)
	//delayy();
	
	while(1){
	  	
		GPIOB->ODR = (1<<1);
		GPIOD->ODR = disp[count1];
	 
		GPIOB->ODR = (1<<0);
		GPIOD->ODR = disp[count2];	
		
		//if (count1)
   // {
   //   GPIOB->ODR ^= (1<<9);            // toggle green LED
   //   count1 = 0;
   // }
   // if (count2)
   // {
   //   GPIOD->ODR ^= (1<<8);            // toggle blue LED
     // count2 = 0;
	
		//}		
	}
	
}
