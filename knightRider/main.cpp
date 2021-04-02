/*
 * main.cpp
 *
 *  Created on: Mar 29, 2021
 *      Author: root
 */




#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= 0xFF; 					// set all pins of PORT B as output
	for(int i=0;i<3;i++)			// Flash all leds 3x
	{
		PORTB = 0xFF;				// ON all leds
		_delay_ms(100);
		PORTB = 0x00;				// OFF all leds
		_delay_ms(100);
	}

	_delay_ms(100);

	int dir = 1;
	PORTB = 0x03;
	while(1){						// knight rider effect with two leds on
		_delay_ms(100);
		if(PORTB == 0x60){ 			// till 0x40 to not use the built-in led
			dir = 0;
		}
		else if (PORTB == 0x03){
			dir = 1;
		}

		if(dir){
			PORTB += PORTB;  		// light next led
		}else{
			PORTB -= (PORTB >> 1); 	// light previous led
		}
	}
}
