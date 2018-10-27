/*
 * pio.h
 *
 * Created: 12.07.2018 23:43:38
 *  Author: Odin
 */ 


#ifndef PIO_H_
#define PIO_H_

#include <stdbool.h>
#include <stdint.h>

/* Remove unwanted definitions */
#ifdef EIFR
#undef EIFR
#endif

#ifdef EIMSK
#undef EIMSK
#endif

#ifdef EICRA
#undef EICRA
#endif

#ifdef INT0
#undef INT0
#endif

#ifdef INT1
#undef INT1
#endif


#ifdef PCIFR
#undef PCIFR
#endif

#ifdef PCICR
#undef PCICR
#endif

#ifdef PCMSK0
#undef PCMSK0
#endif

#ifdef PCMSK1
#undef PCMSK1
#endif

#ifdef PCMSK2
#undef PCMSK2
#endif

/* PIO registers */
#define PIOB ((Pio*)0x23)
#define PIOC ((Pio*)0x26)
#define PIOD ((Pio*)0x29)

/* External Interrupt registers */
#define INT ((Exint*)0x3C)

/* Pin Change Interrupt registers */
#define PCINT ((Pcint*)0x3B)


/* EICRA bits */
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

/* EIMSK bits */
#define INT0E	0
#define INT1E	1

/* EIFR bits */
#define INTF0	0
#define INTF1	1

/* PCICR bits */
#define PCIE2	2
#define PCIE1	1
#define PCIE0	0

/* PCIFR bits */
#define PCIF2	2
#define PCIF1	1
#define PCIF0	0

/* Pcint Pins */
enum PcintPin {
	PCINT_0 = 0,
	PCINT_1,
	PCINT_2,
	PCINT_3,
	PCINT_4,
	PCINT_5,
	PCINT_6,
	PCINT_7,
	PCINT_8 = 0,
	PCINT_9,
	PCINT_10,
	PCINT_11,
	PCINT_12,
	PCINT_13,
	PCINT_14,
	PCINT_16 = 0,
	PCINT_17,
	PCINT_18,
	PCINT_19,
	PCINT_20,
	PCINT_21,
	PCINT_22,
	PCINT_23
};

/* Pins */
enum Pin {
	PIN_0	= 0,
	PIN_1	= 1,
	PIN_2	= 2,
	PIN_3	= 3,
	PIN_4	= 4,
	PIN_5	= 5,
	PIN_6	= 6,
	PIN_7	= 7
};

enum PinLevel {
	PIN_LOW,
	PIN_HIGH
};

enum InterruptType {
	LOW_LEVEL,
	LOGIC_CHANGE,
	FALLING_EDGE, 
	RISING_EDGE	 
};

enum ExternalIntteruptPin {
	INT0,
	INT1	
};

typedef struct {
	volatile uint8_t PIN;	/* PIN:  Sets value on pin, regardless of DDR													 */
	volatile uint8_t DDR;	/* DDR:  Sets direction on pin. 1 for input, 0 for output.										 */
	volatile uint8_t PORT;	/* PORT: Sets value on pin, dependent on DDR. High or low for output, pullup on or off for input */	
} Pio;

typedef struct {
	volatile uint8_t EIFR;
	volatile uint8_t EIMSK;
	volatile uint8_t RESERVED[43];
	volatile uint8_t EICRA;	
} Exint;

typedef struct {
	volatile uint8_t PCIFR; /* PCIFR: Pin Change Interrupt Flag Register */
	volatile uint8_t RESERVED0[44];
	volatile uint8_t PCICR; /* PCICR: Pin Change Interrupt Control Register. Enables PCINTx */
	volatile uint8_t RESERVED1[2];
	volatile uint8_t PCMSK0;
	volatile uint8_t PCMSK1;
	volatile uint8_t PCMSK2;
} Pcint;

void pio_init();

void pio_enableOutput(Pio * pio, enum Pin pin);
void pio_disableOutput(Pio * pio, enum Pin pin);
void pio_toggleOutput(Pio * pio, enum Pin pin);
void pio_setOutput(Pio * pio, enum Pin pin, enum PinLevel level);

void pio_enablePullUp(Pio * pio, enum Pin pin);
void pio_disablePullUp(Pio * pio, enum Pin pin);

bool pio_readPin(Pio * pio, enum Pin pin);

/**

 PIOB = PCINT[7:0], 
 PIOC = PCINT[14:8], 
 PIOD = PCINT[23:16] 
 
*/
void pio_enablePinChangeInterrupt(enum PcintPin pin);
void pio_disablePinChangeInterrupt(enum PcintPin pin);
void pio_setPinChangeInterruptCallbackFunction(enum PcintPin pin, void (*callbackFunction)(void));

void pio_enableExternalInterrupt(enum ExternalIntteruptPin externalInterruptPin, enum InterruptType interruptType, void (*callbackFunction)(void));
void pio_disableExternalInterrupt(enum ExternalIntteruptPin externalInterruptPin);


#endif /* PIO_H_ */