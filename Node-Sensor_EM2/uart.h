/*
 * uart.h
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#ifndef UART_H_
#define UART_H_

#define TX_PORT             gpioPortA
#define TX_PIN              8
#define RX_PORT             gpioPortA
#define RX_PIN              4
#define VCOM_Enable_PORT    gpioPortB
#define VCOM_Enable_PIN     0
#define LoraPort   gpioPortC
#define LoraPin    6

#include "em_eusart.h"
#include "Letimer.h"
#include <stdio.h>

void uartInit(void);
void transmitData(unsigned char* dataArray, uint8_t length);
void uint16ToUnsignedCharArray(uint16_t number, unsigned char* array, int arraySize);
uint8_t calculateLrc(const unsigned char* array, int size);
void EUSART0_RX_IRQHandler(void);


#endif /* UART_H_ */
