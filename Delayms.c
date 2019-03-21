#define CTRL_R     ((*((volatile unsigned long *)0xE000E010))&0x10000)
#include "TM4C123.h"

void delay_milli(int Dm){

	while(Dm!=0){
		SysTick->LOAD=16000-1;
		SysTick->VAL=0;
		SysTick->CTRL=5;
		while(CTRL_R==0 );
		SysTick->CTRL=1<<16;
		Dm-=1;
	}
}

void delay_micro(int Dm){

	while(Dm!=0){	
		SysTick->LOAD=16-1;
		SysTick->VAL=0;
		SysTick->CTRL=5;
		while(CTRL_R==0 );
		SysTick->CTRL=1<<16;
		Dm-=1;
	}
}
	
		
	