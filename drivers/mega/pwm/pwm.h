/*
 * pwm.h
 *
 * Created: 02.07.2018 00:01:43
 *  Author: Odin
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <stdint.h>


void pwm_init();

void pwm_setPrescalerAndStartTimer(uint16_t prescaler);

void pwm_setDutyCycle(float dutyCycle);

void pwm_interruptRoutine();

#endif /* PWM_H_ */