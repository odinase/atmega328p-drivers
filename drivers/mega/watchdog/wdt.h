/*
 * wdt.h
 *
 * Created: 19.07.2018 01:39:43
 *  Author: Odin
 */ 


#ifndef WDT_H_
#define WDT_H_

#define WDT ((Wdt*)0x54)

typedef struct {
	volatile uint8_t MCUSR;
	volatile uint8_t RESERVED0[5];
	volatile uint8_t WDTCSR;
} Wdt;

enum WatchdogMode {
	STOPPED,
	INTERRUPT_MODE,
	SYSTEM_RESET_MODE,
	INTERRUPT_AND_SYSTEM_RESET_MODE	
};

enum WatchdogPrescaler {
	WDT_CYCLES_2K,
	WDT_CYCLES_4K,
	WDT_CYCLES_8K,
	WDT_CYCLES_16K,
	WDT_CYCLES_32K,
	WDT_CYCLES_64K,
	WDT_CYCLES_128K,
	WDT_CYCLES_256K,
	WDT_CYCLES_512K,
	WDT_CYCLES_1024K
};

void wdt_enableInterrupt(void (*callbackFunction)(void));
void wdt_disableInterrupt();
void wdt_setWatchdogMode(enum WatchdogMode watchdogMode);
void wdt_setWatchdogPrescaler(enum WatchdogPrescaler watchdogPrescaler);


#endif /* WDT_H_ */