/*
 * adc.h
 *
 *  Created on: Jun 10, 2023
 *      Author: PhongPham
 */

#ifndef IADC_H_
#define IADC_H_

#define MoisturePort   gpioPortC
#define MoisturePin    4

#include "em_iadc.h"
#include "em_cmu.h"
#include "uart.h"


void iadcInit(void);
uint16_t getMoisture(void);

#endif /* IADC_H_ */
