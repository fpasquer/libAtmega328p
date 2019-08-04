#include "../incs/libArduino.h"

t_status				libDigitalRead(t_pins pin)
{
	if (pin > 0)
		return HIGH;
	return LOW;
}
