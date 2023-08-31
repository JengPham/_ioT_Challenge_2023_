/*
 * uart.c
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#include "usart.h"

void gpioInit(void){
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(BUTTON0_PORT, BUTTON0_PIN, gpioModeInput, 1);
  GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(LED1_PORT, LED1_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(MOTOR1_PORT, MOTOR1_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(MOTOR2_PORT, MOTOR2_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(MOTOR3_PORT, MOTOR3_PIN, gpioModePushPull, 0);
}

void uartInit(void){
  CMU_ClockEnable(cmuClock_USART0, true);

  GPIO_PinModeSet(gpioPortA, 8, gpioModePushPull, 0); /*TX*/ /*F6*/
  GPIO_PinModeSet(gpioPortA, 9, gpioModeInput, 0); /*RX - 4*/ /*F3*/
  GPIO_PinModeSet(gpioPortB, 0, gpioModePushPull, 1);  /* VCOM enable */

  USART_InitAsync_TypeDef uartinit = USART_INITASYNC_DEFAULT;
  uartinit.baudrate = 115200;

  GPIO->USARTROUTE[0].TXROUTE = (gpioPortA << _GPIO_USART_TXROUTE_PORT_SHIFT)
      | (8 << _GPIO_USART_TXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].RXROUTE = (gpioPortA << _GPIO_USART_RXROUTE_PORT_SHIFT)
      | (9 << _GPIO_USART_RXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].ROUTEEN = GPIO_USART_ROUTEEN_RXPEN | GPIO_USART_ROUTEEN_TXPEN;

  USART_InitAsync(USART0, &uartinit);

  NVIC_ClearPendingIRQ(USART0_RX_IRQn);
  NVIC_EnableIRQ(USART0_RX_IRQn);

}

void transmitData(char* dataArray, uint8_t length)
{
  for (uint8_t i = 0; i < length; i++)
  {
    USART_Tx(USART0, dataArray[i]);

  }
}

char State(GPIO_Port_TypeDef port,unsigned int pin)
{
  if(GPIO_PinOutGet(port, pin))
  return '1';
  else return '0';
}

void transmitTheStateOfTheMotors(void){
  dataTransmit[4] = State(MOTOR1_PORT, MOTOR1_PIN);
  dataTransmit[5] = State(MOTOR2_PORT, MOTOR2_PIN);
  dataTransmit[6] = State(MOTOR3_PORT, MOTOR3_PIN);
  transmitData(dataTransmit, sizeof(dataTransmit));
}

uint8_t j = 0;
void USART0_RX_IRQHandler(void){

  response[j] = USART0->RXDATA;
    if ((response[j] != 'E')){
        j++;
    }
    else {
        if ( j == 6 ){
            TIMER1Init();
            TIMER_IntDisable(TIMER1, TIMER_IEN_OF);
            TIMER1Disable();
            if(response[0] == '1'){
               GPIO_PinOutSet(MOTOR1_PORT, MOTOR1_PIN);
                }
            else GPIO_PinOutClear(MOTOR1_PORT, MOTOR1_PIN);

            if(response[1] == '1'){
               GPIO_PinOutSet(MOTOR2_PORT, MOTOR2_PIN);
                }
            else GPIO_PinOutClear(MOTOR2_PORT, MOTOR2_PIN);

            if(response[2] == '1'){
               GPIO_PinOutSet(MOTOR3_PORT, MOTOR3_PIN);
                }
            else GPIO_PinOutClear(MOTOR3_PORT, MOTOR3_PIN);

            if(response[3]!=0 || response[4]!=0 || response[5]!= 0){
                T1 = response[3];
                T2 = response[4];
                T3 = response[5];
                TIMER_IntEnable(TIMER1, TIMER_IEN_OF);
                TIMER1Enable();
            }
            j = 0;
        }
        else j = 0;

    }
}
















