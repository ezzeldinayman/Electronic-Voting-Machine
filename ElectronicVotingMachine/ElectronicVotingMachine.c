/*
 * ElectronicVotingMachine.c
 *
 * Created: 04-Mar-22 11:29:07 AM
 *  Author: ezz_a
 */ 

#include "button.h"
#include "LCD.h"
#include "util/delay.h"
#define F_CPU 

#define DISPLAY_ON_CURSOR_OFF 0x0C

void resetMachine(void)
//Function to reset the screen
{
	LCD_clearscreen();
	LCD_vSend_string("A=0");
	LCD_movecursor(2,1);
	LCD_vSend_string("B=0");
	LCD_movecursor(1,8);
	LCD_vSend_string("C=0");
	LCD_movecursor(2,8);
	LCD_vSend_string("D=0");
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
	char a=0;
	char b=0; 
	char c=0;
	char d=0;

	//Send Initial Data to the LCD
	resetMachine();
	
	//START OF THE EVM Code
    while(1)
    {
		//Reset Button Setup
		if(button_read('A',4)==1)
		{
			resetMachine();
			a = 0;
			b = 0;
			c = 0;
			d = 0;
			/*
			a_a=48;
			b_b=48;
			c_c=48;
			d_d=48;
			*/
		}
		//Voting for A Setup	
		if(button_read('A',0)==1)
		{
			LCD_movecursor(1,3);
			if(a<9)
			{
				a++;
				/*LCD_vSend_char((char)a_a);*/
				LCD_vSend_char(a+48);
			}
			else
			{
				/*
				a=48;
				a_a++;
				*/
				a++;
				LCD_vSend_char(a/10 + 48);
				LCD_vSend_char(a%10 + 48);
			}
		}
		
		//Voting for B Setup
		if(button_read('A',1)==1)
		{
			LCD_movecursor(2,3);
			if(b<9)
			{
				b++;
				//LCD_vSend_char((char)b_b);
				LCD_vSend_char(b+48);
			}
			else
			{
				/*
				b=48;
				b_b++;
				*/
				//LCD_vSend_char((char)b_b);
				b++;
				LCD_vSend_char(b/10 + 48);
				LCD_vSend_char(b%10 + 48);
			}
			
		}
		
		//Voting for C Setup
		if(button_read('A',2)==1)
		{
			LCD_movecursor(1,10);
			if(c<9)
			{
				c++;
				//LCD_vSend_char((char)c_c);
				LCD_vSend_char(c+48);
			}
			else
			{
				/*
				b=48;
				b_b++;
				*/
				c++;
				LCD_vSend_char(c/10 + 48);
				LCD_vSend_char(c%10 + 48);
			}
			
		}
		
		//Voting for D Setup
		if(button_read('A',3)==1)
		{
			LCD_movecursor(2,10);
			if(d<9)
			{
				d++;
				//LCD_vSend_char((char)d_d);
				LCD_vSend_char(d+48);
			}
			else
			{
				/*
				d=48;
				d_d++;
				*/
				d++;
				LCD_vSend_char(d/10 + 48);
				LCD_vSend_char(d%10 + 48);
			}
			
		}
		_delay_ms(200);
		
    }
}
//End of MAIN CODE