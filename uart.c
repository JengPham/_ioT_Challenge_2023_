/*
 * uart.c
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#include "uart.h"

void uartInit(void){
  CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_USART0, true);

  GPIO_PinModeSet(gpioPortA, 8, gpioModePushPull, 0); /*TX*/ /*F6*/
  GPIO_PinModeSet(gpioPortA, 4, gpioModeInput, 0); /*RX - 4*/ /*F3*/
  GPIO_PinModeSet(gpioPortB, 0, gpioModePushPull, 1);  /* VCOM */

  USART_InitAsync_TypeDef uartinit = USART_INITASYNC_DEFAULT;
  uartinit.baudrate = 9600;

  GPIO->USARTROUTE[0].TXROUTE = (gpioPortA << _GPIO_USART_TXROUTE_PORT_SHIFT)
      | (8 << _GPIO_USART_TXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].RXROUTE = (gpioPortA << _GPIO_USART_RXROUTE_PORT_SHIFT)
      | (4 << _GPIO_USART_RXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].ROUTEEN = GPIO_USART_ROUTEEN_RXPEN | GPIO_USART_ROUTEEN_TXPEN;

  USART_InitAsync(USART0, &uartinit);

}

void transmitData(char* dataArray, uint8_t length)
{
  for (uint8_t i = 0; i < length; i++)
  {
    USART_Tx(USART0, dataArray[i]);

  }
}

void data(const char* data_sensor, char* Data) {
    for (uint8_t i = 0, j = 0; i < 20; i += 2, j++) {
        char asciiData[3] = { data_sensor[i], data_sensor[i + 1], '\0' };
        Data[j] = (char)atoi(asciiData);
    }
}

void insertStringAtBeginning(char* inputArray, char* outputArray, char* stringToInsert)
{
    strcpy(outputArray, stringToInsert);
    strcat(outputArray, inputArray);
}

void concatenateArrays(const char* a, const char* b, const char* c, const char* d, char* sum)
{
    strcpy(sum, a);
    strcat(sum, b);
    strcat(sum, c);
    strcat(sum, d);
}

void uint16ToCharArray(uint16_t number, char* array, int arraySize) {
    snprintf(array, arraySize, "%03u", number);
}

uint16_t calculateChecksum(const char* array, int size) {
    uint16_t checksum = 0;

    for (int i = 0; i < size; i++) {
        checksum ^= array[i];
    }
    return checksum;
}



















