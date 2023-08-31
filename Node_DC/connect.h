/*
 * connect.h
 *
 *  Created on: Aug 26, 2023
 *      Author: jengp
 */

#ifndef CONNECT_H_
#define CONNECT_H_

#include "usart.h"
#include "em_emu.h"
#include "ustimer.h"

void connectToStation(void);
extern char address[5];

#endif /* CONNECT_H_ */
