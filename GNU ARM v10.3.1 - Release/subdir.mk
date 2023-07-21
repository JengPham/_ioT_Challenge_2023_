################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DHT22.c \
../Letimer.c \
../adc.c \
../connect.c \
../flash.c \
../iadcScan.c \
../uart.c 

OBJS += \
./DHT22.o \
./Letimer.o \
./adc.o \
./connect.o \
./flash.o \
./iadcScan.o \
./uart.o 

C_DEPS += \
./DHT22.d \
./Letimer.d \
./adc.d \
./connect.d \
./flash.d \
./iadcScan.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
DHT22.o: ../DHT22.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"DHT22.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Letimer.o: ../Letimer.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"Letimer.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

adc.o: ../adc.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"adc.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

connect.o: ../connect.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"connect.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

flash.o: ../flash.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"flash.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

iadcScan.o: ../iadcScan.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"iadcScan.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart.o: ../uart.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -std=c99 '-DNDEBUG=1' -Os -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"uart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


