#ifndef APP_H
#define APP_H

#include "iadc.h"
#include "uart.h"
#include "Letimer.h"
#include "connect.h"

void app_init(void);
void app_process_action(void);

#endif
