/*************************************************************************
 *
 * OrkMain.c
 * ORKWare Main Code Starter File
 * Library for use with 2011 OSURC Robotics Kit (ORK).
 *
 * Copyright (C) 2011 OSURC. Released under the GNU LGPL3.
 * http://oregonstate.edu/groups/osurc/
 *
 * Written by Cody Hyman <hymanc@onid.orst.edu>
 * Created 9/2/2011
 * Updated 10/9/2011
 *************************************************************************/

 //#define L298 1 //Uncomment this definition to use the L298 (Upgrade Motor Driver) motor driver code
 
#include "OrkLib/OrkCore.h"
#include "OrkLib/uart.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{	
	initializeCore(); // Initializes core ORK Functionality (motors, 
	setMotor(LeftMotor,128);
	setMotor(RightMotor,128);
	DDRB |= 1;


	//Set PORTB Pin 1 to be an output
	DDRB |= 0b00000001;

	while(1)
	{
		//Toggle PORTB Pin 1 every 1 second (blink LED)
		_delay_ms(1000);
		PORTB ^= 1;
	}
	return 0;
}
