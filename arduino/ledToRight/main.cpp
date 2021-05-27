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
	for(int i=0;i<3;i++)
	{
		PORTB |= 0xFF;				// ON all leds
		_delay_ms(100);
		PORTB &= ~(0xFF);			// OFF all leds
		_delay_ms(100);
	}

	_delay_ms(100);

	int dir = 1;
	int MASK = 0x01;
	while(1){
		_delay_ms(100);
		if(PORTB == 0x7F){ 			// till 0x7F to not use the built-in led
			dir = 0;
		}
		else if (PORTB == 0x00){
			dir = 1;
			PORTB |= 0x01;
			MASK = 0x01;
		}

		if(dir){
			PORTB |= (PORTB << 1);  // increase byte
		}else{
			PORTB &= ~MASK;			// bitwise and with inverse mask > insert 0 on the right
			MASK |= (MASK << 1);    // increase mask
		}
	}
}
