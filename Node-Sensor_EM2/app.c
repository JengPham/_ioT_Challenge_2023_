#include "app.h"

void app_init(void)
{

  gpioSetup();
  uartInit();
  letimer0Init();
  iadcInit();

}

void app_process_action(void)
{

}


