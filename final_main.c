#include "stdio.h"
#include "Delayms.c"
#include "TM4C123.h" 
#include <string.h>
#include <stdlib.h>
#include "sandy.c"
#define unlock 0x4C4F434B;
#include "tm4c123gh6pm.h"
//#define RS(s) (GPIOA->DATA=((s)?(GPIOA->DATA|0x20):((GPIOA->DATA)&~(0x20))))  // connect to pinA0
//#define EN(E) (GPIOA->DATA=((E)?(GPIOA->DATA|0x80):((GPIOA->DATA)&~(0x80))))  // connect to pin A1
#define LCD_data(p) (GPIOB->DATA=p)

                   

///////***port***///////////

void SystemInit(){}



///////*** LCD*** /////////////

void lcd_comand(char x )

{
	GPIOA->DATA=0;
	LCD_data(x);
	GPIOA->DATA=1<<7;
  delay_micro(100);  
  GPIOA->DATA=0<<7;
	
}


void LCD_init(void)
{
	Port_Init(1);//initialization for port B
			Port_SetPinDirection(1,0xFF,OUT);
			Port_Init(0);//initialization for port A
			Port_SetPinDirection(0,0xE0,OUT);//SET PINS 5->RS & 6->RW & 7->Enable
			
			lcd_comand(0x01);//clear fo screen
			delay_micro(390);
			lcd_comand(0x30);//wake up
			delay_micro(390);
			lcd_comand(0x38);//8-bits of data
			delay_micro(390);
			lcd_comand(0x0F);//display on
			delay_micro(390);
			lcd_comand(0X80);//start from right
			delay_micro(390);
	    lcd_comand(0XC0);//start from right
			delay_micro(390);

}	




void lcd_send(char x[])
{ int i = 0; 
	lcd_comand(0x01);//clear fo screen
	delay_micro(390);
	while(x[i] != '\0' )
	{
	 GPIOA->DATA|=1<<5;
	 GPIOA->DATA|=1<<7;
   LCD_data(x[i++]);
	 delay_micro(390);  // delay to toggle
	 GPIOA->DATA=0<<7;  // E high
	 delay_micro(390); 
	}
	
	
}
	
int main(void)
{
	    char reset[3]="000";
	    char K[3];
      int i=-1;
			int f = 0 ;
			int y = 0 ;
	   	LCD_init();
	    Port_Init(4);
      Port_SetPinDirection(4 ,0x0E,IN);
      Port_SetPinPullUp(4,0x0E,1);
	lcd_send("Sixth Fleet G39");
	
	 while(1)
	 {
		 if((GPIOE->DATA &0x02)==0 &&i<1000)
		   { i++;
				 sprintf(K,"%d",i);
			   lcd_send(K);
				 delay_milli(200);
		   }
			if((GPIOE->DATA &0x04)==0&&i>0&&(f==0))
		   { f=1;
				 i--;
				 delay_milli(170);
				 sprintf(K,"%d",i);

			   lcd_send(K);				 
		   }
      if(GPIOE->DATA &0x04)
			{
				f=0;
			}				
			if((GPIOE->DATA &0x08)== 0)
			{
				y = 1;
			}
			
			if((GPIOE->DATA &0x08) && y) 
      {  y = 0 ;
				 i = 0 ;
				 delay_milli(170);
			   lcd_send(reset);
			}
   }
	
}
