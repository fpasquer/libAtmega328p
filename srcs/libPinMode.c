#include "../incs/libArduino.h"

static void				setPinMode(const unsigned char reg,
	const t_pinMode mode,
	unsigned char *var)
/**
 *	DESCRIPTION :
 *		Set register of ddr to specified mode
 *	PARAMS :
 *		reg => the bit of ddr
 *		mode => OUTPUT|INPUT
 *		var => constant form io.h
 * */
{
	if (mode == INPUT)
		(*var) &= ~reg;
	else if (mode == OUTPUT)
		(*var) |= reg;
}

void					libPinMode(const t_pins pin,
	const t_pinMode mode)
/**
 *	DESCRIPTION : 
 *		Configures the specified pin to behave either as an input or an output.
 *	PARAMS :
 *		pin => Arduino pin you want to set up
 *		mode => OUTPUT|INPUT
 *	RETURN :
 *		void
 * */
{
	t_mappingAtmega328pToArduino
						mapping[DIGITAL_PIN_NUMBER] = {
			{.pin = LIB_PIN0, .reg = 0x1, .var = DDRD},
			{.pin = LIB_PIN1, .reg = 0x2, .var = DDRD},
			{.pin = LIB_PIN2, .reg = 0x4, .var = DDRD},
			{.pin = LIB_PIN3, .reg = 0x8, .var = DDRD},
			{.pin = LIB_PIN4, .reg = 0x10, .var = DDRD},
			{.pin = LIB_PIN5, .reg = 0x20, .var = DDRD},
			{.pin = LIB_PIN6, .reg = 0x40, .var = DDRD},
			{.pin = LIB_PIN7, .reg = 0x80, .var = DDRD},
			{.pin = LIB_PIN8, .reg = 0x1, .var = DDRB},
			{.pin = LIB_PIN9, .reg = 0x2, .var = DDRB},
			{.pin = LIB_PIN10, .reg = 0x4, .var = DDRB},
			{.pin = LIB_PIN11, .reg = 0x8, .var = DDRB},
			{.pin = LIB_PIN12, .reg = 0x10, .var = DDRB},
			{.pin = LIB_PIN13, .reg = 0x20, .var = DDRB},
		};
	unsigned int		i;

	for (i = 0; i < DIGITAL_PIN_NUMBER; i++)
		if (mapping[i].pin == pin)
			return setPinMode(mapping[i].reg, mode, &mapping[i].var);
}
