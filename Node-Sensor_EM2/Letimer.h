/*
 * Letimer.h
 *
 *  Created on: Jun 19, 2023
 *      Author: PhongPham
 */

#ifndef LETIMER_H_
#define LETIMER_H_

#include "em_letimer.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "uart.h"
#include "DHT22.h"
#include "iadc.h"
#include "connect.h"


void letimer0Init(void);
void letimer0Enable(void);
void letimer0Disable(void);
void LETIMER0_IRQHandler(void);
void batteryLevel(uint8_t* count, uint16_t* battery);

extern char dataTransmit[21];
extern uint8_t interrupt;

#endif /* LETIMER_H_ */
