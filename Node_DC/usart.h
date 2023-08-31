/*
 * usart.h
 *
 *  Created on: Aug 26, 2023
 *      Author: jengp
 */

#ifndef USART_H_
#define USART_H_
#include "em_usart.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "Timer.h"

#define LED0_PORT    gpioPortB
#define LED0_PIN     2
#define LED1_PORT    gpioPortB
#define LED1_PIN     4
#define BUTTON0_PORT gpioPortB
#define BUTTON0_PIN  1
#define BUTTON1_PORT gpioPortB
#define BUTTON1_PIN  3
#define MOTOR1_PORT  gpioPortC
#define MOTOR1_PIN   9
#define MOTOR2_PORT  gpioPortC
#define MOTOR2_PIN   8
#define MOTOR3_PORT  gpioPortC
#define MOTOR3_PIN   6

void gpioInit(void);
void uartInit(void);
void transmitData(char* dataArray, uint8_t length);
char State(GPIO_Port_TypeDef port,unsigned int pin);
void transmitTheStateOfTheMotors(void);
void USART0_RX_IRQHandler(void);

extern char response[10];
extern char dataTransmit[11];

#endif /* USART_H_ */
