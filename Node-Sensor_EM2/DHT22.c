/*
 * DHT22.c
 *
 *  Created on: Jun 20, 2023
 *      Author: PhongPham
 */

#include "DHT22.h"

#define DHT_PORT gpioPortA /*F9*/
#define DHT_PIN  0

uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
uint16_t SUM;
uint8_t Presence = 0;

void DHT_Start(void){

  USTIMER_Init();
  GPIO_PinModeSet(DHT_PORT, DHT_PIN, gpioModePushPull, 0);
  USTIMER_DelayIntSafe(1200);
  GPIO_PinModeSet(DHT_PORT, DHT_PIN, gpioModePushPull, 1);
  USTIMER_DelayIntSafe(30); /* wait 30us for DHT22's response */
  GPIO_PinModeSet(DHT_PORT, DHT_PIN, gpioModeInput, 0);

}

uint8_t DHT_Check_Response (void){
  uint8_t Response = 0;

  USTIMER_DelayIntSafe(50);
  if(!(GPIO_PinInGet(DHT_PORT, DHT_PIN)))
  {
      USTIMER_DelayIntSafe(100);
      if((GPIO_PinInGet(DHT_PORT, DHT_PIN)))
        {
          Response = 1;
        }
      else
        {
          Response = -1;
        }
  }
  while ((GPIO_PinInGet(DHT_PORT, DHT_PIN)));
  return Response;
}

uint8_t DHT_Read (void){
  uint8_t i,j;
  for (j=0;j<8;j++)
    {
      while (!(GPIO_PinInGet(DHT_PORT, DHT_PIN)));
      USTIMER_DelayIntSafe(50);
      if (!(GPIO_PinInGet(DHT_PORT, DHT_PIN)))
        {
          i&= ~(1<<(7-j));
        }
        else i|= (1<<(7-j));
      while ((GPIO_PinInGet(DHT_PORT, DHT_PIN)));
    }
  return i;
}

void DHT_GetData (DHT_DataTypedef * DHT_Data)
{
   DHT_Start ();
   Presence = DHT_Check_Response ();
   Rh_byte1 = DHT_Read ();
   Rh_byte2 = DHT_Read ();
   Temp_byte1 = DHT_Read ();
   Temp_byte2 = DHT_Read ();
   SUM = DHT_Read();
   if (SUM == (Rh_byte1+Rh_byte2+Temp_byte1+Temp_byte2))
     {
       DHT_Data->Temperature = ((Temp_byte1<<8)|Temp_byte2);
       DHT_Data->Humidity = ((Rh_byte1<<8)|Rh_byte2);
     }
   USTIMER_DeInit();
}
