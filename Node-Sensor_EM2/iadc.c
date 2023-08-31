/*
 * adc.c
 *
 *  Created on: Jun 10, 2023
 *      Author: PhongPham
 */

#include "iadc.h"

void iadcInit(void){

  IADC_Init_t init = IADC_INIT_DEFAULT;
  IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
  IADC_InitSingle_t initSingle = IADC_INITSINGLE_DEFAULT;
  IADC_SingleInput_t initSingleInput = IADC_SINGLEINPUT_DEFAULT;
  CMU_ClockEnable(cmuClock_IADC0,true);
  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO); /*Can run in EM2*/
  init.srcClkPrescale = IADC_calcSrcClkPrescale(IADC0, 20000000, 0);
  init.warmup = iadcWarmupNormal;

  initAllConfigs.configs[0].reference = iadcCfgReferenceInt1V2;
  initAllConfigs.configs[0].vRef = 1210;
  initAllConfigs.configs[0].osrHighSpeed = iadcCfgOsrHighSpeed2x;
  initAllConfigs.configs[0].analogGain = iadcCfgAnalogGain0P5x;
  initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale(IADC0,
                                                                     10000000,
                                                                     0,
                                                                     iadcCfgModeNormal,
                                                                     init.srcClkPrescale);
  initSingle.triggerAction = iadcTriggerActionOnce;
  initSingleInput.posInput = iadcPosInputPortAPin5; /*P43*/
  initSingleInput.negInput = iadcNegInputGnd;
  GPIO->ABUSALLOC |= GPIO_ABUSALLOC_AODD0_ADC0;

  IADC_init(IADC0, &init, &initAllConfigs);
  IADC_initSingle(IADC0, &initSingle, &initSingleInput);

}

uint16_t getMoisture(void){
  float Sum = 0;
  for(uint8_t i = 0; i < 7; i++){
      IADC_command(IADC0, iadcCmdStartSingle);
      while(!IADC_IF_SINGLEDONE);
      if(i>1){
          IADC_Result_t sample = IADC_readSingleResult(IADC0);
          Sum = (sample.data * 2.42 / 0xFFF) + Sum;
      }
  }
  float voltage = Sum / 5;
  uint16_t Moisture = ((3.0 - voltage) / 3.0) * 1000;
  return Moisture;
}


