#include<avr/io.h>			//Include "io" header file from "avr" library for importing characteristics of microcontroller like DDRx, PORTx, Pinx, etc.
#include<util/delay.h>		//Include "delay" header file from "util" library for importing characteristics of time delay like milliseconds, etc.

void main()					//Void function doesn't return any values
{
DDRD = 0b00000000;			//Setting Part D as input part; "0b" is used to tell compiler that the following are binary digits
PORTD = 0b11111111;			//Pulling up all the pins of Part D
DDRB = 0b11111111;			//Setting Part B as output part

int pinD;

while(1)
	{
	pinD = PIND;
	
	if(pinD==0b11111111)			//No obstacle
		PORTB=0b00001010;			//Move forward
	
	if(pinD==0b11111110)			//Obstacle to the right
		PORTB=0b00000110;			//Turn left
	
	if(pinD==0b11111101)			//Obstacle at the center
		{
			PORTB=0b00000101;		//Go back and turn right
			_delay_ms(100);
			
			PORTB=0b00001001;
			_delay_ms(150);
		}
	
	if(pinD==0b11111001)			//Obstacle to the center and right
		{
			PORTB=0B00000101;		//Go back and turn left
			_delay_ms(100);
		
			PORTB=0b00000110;
			_delay_ms(150);
		}
	
	if(pinD==0b11111011)			//Obstacle to the left
		PORTB=0b00001001;			//Turn right
	
	if(pinD==0b11111010)			//Obstacle on both sides (right & left)
		{
			PORTB=0b00000101;		//Go back and turn right
			_delay_ms(100);
		
			PORTB=0b00001001;
			_delay_ms(250);
		}
	
	if(pinD=0b11111001)				//Obstacle to the center and left
		{
			PORTB=0b00000101;		//Go back and turn right
			_delay_ms(100);
		
			PORTB=0b00001001;
			_delay_ms(150);
		}
	
	if(pinD=0b11111000)				//Obstacle on all sides
		{
			PORTB=0b00000101;		//Take a U-Turn (i.e. prolonged right turn)
			_delay_ms(100);
			
			PORTB=0b00001001;
			_delay_ms(900);
		}
	}
}
	