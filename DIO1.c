#include "DIO.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"

////////////***DIO***//////////////


uint8_t DIO_ReadPort(uint8_t port_index , uint8_t pins_mask )
{
	uint8_t pins_level ;
	switch(port_index)
	{
		case 0  : pins_level = GPIO_PORTA_DATA_R & pins_mask ;break; //port A
		case 1  : pins_level = GPIO_PORTB_DATA_R & pins_mask ;break; //port B
		case 2  : pins_level = GPIO_PORTC_DATA_R & pins_mask ;break; //port C
		case 3  : pins_level = GPIO_PORTD_DATA_R & pins_mask ;break; //port D
		case 4  : pins_level = GPIO_PORTE_DATA_R & pins_mask ;break; //port E 
		case 5  : pins_level = GPIO_PORTF_DATA_R & pins_mask ;break; //port F
	}			
	
	return pins_level;
}


