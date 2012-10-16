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
	init_uart();
	DDRB |= 1;

	char ir[] = {0,0,0,0};
	char string[20];

	DDRB |= 0b00000001;
	PORTB |= 0b00000001;

	/*
	* Write other initialization code here (i.e. setting a pin data direction with a DDRx)
	*/
	while(1)
	{
		_delay_ms(1000);
		PORTB ^= 1;

		if(PINF & 0b00100000){
			ir[0] = 1;
		}
		else{
			ir[0] = 0;
		}
		if(PINB & 0b00010000){
			ir[1] = 1;
		}
		else{
			ir[1] = 0;
		}
		if(PIND & 0b01000000){
			ir[2] = 1;
		}
		else{
			ir[2] = 0;
		}
		if(PIND & 0b00010000){
			ir[3] = 1;
		}
		else{
			ir[3] = 0;
		}
		sprintf(string, "%d %d %d %d\n\r", ir[0], ir[1], ir[2], ir[3]);
		send_string(string);

		//send_byte('a');

		/*
		//Demo program that drives the ORK in alternating circles
		//Uncomment and compile this code to run. (Remote the /* and * / at the end of this block.
		setMotor(LeftMotor,128); //Sets the left motor to full forwardspeed
		setMotor(RightMotor,-128); //Sets the right motor to full  reverse speed
		delay(1000); //1000ms delay
		setMotor(LeftMotor,-128);
		setMotor(RightMotor,128);
		delay(1000);
		*/
		
		/*
		//Demo program that reads a line sensor connected to CON1 or CON4 and spins the nearest motor if
		//a line is detected. 
		//To test a line sensor, run this code and cover up the sensor with your finger to make the motor spin
		//Uncomment and compile this code to run. (Remote the /* and * / at the end of this block.
		if(readDigitalPin(CON1) //CON1 will be true (1) if it detects a black line, (0) if not
		{
			setMotor(RightMotor,128); //Right motor is set to full forward
			ledOn();
		}
		else
		{
			setMotor(RightMotor,0); //Right motor is stopped
			ledOff();
		}
		if(readDigitalPin(CON4)
		{
			setMotor(LeftMotor,128);
		}
		else
		{
			setMotor(LeftMotor,0); //Left Motor is stopped
		}
		*/
		
		/*
		*	Write your main loop code here
		*	This infinite loop will continue executing until the ORK is shut off
		*/
		
		/*
		* End of the Main Loop
		*/
	}
	return 0;
}
