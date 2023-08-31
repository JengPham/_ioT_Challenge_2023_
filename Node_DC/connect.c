/*
 * connect.c
 *
 *  Created on: Jul 21, 2023
 *      Author: PhongPham
 *
 */

#include "connect.h"

char dataTransmit[11] = {0};
char response[10] = {0};
void connectToStation(void){
   bool connect = false;
   char dataToConnect[] = { 0xFF, 0xFF, 0x17, '2', 0x01, 0x04, 'E'};
   transmitData(dataToConnect, sizeof (dataToConnect));

   /* Nhận phản hồi từ Station xem có được ghép đôi? */
   uint8_t i;
   while(!connect){
     for ( i=0 ; i< 10; i++){
         response[i] = USART_Rx(USART0);
         if (response[i] == 'E')
           break;
   }
   if(i == 4){
   /* Station phản hổi được ghép kèm theo địa chỉ Station */
   if ( response[0] == '2' && response[1] == '1'){
       dataTransmit[0] = response[2]; dataTransmit[1] = response[3];
       dataTransmit[2] = 0x17; dataTransmit[3] = '2'; dataTransmit[7] = '2';
       dataTransmit[8] = '5'; dataTransmit[9] = '8'; dataTransmit[10] = 'E';
       GPIO_PinOutToggle(GPIO_PORTB, 2); /* Bật LED0 (3s): Thông báo kết nối thành công */
       USTIMER_Init();
       USTIMER_DelayIntSafe(3000000);
       GPIO_PinOutToggle(GPIO_PORTB, 2);
       USTIMER_DeInit();
       connect = true;
   }
   }
   if(i == 2){
   /* Station phản hổi không được ghép --> Vào EM4 */
       if(response[0] == '2' && response[1] == '0'){
       GPIO_PinOutToggle(GPIO_PORTB, 4); /* Bật LED1 (3s): Thông báo kết nối không thành công */
       USTIMER_Init();
       USTIMER_DelayIntSafe(3000000);
       USTIMER_DeInit();
       EMU_EnterEM4();
   }
}
}
}
