################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.3.1/util/third_party/mbedtls/library/subdir.mk
-include gecko_sdk_4.3.1/util/silicon_labs/silabs_core/memory_manager/subdir.mk
-include gecko_sdk_4.3.1/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.3.1/platform/service/system/src/subdir.mk
-include gecko_sdk_4.3.1/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/subdir.mk
-include gecko_sdk_4.3.1/platform/security/sl_component/sl_mbedtls_support/src/subdir.mk
-include gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/subdir.mk
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


BUILD_ARTIFACT_NAME := Node-Sensor_Final
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: Node-Sensor_Final.axf

# Tool invocations
Node-Sensor_Final.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "C:\Users\jengp\SimplicityStudio\v5_workspace\Node-Sensor_Final\autogen\linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="Node-Sensor_Final.map" -mfpu=fpv5-sp-d16 -mfloat-abi=hard --specs=nano.specs -o Node-Sensor_Final.axf -Wl,--start-group "./DHT22.o" "./Letimer.o" "./app.o" "./connect.o" "./crypt.o" "./iadc.o" "./main.o" "./uart.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./gecko_sdk_4.3.1/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.3.1/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.3.1/hardware/driver/configuration_over_swo/src/sl_cos.o" "./gecko_sdk_4.3.1/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_usart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.3.1/platform/Device/SiliconLabs/EFR32MG24/Source/startup_efr32mg24.o" "./gecko_sdk_4.3.1/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.o" "./gecko_sdk_4.3.1/platform/common/src/sl_assert.o" "./gecko_sdk_4.3.1/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.3.1/platform/driver/debug/src/sl_debug_swo.o" "./gecko_sdk_4.3.1/platform/emdrv/ustimer/src/ustimer.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_core.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_emu.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_eusart.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_iadc.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_letimer.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_msc.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_se.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_system.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_timer.o" "./gecko_sdk_4.3.1/platform/emlib/src/em_usart.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager_attestation.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager_cipher.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager_entropy.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager_hash.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager_key_derivation.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager_key_handling.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager_signature.o" "./gecko_sdk_4.3.1/platform/security/sl_component/se_manager/src/sl_se_manager_util.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_mbedtls_support/src/se_aes.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_mbedtls_support/src/sl_mbedtls.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_psa_driver_common.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_psa_driver_init.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_aead.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_builtin_keys.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_cipher.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_key_derivation.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_key_management.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_mac.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_driver_signature.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_opaque_driver_aead.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_opaque_driver_cipher.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_opaque_driver_mac.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_opaque_key_derivation.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_driver_aead.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_driver_cipher.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_driver_hash.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_driver_mac.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_transparent_key_derivation.o" "./gecko_sdk_4.3.1/platform/security/sl_component/sl_psa_driver/src/sli_se_version_dependencies.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_dcdc_s2.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_emu_s2.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_hfrco.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_hfxo_s2.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_lfxo_s2.o" "./gecko_sdk_4.3.1/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.3.1/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.3.1/platform/service/system/src/sl_system_process_action.o" "./gecko_sdk_4.3.1/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.3.1/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" "./gecko_sdk_4.3.1/util/silicon_labs/silabs_core/memory_manager/sl_malloc.o" "./gecko_sdk_4.3.1/util/third_party/mbedtls/library/aes.o" "./gecko_sdk_4.3.1/util/third_party/mbedtls/library/constant_time.o" "./gecko_sdk_4.3.1/util/third_party/mbedtls/library/platform.o" "./gecko_sdk_4.3.1/util/third_party/mbedtls/library/platform_util.o" "./gecko_sdk_4.3.1/util/third_party/mbedtls/library/psa_crypto_client.o" "./gecko_sdk_4.3.1/util/third_party/mbedtls/library/threading.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: Node-Sensor_Final.out'
	arm-none-eabi-objcopy "Node-Sensor_Final.axf" "Node-Sensor_Final.out"
	@echo ' '

	@echo 'Building hex file: Node-Sensor_Final.hex'
	arm-none-eabi-objcopy -O ihex "Node-Sensor_Final.axf" "Node-Sensor_Final.hex"
	@echo ' '

	@echo 'Building bin file: Node-Sensor_Final.bin'
	arm-none-eabi-objcopy -O binary "Node-Sensor_Final.axf" "Node-Sensor_Final.bin"
	@echo ' '

	@echo 'Building s37 file: Node-Sensor_Final.s37'
	arm-none-eabi-objcopy -O srec "Node-Sensor_Final.axf" "Node-Sensor_Final.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "Node-Sensor_Final.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) Node-Sensor_Final.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
