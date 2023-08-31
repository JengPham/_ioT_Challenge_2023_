/*
 * connect.c
 *
 *  Created on: Jul 21, 2023
 *      Author: PhongPham
 *
 */

#include "connect.h"

char response[10];
void connectToStation(void){

   char dataToConnect[] = {0xFF, 0xFF, 0x17, '1', 0x01, 0x03, 'E'};
   transmitData(dataToConnect, sizeof (dataToConnect));

   /* Nhận phản hồi từ Station xem có được ghép đôi? */
   uint8_t i;
   while(1){
     for (i=0 ; i< 10; i++){
         response[i] = EUSART_Rx(EUSART0);
         if (response[i] == 'E')
           break;
   }
   if(i == 4 && response[0] == '1' && response[1] == '1'){
   /* Station phản hổi được ghép kèm theo địa chỉ Station */

       dataTransmit[0] = response[2]; dataTransmit[1] = response[3];
       GPIO_PinOutToggle(LED0_PORT, LED0_PIN); /* Bật LED0 (5s): Thông báo kết nối thành công */
       USTIMER_Init();
       USTIMER_DelayIntSafe(5000000);
       GPIO_PinOutToggle(LED0_PORT, LED0_PIN);
       USTIMER_DeInit();
       break;

   }
   if(i == 2 && response[0] == '1' && response[1] == '0'){
      /* Station phản hổi không được ghép --> Vào EM4 */

          GPIO_PinOutToggle(LED1_PORT, LED1_PIN); /* Bật LED1 (3s): Thông báo kết nối không thành công */
          USTIMER_Init();
          USTIMER_DelayIntSafe(3000000);
          USTIMER_DeInit();
          EMU_EnterEM4();

        }
    }
}
