#include "stdint.h"
#include "C:/Keil_v5/Labware/inc/tm4c123gh6pm.h"
#define zero 0x3F
#define one	0x06
#define two  0x5B
#define three 0x4F
#define four 0x66
#define five 0x6D
#define six 0x7D
#define seven 0x07
#define eigth 0x7F
#define nine 0x6F

enum Port_PinDirectionType{
		PORT_PIN_IN,PORT_PIN_OUT
};//default value of the first element is zero and the secound is one



void delay(int n);
void Port_Init();

void delay(int n){
	int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<3180;j++)
		{};
}


void Port_Init(int port_index){
			switch(port_index){
			case'0':{//portA 
				uint32_t delay;
				SYSCTL_RCGCGPIO_R=0X01;//enable port A 
				delay=1;			
				GPIO_PORTA_LOCK_R=0X4C4F434B;
				GPIO_PORTA_DEN_R=0XFF;
			};
			case'1':{//port B 
				uint32_t delay;
				SYSCTL_RCGCGPIO_R=0X02;//enable port  B
				delay=1;
				GPIO_PORTB_LOCK_R=0X4C4F434B;
				GPIO_PORTB_DEN_R=0XFF;
					}
			case'2':{//port c 
				uint32_t delay;
				SYSCTL_RCGCGPIO_R=0X04;//enable port C
				delay=1;
				GPIO_PORTC_LOCK_R=0X4C4F434B;
				GPIO_PORTC_DEN_R=0XFF;
			};
			case'3':{//port D 
				uint32_t delay;
				SYSCTL_RCGCGPIO_R=0X08;//enable port D
				delay=1;
				GPIO_PORTD_LOCK_R=0X4C4F434B;
				GPIO_PORTD_DEN_R=0XFF;
			};
			case'4':{//port E 
				uint32_t delay;
				SYSCTL_RCGCGPIO_R=0X10;//enable port E
				delay=1;			
				GPIO_PORTE_LOCK_R=0X4C4F434B;
				GPIO_PORTE_DEN_R=0XF;
			};
			case'5':{//port F 
				uint32_t delay;
				SYSCTL_RCGCGPIO_R=0X20;//enable port F
				delay=1;
				GPIO_PORTF_LOCK_R=0X4C4F434B;
				GPIO_PORTF_DEN_R=0XFF;
			}
		}
};

void Port_SetPinDirection(int port_index,int pins_mask,enum Port_PinDirectionType pins_direction){
	switch(port_index){
		case'0':{ if(pins_direction)
								GPIO_PORTA_DATA_R &=pins_mask;
							else
								GPIO_PORTA_DATA_R |=pins_mask;
						}
		case'1':{ if(pins_direction)
								GPIO_PORTB_DATA_R &=pins_mask;
							else
								GPIO_PORTB_DATA_R |=pins_mask;
						}
		case'2':{ if(pins_direction)
							GPIO_PORTC_DATA_R &=pins_mask;
						else
							GPIO_PORTC_DATA_R |=pins_mask;
					}
		case'3':{ if(pins_direction)
							GPIO_PORTD_DATA_R &=pins_mask;
						else
							GPIO_PORTD_DATA_R |=pins_mask;
					}
		case'4':{ if(pins_direction)
							GPIO_PORTE_DATA_R &=pins_mask;
						else
							GPIO_PORTE_DATA_R |=pins_mask;
					}
		case'5':{ if(pins_direction)
							GPIO_PORTF_DATA_R &=pins_mask;
						else
							GPIO_PORTF_DATA_R |=pins_mask;
					}	
}	};

void Port_SetPinPullUp(int port_index,int pins_mask,int enable){
	switch(port_index){
		case'0':{ if(enable)
								GPIO_PORTA_PUR_R &=pins_mask;
							else
								GPIO_PORTA_PUR_R |=pins_mask;
						}
		case'1':{ if(enable)
								GPIO_PORTB_PUR_R &=pins_mask;
							else
								GPIO_PORTB_PUR_R |=pins_mask;
						}
		case'2':{ if(enable)
							GPIO_PORTC_PUR_R &=pins_mask;
						else
							GPIO_PORTC_PUR_R |=pins_mask;
					}
		case'3':{ if(enable)
							GPIO_PORTD_PUR_R &=pins_mask;
						else
							GPIO_PORTD_PUR_R |=pins_mask;
					}
		case'4':{ if(enable)
							GPIO_PORTE_PUR_R &=pins_mask;
						else
							GPIO_PORTE_PUR_R |=pins_mask;
					}
		case'5':{ if(enable)
							GPIO_PORTF_PUR_R &=pins_mask;
						else
							GPIO_PORTF_PUR_R |=pins_mask;
					}	
}	};



void Port_SetPinPullDown(int port_index,int pins_mask,int enable){
	switch(port_index){
		case'0':{ if(enable)
								GPIO_PORTA_PDR_R &=pins_mask;
							else
								GPIO_PORTA_PDR_R |=pins_mask;
						}
		case'1':{ if(enable)
								GPIO_PORTB_PDR_R &=pins_mask;
							else
								GPIO_PORTB_PDR_R |=pins_mask;
						}
		case'2':{ if(enable)
							GPIO_PORTC_PDR_R &=pins_mask;
						else
							GPIO_PORTC_PDR_R |=pins_mask;
					}
		case'3':{ if(enable)
							GPIO_PORTD_PDR_R &=pins_mask;
						else
							GPIO_PORTD_PDR_R |=pins_mask;
					}
		case'4':{ if(enable)
							GPIO_PORTE_PDR_R &=pins_mask;
						else
							GPIO_PORTE_PDR_R |=pins_mask;
					}
		case'5':{ if(enable)
							GPIO_PORTF_PDR_R &=pins_mask;
						else
							GPIO_PORTF_PDR_R |=pins_mask;
					}	
}	};








int main(void){
unsigned char arr[] =
{zero, one , two ,three ,four, five, six, seven, eigth, nine};
int i;
Port_Init(i);			
while(1){
			
				
		}
}


