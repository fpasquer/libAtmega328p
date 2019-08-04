#include "../incs/libArduino.h"

static void					setDigitalWrite(const unsigned char reg,
	const t_status status,
	unsigned char *var)
{
	if (status == HIGH)
		(*var) |= reg;
	else if (status == LOW)
		(*var) &= ~reg;
}

void						libDigitalWrite(const t_pins pin, const t_status status)
{
	t_mappingAtmega328pToArduino
						mapping[DIGITAL_PIN_NUMBER] = {
			{.pin = LIB_PIN0, .reg = 0x1, .var = PORTD},
			{.pin = LIB_PIN1, .reg = 0x2, .var = PORTD},
			{.pin = LIB_PIN2, .reg = 0x4, .var = PORTD},
			{.pin = LIB_PIN3, .reg = 0x8, .var = PORTD},
			{.pin = LIB_PIN4, .reg = 0x10, .var = PORTD},
			{.pin = LIB_PIN5, .reg = 0x20, .var = PORTD},
			{.pin = LIB_PIN6, .reg = 0x40, .var = PORTD},
			{.pin = LIB_PIN7, .reg = 0x80, .var = PORTD},
			{.pin = LIB_PIN8, .reg = 0x1, .var = PORTB},
			{.pin = LIB_PIN9, .reg = 0x2, .var = PORTB},
			{.pin = LIB_PIN10, .reg = 0x4, .var = PORTB},
			{.pin = LIB_PIN11, .reg = 0x8, .var = PORTB},
			{.pin = LIB_PIN12, .reg = 0x10, .var = PORTB},
			{.pin = LIB_PIN13, .reg = 0x20, .var = PORTB},
		};
	unsigned int		i;

	for (i = 0; i < DIGITAL_PIN_NUMBER; i++)
		if (mapping[i].pin == pin)
			return setDigitalWrite(mapping[i].reg, status, &mapping[i].var);
}
