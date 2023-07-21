/*
 * flash.c
 *
 *  Created on: Jun 20, 2023
 *      Author: PhongPham
 */
#include "flash.h"
/* Địa chỉ bắt đầu của vùng nhớ USERDATA */
#define USER_FLASH_ADDRESS 0x0fe00000

void writeDataToUserFlash(uint32_t *address,void const *data,uint32_t numBytes){

  CMU_ClockEnable(cmuClock_MSC, true);
  MSC_Init();
  MSC_ErasePage(address);
  MSC_WriteWord(address, data, numBytes);
  MSC_Deinit();
  CMU_ClockEnable(cmuClock_MSC, false);

}

void eraseUserFlashData(uint32_t *address){

  CMU_ClockEnable(cmuClock_MSC, true);
  MSC_Init();
  MSC_ErasePage(address);
  MSC_Deinit();
  CMU_ClockEnable(cmuClock_MSC, false);

}

uint32_t flashReadData(uint32_t *address) {
  uint32_t data = *address;
  return data;
}

/*
  uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
  writeDataToUserFlash((uint32_t *)USER_FLASH_ADDRESS, data, 5);
*/

