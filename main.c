#include "stdio.h"
#include "Delayms.c"
#include "TM4C123.h" 
#include <string.h>
#include <stdlib.h>
#include "DIO.h"
#include "PORT.h"
#include "LCD.h"
#define unlock 0x4C4F434B;
#include "tm4c123gh6pm.h"

int main(void){

    char K[3];
    int i=-1;
    int f=0;
    LCD_init8bit();
    Port_Init(5);
    Port_SetPinDirection(5 ,0x11,PORT_PIN_IN);
    Port_SetPinPullUp(5,0x11,1);
    
    while(1){
        
        // UP
        if((GPIOF->DATA & 0x01)==0 && i<1000){
            i++;
            delay_milli(600);
            sprintf(K,"%d",i);
            delay_milli(100);
            LCD_Send8bit(K);
        }

        // Down
        if((GPIOF->DATA & 0x10)==0 && i>0 && (f==0)){ 
            f = 1;
            i--;
            delay_milli(600);
            sprintf(K,"%d",i);
            delay_milli(100);
            LCD_Send8bit(K);				 
        }

        // RESET
        if(GPIOF->DATA & 0x10)  f=0;			
   }
	
}
