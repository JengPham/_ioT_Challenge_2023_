/*
 * connect.c
 *
 *  Created on: Jul 21, 2023
 *      Author: PhongPham
 *
 */

#include "connect.h"

uint8_t work = 0;
uint8_t connect;

void gpioSetup(void){

  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(LED1_PORT, LED1_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(LoraPort, LoraPin, gpioModePushPull, 0);
  GPIO_PinModeSet(MoisturePort, MoisturePin, gpioModePushPull, 0);

  /*Configure Button PB0 as input and enable interrupt*/
  GPIO_PinModeSet(BUTTON0_PORT, BUTTON0_PIN, gpioModeInputPull, 1);
  GPIO_ExtIntConfig(BUTTON0_PORT,
                    BUTTON0_PIN,
                    BUTTON0_PIN,
                    false,
                    true,
                    true);

  /*Configure Button PB1 as input and enable interrupt*/
  GPIO_PinModeSet(BUTTON1_PORT, BUTTON1_PIN, gpioModeInputPull, 1);
  GPIO_ExtIntConfig(BUTTON1_PORT,
                    BUTTON1_PIN,
                    BUTTON1_PIN,
                    false,
                    true,
                    true);

  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
}


void GPIO_ODD_IRQHandler(void)
{

  uint32_t interruptMask = GPIO_IntGet();
  GPIO_IntClear(interruptMask);

  /*Check Button 0, if Button 0 is pressed, proceed with connecting to the station*/
  if (interruptMask & (1 << BUTTON0_PIN))
  {
    connect = 0;
    LETIMER_Reset(LETIMER0);
    letimer0Init();
    if(work==1) {
        work = 0;
        GPIO_PinOutClear(LED1_PORT, LED1_PIN);
    }
    unsigned char dataToConnect[] = {0xFF, 0xFF, 0x17, '1', 0x01, 0x03, 'E'};
    transmitData(dataToConnect, sizeof(dataToConnect));
    EUSART_IntEnable(EUSART0, EUSART_IEN_RXFL); /*Enable EUSART0 interrupt to receive connection data from the station*/
    letimer0Enable(); /*Enable the timer to handle the connection event*/

  }

  /*Check Button 1, if Button 1 is pressed, proceed to start or stop the operation*/
  else if (interruptMask & (1 << BUTTON1_PIN))
  {
      if(work == 0 && connect == 1){
          letimer0Enable();
          work = 1;
          GPIO_PinOutSet(LED1_PORT, LED1_PIN);
      }
      else if(work == 1 && connect == 1){
          letimer0Disable();
          work = 0;
          GPIO_PinOutClear(LED1_PORT, LED1_PIN);
      }
  }
}



