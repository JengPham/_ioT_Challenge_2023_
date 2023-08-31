#include "app.h"

void app_init(void)
{

  gpioInit();
  uartInit();
  while(1){
      /* Nhấn BUTTON_0 để kết nối tới Station */
      if(!GPIO_PinInGet(BUTTON0_PORT, BUTTON1_PIN)){
          connectToStation();
          break;
      }
  }

  letimer0Init();
  iadcInit();
  letimer0Enable();

}

void app_process_action(void)
{

}


