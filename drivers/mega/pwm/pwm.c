/*
 * pwm.c
 *
 * Created: 02.07.2018 00:01:27
 *  Author: Odin
 */ 

#include "pwm.h"

/* Sets non-inverting on 0A (pin PD6) and Fast-PWM */
void pwm_init() {
	
}

/* Starts the timer */
void pwm_setPrescalerAndStartTimer(uint16_t prescaler) {
	
}

/* Sets duty cycle for 8-bit timer (must be between 0 and 255) */
void pwm_setDutyCycle(float dutyCycle) {
	if (dutyCycle < 0)
	{
		dutyCycle = 0;
	}
	if (dutyCycle > 100)
	{
		dutyCycle = 100;
	}
}

void pwm_interruptRoutine() {
	//dutyCycle++;
}

