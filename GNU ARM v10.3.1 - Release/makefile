################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := IoT_Challenge
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: IoT_Challenge.axf

# Tool invocations
IoT_Challenge.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -T "IoT_Challenge.ld" -Xlinker --gc-sections -Xlinker -Map="IoT_Challenge.map" -mfpu=fpv5-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o IoT_Challenge.axf "./DHT22.o" "./Letimer.o" "./adc.o" "./connect.o" "./flash.o" "./iadcScan.o" "./uart.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: IoT_Challenge.out'
	arm-none-eabi-objcopy "IoT_Challenge.axf" "IoT_Challenge.out"
	@echo ' '

	@echo 'Building hex file: IoT_Challenge.hex'
	arm-none-eabi-objcopy -O ihex "IoT_Challenge.axf" "IoT_Challenge.hex"
	@echo ' '

	@echo 'Building bin file: IoT_Challenge.bin'
	arm-none-eabi-objcopy -O binary "IoT_Challenge.axf" "IoT_Challenge.bin"
	@echo ' '

	@echo 'Building s37 file: IoT_Challenge.s37'
	arm-none-eabi-objcopy -O srec "IoT_Challenge.axf" "IoT_Challenge.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "IoT_Challenge.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) IoT_Challenge.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
