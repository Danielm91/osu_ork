#include <avr/io.h>
void init_pwm1(void){
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000100;
	DDRB |= 0b10000000;
}

void set_pwm1(uint8_t pulse_width){
	OCR0A = pulse_width;
}
