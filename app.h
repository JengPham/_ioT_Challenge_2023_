

#ifndef APP_H
#define APP_H

#define LED0_PORT gpioPortB
#define LED0_PIN  2
#define LED1_PORT gpioPortB
#define LED1_PIN  4

#include "iadc.h"
#include "uart.h"
#include "Letimer.h"
#include "connect.h"

void app_init(void);
void app_process_action(void);

#endif
