/*
 * pio.c
 *
 * Created: 12.07.2018 23:43:25
 *  Author: Odin
 */ 

#include "../pmc/pmc.h"
#include "../../interrupt_handlers/interrupt_handlers.h"
#include <avr/interrupt.h>
#include "pio.h"

static inline bool pio_isOutput(Pio * pio, enum Pin pin);
static inline bool pio_isInput(Pio * pio, enum Pin pin);

void pio_init()
{
	PCINT0_Handler = Default_Handler;
	PCINT1_Handler = Default_Handler;
	PCINT2_Handler = Default_Handler;
	
	INT0_Handler = Default_Handler;
	INT1_Handler = Default_Handler;
}

void pio_enableOutput(Pio * pio, enum Pin pin)
{
	pio->DDR |=  (1 << pin);	
};

void pio_disableOutput(Pio * pio, enum Pin pin)
{
	pio->DDR &= ~(1 << pin);
};

void pio_toggleOutput(Pio * pio, enum Pin pin)
{
	if (pio_isOutput(pio, pin))
	{
		pio->PIN |= (1 << pin);
	}
};

void pio_setOutput(Pio * pio, enum Pin pin, enum PinLevel level)
{
	if (pio_isOutput(pio, pin))
	{
		switch (level)
		{
			case PIN_LOW:
				pio->PORT &= ~(1 << pin);
				break;
			case PIN_HIGH:
				pio->PORT |= (1 << pin);
				break;
			default: break;
		}
	}
};

void pio_enablePullUp(Pio * pio, enum Pin pin)
{
	if (pio_isInput(pio, pin))
	{
		pio->PORT |= (1 << pin);
	}
};

void pio_disablePullUp(Pio * pio, enum Pin pin)
{
	if (pio_isInput(pio, pin))
	{
		pio->PORT &= ~(1 << pin);
	}
};

bool pio_readPin(Pio * pio, enum Pin pin)
{
	return pio->PIN & (1 << pin);
};

void pio_enablePinChangeInterrupt(enum PcintPin pin)
{
	PCINT->PCICR
};

static inline bool pio_isOutput(Pio * pio, enum Pin pin)
{
	return pio->DDR & (1 << pin);
};

static inline bool pio_isInput(Pio * pio, enum Pin pin)
{
	return !pio_isOutput(pio, pin);
};

ISR(PCINT0_vect)
{
	PCINT0_Handler();
}

ISR(PCINT1_vect)
{
	PCINT1_Handler();
}

ISR(PCINT2_vect)
{
	PCINT2_Handler();
}

ISR(INT0_vect)
{
	INT0_Handler();
}

ISR(INT1_vect)
{
	INT1_Handler();
}