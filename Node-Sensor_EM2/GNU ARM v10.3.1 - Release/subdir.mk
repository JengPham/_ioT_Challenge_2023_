################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DHT22.c \
../Letimer.c \
../connect.c \
../flash.c \
../iadc.c \
../uart.c 

OBJS += \
./DHT22.o \
./Letimer.o \
./connect.o \
./flash.o \
./iadc.o \
./uart.o 

C_DEPS += \
./DHT22.d \
./Letimer.d \
./connect.d \
./flash.d \
./iadc.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
DHT22.o: ../DHT22.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -I"C:\Users\jengp\SimplicityStudio\v5_workspace\Node-Sensor_EM2\gecko_sdk_4.3.1\platform\Device\SiliconLabs\EFR32MG24\Include" -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"DHT22.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Letimer.o: ../Letimer.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -I"C:\Users\jengp\SimplicityStudio\v5_workspace\Node-Sensor_EM2\gecko_sdk_4.3.1\platform\Device\SiliconLabs\EFR32MG24\Include" -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"Letimer.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

connect.o: ../connect.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -I"C:\Users\jengp\SimplicityStudio\v5_workspace\Node-Sensor_EM2\gecko_sdk_4.3.1\platform\Device\SiliconLabs\EFR32MG24\Include" -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"connect.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

flash.o: ../flash.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -I"C:\Users\jengp\SimplicityStudio\v5_workspace\Node-Sensor_EM2\gecko_sdk_4.3.1\platform\Device\SiliconLabs\EFR32MG24\Include" -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"flash.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

iadc.o: ../iadc.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -I"C:\Users\jengp\SimplicityStudio\v5_workspace\Node-Sensor_EM2\gecko_sdk_4.3.1\platform\Device\SiliconLabs\EFR32MG24\Include" -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"iadc.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart.o: ../uart.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -I"C:\Users\jengp\SimplicityStudio\v5_workspace\Node-Sensor_EM2\gecko_sdk_4.3.1\platform\Device\SiliconLabs\EFR32MG24\Include" -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"uart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


