/*
 * switch.c
 *
 * Created: 04-Mar-22 2:20:31 PM
 *  Author: ezz_a
 */ 

#include "DIO.h"


void button_init(unsigned char portname, unsigned char pinnumber)
{
	DIO_vSetPinDir(portname,pinnumber,0);
}

unsigned char button_read(unsigned char portname, unsigned char pinnumber)
{
	return DIO_u8read(portname,pinnumber);
}


