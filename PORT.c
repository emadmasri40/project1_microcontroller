#ifndef PORT_H   /* Include guard */
#define PORT_H
#include <tm4c123gh6pm.h>
#define unlock 0x4C4F434B 
typedef unsigned char     uint8_t;

enum Port_PinDirectionType {PORT_PIN_IN = 0, PORT_PIN_OUT = 1};
void Port_Init(uint8_t port_index)
{
	SYSCTL->RCGCGPIO|= 1<port_index ;
switch (port_index){
	case 0 : {GPIOA->LOCK=unlock ; GPIOA->DEN=0x7f;  }
	case 1 : {GPIOB->LOCK=unlock ; GPIOB->DEN=0x7f;  }
	case 2 : {GPIOC->LOCK=unlock ; GPIOC->DEN=0x7f;  }
	case 3 : {GPIOD->LOCK=unlock ; GPIOD->DEN=0x7f;  }
  case 4 : {GPIOE->LOCK=unlock ; GPIOE->DEN=0x7f;  }
	case 5 : {GPIOF->LOCK=unlock ; GPIOF->DEN=0x7f;  }	
}
}
void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, uint8_t  pins_direction)
{

switch (port_index){
	case 0 : {GPIOA->DIR= (pins_direction)?(GPIOA->DIR|pins_mask):(GPIOA->DIR&~(pins_mask)) ; }
	case 1 : {GPIOB->DIR= (pins_direction)?(GPIOB->DIR|pins_mask):(GPIOB->DIR&~(pins_mask)) ; }
	case 2 : {GPIOC->DIR= (pins_direction)?(GPIOC->DIR|pins_mask):(GPIOC->DIR&~(pins_mask)) ;  }
	case 3 : {GPIOD->DIR= (pins_direction)?(GPIOD->DIR|pins_mask):(GPIOD->DIR&~(pins_mask)) ;  }
  case 4 : {GPIOE->DIR= (pins_direction)?(GPIOE->DIR|pins_mask):(GPIOE->DIR&~(pins_mask)) ; }
	case 5 : {GPIOF->DIR= (pins_direction)?(GPIOF->DIR|pins_mask):(GPIOF->DIR&~(pins_mask)) ;  }	
}
}
void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{
switch (port_index){
	case 0 : {GPIOA->PUR= (enable)? pins_mask:0 ; }
	case 1 : {GPIOB->PUR= (enable)? pins_mask:0 ; }
	case 2 : {GPIOC->PUR= (enable)? pins_mask:0 ; }
	case 3 : {GPIOD->PUR= (enable)? pins_mask:0 ; }
  case 4 : {GPIOE->PUR= (enable)? pins_mask:0 ; }
	case 5 : {GPIOF->PUR= (enable)? pins_mask:0 ; }	
}
}
void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{
switch (port_index){
	case 0 : {GPIOA->PDR= (enable)? pins_mask:0 ; }
	case 1 : {GPIOB->PDR= (enable)? pins_mask:0 ; }
	case 2 : {GPIOC->PDR= (enable)? pins_mask:0 ; }
	case 3 : {GPIOD->PDR= (enable)? pins_mask:0 ; }
    case 4 : {GPIOE->PDR= (enable)? pins_mask:0 ; }
	case 5 : {GPIOF->PDR= (enable)? pins_mask:0 ; }	
}
}
#endif // PORT_H