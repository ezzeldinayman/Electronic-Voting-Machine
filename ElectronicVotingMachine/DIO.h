/*
 * DIO.h
 *
 * Created: 04-Mar-22 8:33:27 PM
 *  Author: ezz_a
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "std_macros.h"

void DIO_vSetPinDir(unsigned char portname,unsigned char pinnumber,unsigned char direction);
//Sets pin data direction (direction 1 = output pin / direction 0 = input pin) (DDRx)
void DIO_vWrite(unsigned char portname, unsigned char pinnumber, unsigned char val);
//Write an output on a pin (val=1 LOGIC HIGH, val=0 LOGIC LOW) (PORTx)
void DIO_vToggle(unsigned char portname, unsigned char pinnumber);
//Toggles Digital output on an output pin.
unsigned char DIO_u8read(unsigned char portname, unsigned char pinnumber);
//reads input on a pin (PINx)
void DIO_vSETPORTDir(unsigned char portname, unsigned char direction);
//sets a whole port as a an output port (direction 1) or input port (direction 0) 
void DIO_vWritePORT(unsigned char portname, unsigned char val);
//writes Digital value on an output WHOLE Port (LOGIC HIGH OR LOW)
void DIO_vTOGPORT(unsigned char portname);
//Toggles value on a whole output port
unsigned char DIO_u8ReadPort(unsigned char portname);
//reads value written on whole input port (PINx)

void DIO_vWriteHighNibble(unsigned char portname, unsigned char val);
void DIO_vWriteLowNibble(unsigned char portname, unsigned char val);
void DIO_vEnablePullUp(unsigned char portname, unsigned char pinnumber,unsigned char en);
#endif /* DIO_H_ */