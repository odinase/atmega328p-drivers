/*
 * pmc.h
 *
 * Created: 17.07.2018 09:22:18
 *  Author: Odin
 */ 


#ifndef PMC_H_
#define PMC_H_

#include <stdint.h>
#include <stdbool.h>

#define PMC ((Pmc*)0x53)

/* SMCR bits */
#define SE			0
#define SM0			1
#define SM1			2
#define SM2			3

/* PRR bits */
#define PRTWI		7
#define PRTIM2		6
#define PRTIM0		5
#define PRTIM1		3
#define PRSPI		2
#define PRUSART0	1
#define PRADC		0

typedef struct {
	volatile uint8_t SMCR; /* SMCR: Sets sleep mode of chip*/
	volatile uint8_t RESERVED0;
	volatile uint8_t MCUCR; /* MCU control register. Unsupported. */
	volatile uint8_t RESERVED1[15];
	volatile uint8_t PRR; /* PRR: Power */
} Pmc;

enum PeripheralModule {
	pmc_ADC			= 0,
	pmc_USART0		= 1,
	pmc_SPI			= 2,
	pmc_TIMER1		= 3,
	pmc_TIMER0		= 5,
	pmc_TIMER2		= 6,
	pmc_TWI			= 7
};

enum SleepMode {
	pmc_IDLE,
	pmc_ADC_NOISE_REDUCTION,
	pmc_POWER_DOWN,
	pmc_POWER_SAVE,
	pmc_STANDBY				= 6,
	pmc_EXTERNAL_STANDBY	= 7
};

void pmc_enablePeripheralClock(enum PeripheralModule peripheralModule);
void pmc_disablePeripheralClock(enum PeripheralModule peripheralModule);

void pmc_setSleepMode(enum SleepMode sleepMode);
void pmc_enableSleepMode();
void pmc_disableSleepMode();



#define sleep_cpu()                              \
do {                                             \
	__asm__ __volatile__ ( "sleep" "\n\t" :: );  \
} while(0)

#endif /* PMC_H_ */