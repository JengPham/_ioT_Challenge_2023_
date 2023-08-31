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


BUILD_ARTIFACT_NAME := Node-Sensor_EM2
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: Node-Sensor_EM2.axf

# Tool invocations
Node-Sensor_EM2.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m33 -mthumb -T "Node-Sensor_EM2.ld" -Xlinker --gc-sections -Xlinker -Map="Node-Sensor_EM2.map" -mfpu=fpv5-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o Node-Sensor_EM2.axf "./DHT22.o" "./Letimer.o" "./connect.o" "./flash.o" "./iadc.o" "./uart.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: Node-Sensor_EM2.out'
	arm-none-eabi-objcopy "Node-Sensor_EM2.axf" "Node-Sensor_EM2.out"
	@echo ' '

	@echo 'Building hex file: Node-Sensor_EM2.hex'
	arm-none-eabi-objcopy -O ihex "Node-Sensor_EM2.axf" "Node-Sensor_EM2.hex"
	@echo ' '

	@echo 'Building bin file: Node-Sensor_EM2.bin'
	arm-none-eabi-objcopy -O binary "Node-Sensor_EM2.axf" "Node-Sensor_EM2.bin"
	@echo ' '

	@echo 'Building s37 file: Node-Sensor_EM2.s37'
	arm-none-eabi-objcopy -O srec "Node-Sensor_EM2.axf" "Node-Sensor_EM2.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "Node-Sensor_EM2.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) Node-Sensor_EM2.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
