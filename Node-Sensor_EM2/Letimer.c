/*
 * Letimer.c
 *
 *  Created on: Jun 18, 2023
 *      Author: PhongPham
 */

#include "Letimer.h"

#define Time_underflow   10  /*The Letimer interrupts every 10 seconds*/
unsigned char dataTransmit[23];
uint8_t interrupt = 0;
uint16_t battery = 100;
uint8_t count = 0;
extern uint8_t work;

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

    if(work==0 && interrupt<=2){
        EUSART_IntDisable(EUSART0, EUSART_IEN_RXFL);
        unsigned char dataToConnect[] = {0xFF, 0xFF, 0x17, '1', 0x01, 0x03, 'E'};;
        transmitData(dataToConnect, sizeof(dataToConnect));
        EUSART_IntEnable(EUSART0, EUSART_IEN_RXFL);
    }

    else if(work==0 && interrupt==3){
        EUSART_IntDisable(EUSART0, EUSART_IEN_RXFL);
        GPIO_PinOutToggle(LED1_PORT, LED1_PIN); /*Turn on LED-1(3s)to inform the user that the connection was unsuccessful*/
        USTIMER_Init();
        USTIMER_DelayIntSafe(3000000);
        USTIMER_DeInit();
        GPIO_PinOutToggle(LED1_PORT, LED1_PIN);
        interrupt = 0;
        letimer0Disable();
    }
    else if (work==1 && interrupt == 179){
        GPIO_PinOutSet(LoraPort, LoraPin);
    }
    else if (work==1 && interrupt == 180) { /* Every 30 minutes */

        uint16_t Moisture = getMoisture(); /*Get Moisture data*/
        GPIO_PinOutClear(LoraPort, LoraPin);
        DHT_DataTypedef DHT_data; /*Get Temperature and Humidity data*/
        DHT_GetData(&DHT_data);

        batteryLevel(&count, &battery); /*Get battery level*/
        uint16_t batLevel = battery;

        /*Create a data array for transmission*/
        dataTransmit[2] = 0x17; dataTransmit[3] = '1';
        uint16ToUnsignedCharArray(Moisture, &dataTransmit[4], 4);
        uint16ToUnsignedCharArray(DHT_data.Temperature, &dataTransmit[7], 4);
        uint16ToUnsignedCharArray(DHT_data.Humidity, &dataTransmit[10], 4);
        uint16ToUnsignedCharArray(batLevel, &dataTransmit[13], 4);
        dataTransmit[16] = '2'; dataTransmit[17] = '5';
        dataTransmit[18] = '9'; dataTransmit[20] = 'E';
        dataTransmit[21] = 'E'; dataTransmit[22] = 'E';
        dataTransmit[19] = calculateLrc(&dataTransmit[3], 16);

        /* Encrypt */
        unsigned char dataToEncrypt[16];
        unsigned char encryptedData[16];
        memcpy(dataToEncrypt, &dataTransmit[4], 16);
        EncryptDataECB(dataToEncrypt, encryptedData);
        memcpy(&dataTransmit[4], encryptedData, 16);

        /* Transmit data to station */
        transmitData(dataTransmit, sizeof(dataTransmit));
        EUSART_IntEnable(EUSART0, EUSART_IEN_RXFL);
    }

    else if (work==1 && interrupt == 181) {
        transmitData(dataTransmit, sizeof(dataTransmit)); /*Retransmit data when no response is received from the station*/
        EUSART_IntDisable(EUSART0, EUSART_IEN_RXFL);
        interrupt = 0;
    }
}


