/*
 * switch.h
 *
 * Created: 04-Mar-22 2:20:45 PM
 *  Author: ezz_a
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

void button_init(unsigned char portname, unsigned char pinnumber);
/*
Function Name: button_init
Function Description: The function intializes selected pin as input to the MC. (Based on DIO_vSetPinDir)
Function input: portname ==> port that connects the button to MC, pinnumber ==> pin that connects button to the MC.
Function return type: void
*/

unsigned char button_read(unsigned char portname, unsigned char pinnumber);
/*
Function Name: button_init
Function Description: The function reads input value from a button pin connected to the MC. (Based on DIO_u8read)
Function input: portname ==> port that connects the button to MC, pinnumber ==> pin that connects button to the MC.
Function return type: unsigned char
*/



#endif /* SWITCH_H_ */