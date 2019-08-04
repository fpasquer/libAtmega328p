#ifndef LIB_ARDUINO_H

# define F_CPU 16000000UL
# define __DELAY_BACKWARD_COMPATIBLE__

# include </usr/local/CrossPack-AVR/avr/include/avr/io.h>
# include <util/delay.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define DIGITAL_PIN_NUMBER 14

typedef enum				e_status
{
	LOW = false,
	HIGH = true
}							t_status;

typedef enum				e_pinMode
{
	INPUT = 0,
	OUTPUT = 1
}							t_pinMode;

typedef enum				e_pins
{
	LIB_PIN0,
	LIB_PIN1,
	LIB_PIN2,
	LIB_PIN3,
	LIB_PIN4,
	LIB_PIN5,
	LIB_PIN6,
	LIB_PIN7,
	LIB_PIN8,
	LIB_PIN9,
	LIB_PIN10,
	LIB_PIN11,
	LIB_PIN12,
	LIB_PIN13
}							t_pins;

typedef struct				s_mappingAtmega328pToArduino
{
	const t_pins			pin;
	const unsigned char		reg;
	unsigned char			*var;
}							t_mappingAtmega328pToArduino;

void						libPinMode(const t_pins pin, const t_pinMode mode);
t_status					libDigitalRead(t_pins pin);
void						libDelay(const unsigned long ms);
void						libDigitalWrite(const t_pins pin, const t_status status);

#endif
