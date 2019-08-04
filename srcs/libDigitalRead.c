#include "../incs/libArduino.h"

t_status				readDigitalArduino(const unsigned char reg,
	unsigned char *var)
/**
 *	DESCRIPTION :
 *		Read the bit reg in the varible var.
 *	PARAMS :
 *		reg => the bit in PIN you want to read
 *		var => Global from io.h. Can be PINB  or PIND
 *	RETURN :
 *		HIGH | LOW
 * */
{
	return (((*var) & reg) != 0 ? HIGH : LOW);
}

t_status				libDigitalRead(const t_pins pin)
/**
 *	DESCRIPTION :
 *		Reads the value from a specified digital pin, either HIGH or LOW.
 *	PARAMS :
 *		pin => Arduino pin you want to read
 *	RETURN :
 *		HIGH | LOW
 * */
{
	const t_mappingAtmega328pToArduino
						mapping[DIGITAL_PIN_NUMBER] = {
			{.pin = LIB_PIN0, .reg = 0x1, .var = (unsigned char*)&PIND},
			{.pin = LIB_PIN1, .reg = 0x2, .var = (unsigned char*)&PIND},
			{.pin = LIB_PIN2, .reg = 0x4, .var = (unsigned char*)&PIND},
			{.pin = LIB_PIN3, .reg = 0x8, .var = (unsigned char*)&PIND},
			{.pin = LIB_PIN4, .reg = 0x10, .var = (unsigned char*)&PIND},
			{.pin = LIB_PIN5, .reg = 0x20, .var = (unsigned char*)&PIND},
			{.pin = LIB_PIN6, .reg = 0x40, .var = (unsigned char*)&PIND},
			{.pin = LIB_PIN7, .reg = 0x80, .var = (unsigned char*)&PIND},
			{.pin = LIB_PIN8, .reg = 0x1, .var = (unsigned char*)&PINB},
			{.pin = LIB_PIN9, .reg = 0x2, .var = (unsigned char*)&PINB},
			{.pin = LIB_PIN10, .reg = 0x4, .var = (unsigned char*)&PINB},
			{.pin = LIB_PIN11, .reg = 0x8, .var = (unsigned char*)&PINB},
			{.pin = LIB_PIN12, .reg = 0x10, .var = (unsigned char*)&PINB},
			{.pin = LIB_PIN13, .reg = 0x20, .var = (unsigned char*)&PINB},
		};
	unsigned int		i;

	for (i = 0; i < DIGITAL_PIN_NUMBER; i++)
		if (mapping[i].pin == pin)
			return readDigitalArduino(mapping[i].reg, mapping[i].var);

	return (LOW);
}
