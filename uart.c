#include <avr/io.h>
void init_uart(void){
	DDRD |= 0b00001000;
	DDRD &= ~0b00000100;

	UCSR1A = 0b00000010;
	UCSR1B = 0b00011000;
	UCSR1C = 0b00000110;
	
	UBRR1H = 0;
	UBRR1L = 207;
}

void send_byte(char input){
	while(!(UCSR1A & 0b00100000));
	UDR1 = input;
}

void send_string(char * string){
	int i = 0;
	while(string[i] != 0){
		send_byte(string[i]);
		i ++;
	}
}
char read_byte(){
	if(UCSR1A & 0b10000000){
		return UDR1;
	}
	else{
		return 0;
	}
}
