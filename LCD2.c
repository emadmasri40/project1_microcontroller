#include "LCD.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "Delayms.c"
#define LCD_data(p) (GPIOB->DATA=p)

void LCD_init8bit(void)
{
    Port_Init(1);//initialization for port B
    Port_SetPinDirection(1,0xFF,PORT_PIN_OUT);
    Port_Init(0);//initialization for port A
    Port_SetPinDirection(0,0xE0,PORT_PIN_OUT);//SET PINS 5->RS & 6->RW & 7->Enable
    
    lcd_Cmd8bit(0x01);//clear fo screen
    delay_micro(390);
    lcd_Cmd8bit(0x30);//wake up
    delay_micro(390);
    lcd_Cmd8bit(0x38);//8-bits of data
    delay_micro(390);
    lcd_Cmd8bit(0x0F);//display on
    delay_micro(390);
    lcd_Cmd8bit(0X80);//start from right
    delay_micro(390);
}	



void lcd_Cmd4bit(char command)
{

    char f = command<<4;
    GPIOA->DATA=0;
    LCD_data(f);
    GPIOA->DATA=1<<7;
    delay_micro(100);  
    GPIOA->DATA=0<<7;
    delay_micro(50);
    LCD_data(command);
    GPIOA->DATA=1<<7;
    delay_micro(100);  
    GPIOA->DATA=0<<7;
	
}

