/*
 * sysclk.h
 *
 * Created: 17.07.2018 08:16:40
 *  Author: Odin
 */ 


#ifndef SYSCLK_H_
#define SYSCLK_H_

#include <stdint.h>

#define SYSCLK ((Clk*)0x61)

typedef struct {
	volatile uint8_t CLKPR;
	volatile uint8_t RESERVED0[4];
	volatile uint8_t OSCCAL;
} Clk;

enum Prescaler {
	PRESCALER_DIVIDE_1,
	PRESCALER_DIVIDE_2,
	PRESCALER_DIVIDE_4,
	PRESCALER_DIVIDE_8,
	PRESCALER_DIVIDE_16,
	PRESCALER_DIVIDE_32,
	PRESCALER_DIVIDE_64,
	PRESCALER_DIVIDE_128,
	PRESCALER_DIVIDE_256	
};

void sysclk_setPrescaler(enum Prescaler prescaler);

#endif /* SYSCLK_H_ */