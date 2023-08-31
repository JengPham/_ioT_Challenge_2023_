/*
 * uart.h
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#ifndef UART_H_
#define UART_H_

#include "em_eusart.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "Letimer.h"
#include <stdio.h>
#include <string.h>

void gpioInit(void);
void uartInit(void);
void transmitData(char* dataArray, uint8_t length);
void uint16ToCharArray(uint16_t number, char* array, int arraySize);
uint8_t calculateLrc(const char* array, int size);
void EUSART1_RX_IRQHandler(void);

extern char response[10];

#endif /* UART_H_ */
