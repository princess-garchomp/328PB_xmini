#include <avr/io.h>
#include "I_O.h"

/*
int main(void) {
	DDRD |=(1ul<<PD0)|(1ul<<PD1)|(1ul<<PD2);
	while(1){
		PORTD |=(1ul<<PD2)|(1ul<<PD1)|(1ul<<PD2);
	}
}

*/

/*
int main(void)
//https://microchipdeveloper.com/8avr:digital-i-o-on-avr
//solution explorer->rightclick PB_two->properties
//tool->medgb...->debugwire
//debug-> start without debug
{
	DDRB |= 1<<DDRB5;    // Direction of pin PB5 set as Output
	while (1)
	{
		if (PINB & (1<<PINB7))    //read PIN PB7
		{
			PORTB &= ~(1<<PORTB5);    // PB7 is low so LED On
		}
		else
		{
			PORTB |= 1<<PORTB5;    // By default PB7 is high, LED Off
		}
	}
}
*/
/*
//use on board button to make pC5 output high on push
int main(void)
{
	DDRC |= (1ul<<PC5);    // Direction of pin PB5 set as Output
	while (1)
	{
		if (PINB & (1ul<<PINB7))    //read PIN PB7
		{		
			PORTC &= ~(1ul<<PB5);    // PB7 is low so LED On				PORTB5
		}
		else
		{
			PORTC |= (1ul<<PB5);    // By default PB7 is high, LED Off		PORTB5
		}
	}
}*/

int main(void)
{
	all_I_O_config();
	DDRC |= (1ul<<PC5);    // Direction of pin PB5 set as Output
	while (1)
	{
		if((!(PINB & (1ul<<PINB7)))&&button_is_pressed())
		{
			first_rgb_led_color(BLUE); 
		}
		else if(button_is_pressed())
		{
			first_rgb_led_color(RED);
		}
		else if (!(PINB & (1ul<<PINB7)))    //read PIN PB7
		{
			first_rgb_led_color(GREEN);
		}
		else
		{
			first_rgb_led_color(WHITE);
		}
	}
}