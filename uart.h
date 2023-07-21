/*
 * uart.h
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#ifndef UART_H_
#define UART_H_

#include "em_usart.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void uartInit(void);
void transmitData(char* dataArray, uint8_t length);
void insertStringAtBeginning(char* inputArray, char* outputArray, char* stringToInsert);
void concatenateArrays(const char* a, const char* b, const char* c, const char* d, char* sum);
void uint16ToCharArray(uint16_t number, char* array, int arraySize);
uint16_t calculateChecksum(const char* array, int size);

#endif /* UART_H_ */
