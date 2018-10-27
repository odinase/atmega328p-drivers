/*
 * pmc.c
 *
 * Created: 17.07.2018 09:22:04
 *  Author: Odin
 */ 

#include "pmc.h"


void pmc_enablePeripheralClock(enum PeripheralModule peripheralModule)
{
	switch (peripheralModule) {
		case pmc_ADC:
			PMC->PRR &= ~(1 << PRADC);
			break;
		case pmc_USART0:
			PMC->PRR &= ~(1 << PRUSART0);
			break;
		case pmc_SPI:
			PMC->PRR &= ~(1 << PRSPI);
			break;
		case pmc_TIMER0:
			PMC->PRR &= ~(1 << PRTIM0);
			break;
		case pmc_TIMER1:
			PMC->PRR &= ~(1 << PRTIM1);
			break;
		case pmc_TIMER2:
			PMC->PRR &= ~(1 << PRTIM2);
			break;
		case pmc_TWI:
			PMC->PRR &= ~(1 << PRTWI);
			break;
		default: break;
	}
};


void pmc_disablePeripheralClock(enum PeripheralModule peripheralModule)
{
	switch (peripheralModule) {
		case pmc_ADC:
			PMC->PRR |= (1 << PRADC);
			break;
		case pmc_USART0:
			PMC->PRR |= (1 << PRUSART0);
			break;
		case pmc_SPI:
			PMC->PRR |= (1 << PRSPI);
			break;
		case pmc_TIMER0:
			PMC->PRR |= (1 << PRTIM0);
			break;
		case pmc_TIMER1:
			PMC->PRR |= (1 << PRTIM1);
			break;
		case pmc_TIMER2:
			PMC->PRR |= (1 << PRTIM2);
			break;
		case pmc_TWI:
			PMC->PRR |= (1 << PRTWI);
			break;
		default: break;
	}	
}

void pmc_enableSleepMode()
{
	PMC->SMCR |= 1 << SE;
}

void pmc_disableSleepMode()
{
	PMC->SMCR &= ~( 1 << SE );
}

void pmc_setSleepMode(enum SleepMode sleepMode)
{
	switch (sleepMode) {
		case pmc_IDLE:
			PMC->SMCR &= ~( (1 << SM0 ) | ( 1 << SM1 ) | ( 1 << SM2 ));
			break;
		case pmc_ADC_NOISE_REDUCTION:
			PMC->SMCR = (PMC->SMCR & ~(( 1 << SM1 ) | ( 1 << SM2 ))) | ( 1 << SM0 );
			break;
		case pmc_POWER_DOWN:
			PMC->SMCR = (PMC->SMCR & ~(( 1 << SM0 ) | ( 1 << SM2 ))) | ( 1 << SM1 );
			break;
		case pmc_POWER_SAVE:
			PMC->SMCR = (PMC->SMCR & ~( 1 << SM2 ) ) | ( 1 << SM1 ) | ( 1 << SM0 );
			break;
		case pmc_STANDBY:
			PMC->SMCR = (PMC->SMCR & ~( 1 << SM0 )) | (1 << SM1 ) | ( 1 << SM2 );
			break;
		case pmc_EXTERNAL_STANDBY:
			PMC->SMCR |= ( 1 << SM0 ) | ( 1 << SM1 ) | ( 1 << SM2 );
			break;
		default: break;
	}
}

