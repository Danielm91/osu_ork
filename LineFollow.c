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

#define OUTER_LEFT !(PINF & (1 << 5))
#define INNER_LEFT !(PINB & (1 << 4))
#define INNER_RIGHT !(PIND & (1 << 6))
#define OUTER_RIGHT !(PIND & (1 << 4))

int main(void)
{	
	initializeCore(); // Initializes core ORK Functionality (motors, 
	setMotor(LeftMotor,100);
	setMotor(RightMotor,100);


	//Set PORTB Pin 1 to be an output
	DDRB |= 0b00000001;

	while(1)
	{
		if(!(OUTER_LEFT) && (INNER_LEFT) && (INNER_RIGHT) && !(OUTER_RIGHT)){
			setMotor(LeftMotor,100);
			setMotor(RightMotor,100);
		}
		else if(!(OUTER_LEFT) && !(INNER_LEFT) && (INNER_RIGHT) && !(OUTER_RIGHT)){
			setMotor(LeftMotor,125);
			setMotor(RightMotor,50);
		}
		else if(!(OUTER_LEFT) && !(INNER_LEFT) && (INNER_RIGHT) && (OUTER_RIGHT)){
			setMotor(LeftMotor,125);
			setMotor(RightMotor,25);
}
		else if(!(OUTER_LEFT) && (INNER_LEFT) && !(INNER_RIGHT) && !(OUTER_RIGHT)){
			setMotor(LeftMotor,50);
			setMotor(RightMotor,125);
}
		else if((OUTER_LEFT) && (INNER_LEFT) && !(INNER_RIGHT) && !(OUTER_RIGHT)){
			setMotor(LeftMotor,25);
			setMotor(RightMotor,125);

}
else if(!(OUTER_LEFT) && !(INNER_LEFT) && !(INNER_RIGHT) && (OUTER_RIGHT)){
			setMotor(LeftMotor,125);
			setMotor(RightMotor,20);
}
else if((OUTER_LEFT) && !(INNER_LEFT) && !(INNER_RIGHT) && !(OUTER_RIGHT)){
			setMotor(LeftMotor,20);
			setMotor(RightMotor,125);
}

		
	}
	return 0;
}
