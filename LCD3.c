#include "LCD.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "Delayms.c"
#define LCD_data(p) (GPIOB->DATA=p)

void LCD_init4bit(void)
{
    Port_Init(1);//initialization for port B
    Port_SetPinDirection(1,0xFF,PORT_PIN_OUT);
    Port_Init(0);//initialization for port A
    Port_SetPinDirection(0,0xE0,PORT_PIN_OUT);//SET PINS 5->RS & 6->RW & 7->Enable
    
    lcd_Cmd4bit(0x01);//clear fo screen
    delay_micro(390);
    lcd_Cmd4bit(0x30);//wake up
    delay_micro(390);
    lcd_Cmd4bit(0x38);//8-bits of data
    delay_micro(390);
    lcd_Cmd4bit(0x0F);//display on
    delay_micro(390);
    lcd_Cmd4bit(0X80);//start from right
    delay_micro(390);
}	



void LCD_Send4bit(char x[]){
    
    int  i = 0;
	char F ; 
	
    lcd_Cmd4bit(0x01);//clear fo screen
	delay_micro(390);
	
    while(x[i] != '\0' ){

        F= x[i]<<4;
        GPIOA->DATA|=1<<5;
        GPIOA->DATA|=1<<7;
        LCD_data(F);
        delay_micro(390);  // delay to toggle
        GPIOA->DATA=0<<7;  // E high
        delay_micro(39); 
        GPIOA->DATA|=1<<7;
        LCD_data(x[i]);
        delay_micro(39);  // delay to toggle
        GPIOA->DATA=0<<7;  // E high
        delay_micro(390); 
        i++;
	}	
}

