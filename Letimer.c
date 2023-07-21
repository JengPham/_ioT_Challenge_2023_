/*
 * Letimer.c
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#include "Letimer.h"

#define Time_underflow   10  /* 10s */
extern char address[6];

uint16_t battery = 100;
uint8_t count = 0;

void letimer0Init(void){

  CMU_ClockEnable(cmuClock_LETIMER0, true);
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;
  letimerInit.enable = false;

  LETIMER_Init(LETIMER0, &letimerInit);
  LETIMER_IntClear(LETIMER0, _LETIMER_IF_MASK);
  LETIMER_TopSet(LETIMER0, CMU_ClockFreqGet(cmuClock_LETIMER0) / 1 * Time_underflow);

  LETIMER_IntEnable(LETIMER0, LETIMER_IEN_UF);
  NVIC_EnableIRQ(LETIMER0_IRQn);

}

void letimer0Enable(void){

  uint32_t flags=LETIMER_IntGet(LETIMER0);
  LETIMER_IntClear(LETIMER0, flags);
  LETIMER_Enable(LETIMER0, true);

}

void batteryLevel(uint8_t* count, uint16_t* battery) {
    (*count)++;
    if (*count == 151) {
        *battery = *battery - 1;
        *count = 0;
    }
}

void letimer0Disable(void){

  uint32_t flags=LETIMER_IntGet(LETIMER0);
  LETIMER_IntClear(LETIMER0, flags);
  LETIMER_Enable(LETIMER0, false);

}

void LETIMER0_IRQHandler(void){

  uint32_t flags=LETIMER_IntGet(LETIMER0);
  LETIMER_IntClear(LETIMER0, flags);

  DHT_DataTypedef DHT_data;
  char Mois[4],Cell[4], Temp[4], Humi[4];

  uint16_t batLevel;

  /* Get Moisture */
  iadcStartsingle();
  uint16_t Moisture = getMoisture();

  /* Get Temperature and Humidity  */
  DHT_GetData(&DHT_data);
  uint16_t Temperature = DHT_data.Temperature;
  uint16_t Humidity = DHT_data.Humidity;

  /* Get battery level */
  batteryLevel(&count, &battery);
  batLevel = battery;
  uint16ToCharArray(batLevel, Cell, 4);

  /* Create a data string */
  uint16ToCharArray(Humidity, Humi, 4);
  uint16ToCharArray(Moisture, Mois, 4);
  uint16ToCharArray(Temperature, Temp, 4);
  char data_sensor[18] = {address[0], address[1], address[2], address[3], address[4],
                                                           Mois[0], Mois[1], Mois[2],
                                                           Temp[0], Temp[1], Temp[2],
                                                           Humi[0], Humi[1], Humi[2],
                                                           Cell[0], Cell[1], Cell[2]};
  /* Calculate Checksum */
  uint16_t checksum = calculateChecksum(data_sensor, sizeof(data_sensor));
  char checkSum[3];
  checkSum[0] = checksum >> 8;
  checkSum[1] = checksum & 0xFF;

  char dataTransmit[20] = {address[0], address[1], address[2], address[3], address[4],
                                                             Mois[0], Mois[1], Mois[2],
                                                             Temp[0], Temp[1], Temp[2],
                                                             Humi[0], Humi[1], Humi[2],
                                                             Cell[0], Cell[1], Cell[2],
                                                             checkSum[0], checkSum[1]};

  /* Transmit data sensor */
  transmitData(dataTransmit, sizeof(dataTransmit)-1);

  uint32_t k = 10000000; /* Wait for a period of time to receive a signal response from the station */
    char response;
    while (1){
        k--;
        if( USART0->STATUS & USART_STATUS_RXDATAV ){
        response = (uint8_t)USART0->RXDATA;
        if( response == '1' ){
            break;
        }
        else if ( response == '0' ){
            transmitData(dataTransmit, sizeof(dataTransmit)-1); /* Retransmit the data because the previous data may be corrupted. */
            break;
        }
        }
        else if(k==0){
            transmitData(dataTransmit, sizeof(dataTransmit)-1); /* Retransmit the data as there is no response */
            break;
        }
    }
}


