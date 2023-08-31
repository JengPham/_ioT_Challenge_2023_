
#include "app.h"

void app_init(void)
{
    gpioInit();
    uartInit();
    while(1){
        /* Đợi người dùng nhấn BUTTON_0 để kết nối tới Station */
        if(!GPIO_PinInGet(GPIO_PORTB, 1)){
            connectToStation();
            break;
        }
    }
    USART_IntEnable(USART0, USART_IEN_RXDATAV);
    /* Gửi trạng thái ban đầu của các động cơ sau khi kết nối */
    transmitTheStateOfTheMotors();
}


void app_process_action(void)
{
}
