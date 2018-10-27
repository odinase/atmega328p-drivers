/*
 * interrupt_handlers.h
 *
 * Created: 22.07.2018 09:54:46
 *  Author: Odin
 */ 


#ifndef INTERRUPT_HANDLERS_H_
#define INTERRUPT_HANDLERS_H_

void Default_Handler();

void (*PCINT0_Handler)();
void (*PCINT1_Handler)();
void (*PCINT2_Handler)();

void (*INT0_Handler)();
void (*INT1_Handler)();





#endif /* INTERRUPT_HANDLERS_H_ */