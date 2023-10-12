/*
 * uart.c
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#include "uart.h"

unsigned char response[10];
extern uint8_t connect;

void uartInit(void){

  /* Select LFXO for the EUSART0 */
  CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;
  CMU_LFXOInit(&lfxoInit);
  CMU_ClockSelectSet(cmuClock_EUSART0, cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_EUSART0, true);

  GPIO_PinModeSet(TX_PORT, TX_PIN, gpioModePushPull, 1); /*F6*/
  GPIO_PinModeSet(RX_PORT, RX_PIN, gpioModeInput, 0);    /*F3*/
  GPIO_PinModeSet(VCOM_Enable_PORT, VCOM_Enable_PIN, gpioModePushPull, 1); /* VCOM enable*/

  EUSART_UartInit_TypeDef init = EUSART_UART_INIT_DEFAULT_LF;
  GPIO->EUSARTROUTE[0].TXROUTE = (TX_PORT << _GPIO_EUSART_TXROUTE_PORT_SHIFT)
      | (TX_PIN << _GPIO_EUSART_TXROUTE_PIN_SHIFT);
  GPIO->EUSARTROUTE[0].RXROUTE = (RX_PORT << _GPIO_EUSART_RXROUTE_PORT_SHIFT)
      | (RX_PIN << _GPIO_EUSART_RXROUTE_PIN_SHIFT);

  GPIO->EUSARTROUTE[0].ROUTEEN = GPIO_EUSART_ROUTEEN_RXPEN | GPIO_EUSART_ROUTEEN_TXPEN;

  EUSART_UartInitLf(EUSART0, &init);

  NVIC_ClearPendingIRQ(EUSART0_RX_IRQn);
  NVIC_EnableIRQ(EUSART0_RX_IRQn);

}

uint8_t j = 0;
void EUSART0_RX_IRQHandler(void)
{

  response[j] = EUSART0->RXDATA;
  if ((response[j] != 'E')){
      j++;
  }
  else {
      /*Handling the response data when sending sensor data to the station*/
      if (j == 1){
          if (response[0] == '1'){
              EUSART_IntDisable(EUSART0, EUSART_IEN_RXFL);
          }
          else if (response[0] == '0'){
              transmitData(dataTransmit, sizeof(dataTransmit));
              EUSART_IntDisable(EUSART0, EUSART_IEN_RXFL);
          }
          j = 0;
          interrupt = 0;
      }
      /*Handling the response data when sending connection data to the station*/
      else if (j==4 && response[0] == '1' && response[1] == '1'){
              /*The case where the station agrees to establish a connection*/
              letimer0Disable(); /* Dừng Timer xử lý sự kiện kết nối */
              dataTransmit[0] = response[2]; dataTransmit[1] = response[3];
              GPIO_PinOutToggle(LED0_PORT, LED0_PIN); /* Bật LED0 (3s): Thông báo kết nối thành công */
              USTIMER_Init();
              USTIMER_DelayIntSafe(3000000);
              GPIO_PinOutToggle(LED0_PORT, LED0_PIN);
              USTIMER_DeInit();
              interrupt = 0;
              connect = 1;
      }

      else if(j==2 && response[0] == '1' && response[1] == '0'){
          /*The case where the station does not agree to establish a connection*/
              letimer0Disable();/* Dừng Timer xử lý sự kiện kết nối */
              GPIO_PinOutToggle(LED1_PORT, LED1_PIN); /* Bật LED1 (3s): Thông báo kết nối không thành công */
              USTIMER_Init();
              USTIMER_DelayIntSafe(3000000);
              USTIMER_DeInit();
              GPIO_PinOutToggle(LED1_PORT, LED1_PIN);
              interrupt = 0;
      }

      else j = 0;

  }
  EUSART_IntClear(EUSART0, EUSART_IF_RXFL);

}

void transmitData(unsigned char* dataArray, uint8_t length)
{
  GPIO_PinOutSet(LoraPort, LoraPin);
  for (uint8_t i = 0; i < length; i++)
  {
      EUSART_Tx(EUSART0, dataArray[i]);
  }
  GPIO_PinOutClear(LoraPort, LoraPin);
}


void uint16ToUnsignedCharArray(uint16_t number, unsigned char* array, int arraySize) {
    snprintf((char*)array, arraySize, "%03u", number);
}

uint8_t calculateLrc(const unsigned char* array, int size) {
    uint8_t lrc = 0;
    for (int i = 0; i < size; i++) {
        lrc ^= array[i];
    }
    return lrc;
}


















