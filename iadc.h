/*
 * adc.h
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#ifndef IADC_H_
#define IADC_H_

#include "em_iadc.h"
#include "em_cmu.h"
#include <string.h>
#include "uart.h"

void iadcInit(void);
void iadcStartsingle(void);
uint16_t getMoisture(void);



#endif /* IADC_H_ */
