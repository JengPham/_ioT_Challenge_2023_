
/*
 * Timer.c
 *
 *  Created on: Aug 27, 2023
 *      Author: jengp
 */

#include "Timer.h"

#define  Time_underflow  6 /* 1 Phút */
uint16_t count = 0;
uint8_t T1 = 0;
uint8_t T2 = 0;
uint8_t T3 = 0;

void TIMER1Init(void){

  CMU_ClockEnable(cmuClock_TIMER1, true);
  TIMER_Init_TypeDef Init = TIMER_INIT_DEFAULT;
  Init.enable = false;
  TIMER_Init(TIMER1, &Init);
  TIMER_IntClear(TIMER1, _TIMER_IF_MASK);
  TIMER_TopSet(TIMER1, CMU_ClockFreqGet(cmuClock_TIMER1) / 1 * Time_underflow);

  NVIC_ClearPendingIRQ(TIMER1_IRQn);
  NVIC_EnableIRQ(TIMER1_IRQn);

}

void TIMER1Enable(void){

  uint32_t flags=TIMER_IntGet(TIMER1);
  TIMER_IntClear(TIMER1, flags);
  TIMER_Enable(TIMER1, true);

}

void TIMER1Disable(void){

  uint32_t flags=TIMER_IntGet(TIMER1);
  TIMER_IntClear(TIMER1, flags);
  TIMER_Enable(TIMER1, false);

}

void TIMER1_IRQHandler(void){
  uint32_t flags=TIMER_IntGet(TIMER1);
  TIMER_IntClear(TIMER1, flags);
  count++;
  if(count == T1 || count == T2 || count == T3){
      if(count == T1){
          GPIO_PinOutClear(MOTOR1_PORT, MOTOR1_PIN);
          T1 = 0;
      }
      if(count == T2){
          GPIO_PinOutClear(MOTOR2_PORT, MOTOR2_PIN);
          T2 = 0;
      }
      if(count == T3){
          GPIO_PinOutClear(MOTOR3_PORT, MOTOR3_PIN);
          T3 = 0;
      }
      transmitTheStateOfTheMotors();
  }

  if(T1==0 && T2==0 && T3==0){
      count = 0;
      TIMER_IntDisable(TIMER1, TIMER_IEN_OF);
      TIMER1Disable();
  }
}



