################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.3.1/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.3.1/platform/service/system/src/subdir.mk
-include gecko_sdk_4.3.1/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.3.1/platform/emlib/src/subdir.mk
-include gecko_sdk_4.3.1/platform/emdrv/ustimer/src/subdir.mk
-include gecko_sdk_4.3.1/platform/driver/debug/src/subdir.mk
-include gecko_sdk_4.3.1/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.3.1/platform/common/src/subdir.mk
-include gecko_sdk_4.3.1/platform/Device/SiliconLabs/EFR32MG24/Source/subdir.mk
-include gecko_sdk_4.3.1/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/subdir.mk
-include gecko_sdk_4.3.1/hardware/driver/configuration_over_swo/src/subdir.mk
-include gecko_sdk_4.3.1/hardware/board/src/subdir.mk
-include autogen/subdir.mk
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


BUILD_ARTIFACT_NAME := Node_DC
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: Node_DC.axf

# Tool invocations
Node_DC.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "C:\Users\jengp\SimplicityStudio\v5_workspace\Node_DC\autogen\linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="Node_DC.map" -mfpu=fpv5-sp-d16 -mfloat-abi=hard --specs=nano.specs -o Node_DC.axf -Wl,--start-group "./Timer.o" "./app.o" "./connect.o" "./main.o" "./usart.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./gecko_sdk_4.3.1/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.3.1/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.3.1/hardware/driver/configuration_over_swo/src/sl_cos.o" "./gecko_sdk_4.3.1/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.3.1/platform/Device/SiliconLabs/EFR32MG24/Source/startup_efr32mg24.o" "./gecko_sdk_4.3.1/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.o" "./gecko_sdk_4.3.1/platform/common/src/sl_assert.o" "./gecko_sdk_4.3.1/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.3.1/platform/driver/debug/src/sl_debug_swo.o" "./gecko_sdk_4.3.1/platform/emdrv/ustimer/src/ustimer.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_core.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_emu.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_msc.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_system.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_timer.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_usart.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_dcdc_s2.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_emu_s2.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_hfxo_s2.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_lfxo_s2.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.3.1/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.3.1/platform/service/system/src/sl_system_process_action.o" "./gecko_sdk_4.3.1/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.3.1/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: Node_DC.out'
	arm-none-eabi-objcopy "Node_DC.axf" "Node_DC.out"
	@echo ' '

	@echo 'Building hex file: Node_DC.hex'
	arm-none-eabi-objcopy -O ihex "Node_DC.axf" "Node_DC.hex"
	@echo ' '

	@echo 'Building bin file: Node_DC.bin'
	arm-none-eabi-objcopy -O binary "Node_DC.axf" "Node_DC.bin"
	@echo ' '

	@echo 'Building s37 file: Node_DC.s37'
	arm-none-eabi-objcopy -O srec "Node_DC.axf" "Node_DC.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "Node_DC.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) Node_DC.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
