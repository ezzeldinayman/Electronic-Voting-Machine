/*
 * ElectronicVotingMachine.c
 *
 * Created: 04-Mar-22 11:29:07 AM
 *  Author: ezz_a
 */ 

#include "button.h"
#include "LCD.h"
#include "util/delay.h"

#define DISPLAY_ON_CURSOR_OFF 0x0C

void resetMachine(void)
//Function to reset the screen
{
	LCD_clearscreen();
	LCD_vSend_string("A=00");
	LCD_movecursor(2,1);
	LCD_vSend_string("B=00");
	LCD_movecursor(1,8);
	LCD_vSend_string("C=00");
	LCD_movecursor(2,8);
	LCD_vSend_string("D=00");
}


int main(void)
{
	//Buttons Initialization
	button_init('A',0);
	button_init('A',1);
	button_init('A',2);
	button_init('A',3);
	button_init('A',4);
	//LCD Initialization
	LCD_vInit();
	LCD_vSend_cmd(DISPLAY_ON_CURSOR_OFF);
	//the Units digit of Choices declaration
	char a=48;
	char b=48; 
	char c=48;
	char d=48;
	//The Tenth Digit of Choices declaration
	char a_a=48;
	char b_b=48;
	char c_c=48;
	char d_d=48;
	//Send Initial Data to the LCD
	resetMachine();
	
	//START OF THE EVM Code
    while(1)
    {
		//Reset Button Setup
		if(button_read('A',4)==1)
		{
			resetMachine();
			a = 48;
			b = 48;
			c = 48;
			d = 48;
			a_a=48;
			b_b=48;
			c_c=48;
			d_d=48;
		}
		//Voting for A Setup	
		if(button_read('A',0)==1)
		{
			LCD_movecursor(1,3);
			if((a-48)<9)
			{
				a++;
				LCD_vSend_char((char)a_a);
				LCD_vSend_char((char)a);
			}
			else
			{
				a=48;
				a_a++;
				LCD_vSend_char((char)a_a);
				LCD_vSend_char((char)a);
			}
			_delay_ms(250);
		}
		
		//Voting for B Setup
		if(button_read('A',1)==1)
		{
			LCD_movecursor(2,3);
			if((b-48)<9)
			{
				b++;
				LCD_vSend_char((char)b_b);
				LCD_vSend_char((char)b);
			}
			else
			{
				b=48;
				b_b++;
				LCD_vSend_char((char)b_b);
				LCD_vSend_char((char)b);
			}
			_delay_ms(250);
		}
		
		//Voting for C Setup
		if(button_read('A',2)==1)
		{
			LCD_movecursor(1,10);
			if((c-48)<9)
			{
				c++;
				LCD_vSend_char((char)c_c);
				LCD_vSend_char((char)c);
			}
			else
			{
				c=48;
				c_c++;
				LCD_vSend_char((char)c_c);
				LCD_vSend_char((char)c);
			}
			_delay_ms(250);
		}
		
		//Voting for D Setup
		if(button_read('A',3)==1)
		{
			LCD_movecursor(2,10);
			if((d-48)<9)
			{
				d++;
				LCD_vSend_char((char)d_d);
				LCD_vSend_char((char)d);
			}
			else
			{
				d=48;
				d_d++;
				LCD_vSend_char((char)d_d);
				LCD_vSend_char((char)d);
			}
			_delay_ms(250);
		}
		
    }
}
//End of MAIN CODE