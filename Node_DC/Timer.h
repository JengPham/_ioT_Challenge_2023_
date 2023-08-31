/*
 * Timer.h
 *
 *  Created on: Aug 27, 2023
 *      Author: jengp
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "em_timer.h"
#include "em_cmu.h"
#include "usart.h"
void TIMER1Init(void);
void TIMER1Enable(void);
void TIMER1Disable(void);
void TIMER1_IRQHandler(void);

extern uint16_t count;
extern uint8_t T1;
extern uint8_t T2;
extern uint8_t T3;

#endif /* TIMER_H_ */
