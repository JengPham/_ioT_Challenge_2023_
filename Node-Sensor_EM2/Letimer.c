/*
 * Letimer.c
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#include "Letimer.h"

#define Time_underflow   10  /* 10s */
char dataTransmit[21];
uint8_t interrupt = 0;
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
  NVIC_ClearPendingIRQ(LETIMER0_IRQn);
  NVIC_EnableIRQ(LETIMER0_IRQn);

}

void letimer0Enable(void){

  uint32_t flags=LETIMER_IntGet(LETIMER0);
  LETIMER_IntClear(LETIMER0, flags);
  LETIMER_Enable(LETIMER0, true);

}

void letimer0Disable(void){

  uint32_t flags=LETIMER_IntGet(LETIMER0);
  LETIMER_IntClear(LETIMER0, flags);
  LETIMER_Enable(LETIMER0, false);

}

void batteryLevel(uint8_t* count, uint16_t* battery) {
    (*count)++;
    if (*count == 5) {
        *battery = *battery - 1;
        *count = 0;
    }
}

void LETIMER0_IRQHandler(void) {

    uint32_t flags = LETIMER_IntGet(LETIMER0);
    LETIMER_IntClear(LETIMER0, flags);
    interrupt++;

    if (interrupt == 2) { /* Every 20 seconds */
        uint16_t Moisture = getMoisture();

        DHT_DataTypedef DHT_data;
        DHT_GetData(&DHT_data);

        batteryLevel(&count, &battery);
        uint16_t batLevel = battery;

        dataTransmit[2] = 0x17;
        dataTransmit[3] = '1';
        uint16ToCharArray(Moisture, &dataTransmit[4], 4);
        uint16ToCharArray(DHT_data.Temperature, &dataTransmit[7], 4);
        uint16ToCharArray(DHT_data.Humidity, &dataTransmit[10], 4);
        uint16ToCharArray(batLevel, &dataTransmit[13], 4);
        dataTransmit[16] = '2';
        dataTransmit[17] = '5';
        dataTransmit[18] = '9';
        char lrc = calculateLrc(&dataTransmit[3], 16);
        dataTransmit[19] = lrc;
        dataTransmit[20] = 'E';

        transmitData(dataTransmit, sizeof(dataTransmit));
        EUSART_IntClear(EUSART0, EUSART_IF_RXFL);
        EUSART_IntEnable(EUSART0, EUSART_IEN_RXFL);
    }

    if (interrupt == 3) {
        transmitData(dataTransmit, sizeof(dataTransmit));
        EUSART_IntDisable(EUSART0, EUSART_IEN_RXFL);
        interrupt = 0;
    }
}


