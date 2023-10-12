/*
 * connect.h
 *
 *  Created on: Jul 21, 2023
 *      Author: PhongPham
 */

#ifndef CONNECT_H_
#define CONNECT_H_

#define LED0_PORT           gpioPortB
#define LED0_PIN            2
#define LED1_PORT           gpioPortB
#define LED1_PIN            4
#define BUTTON0_PORT        gpioPortB /*The Button 0 is designed to connect/disconnect the node to the station*/
#define BUTTON0_PIN         1
#define BUTTON1_PORT        gpioPortB /*Button 1 functions to start/stop the operation*/
#define BUTTON1_PIN         3

#include "uart.h"
#include "em_emu.h"

void gpioSetup(void);
void GPIO_ODD_IRQHandler(void);

#endif /* CONNECT_H_ */
