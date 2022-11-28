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
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ledtoggle.lss \

FLASH_IMAGE += \
ledtoggle.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ledtoggle.elf secondary-outputs

# Tool invocations
ledtoggle.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ledtoggle.map -mmcu=atmega32 -o "ledtoggle.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ledtoggle.lss: ledtoggle.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ledtoggle.elf  >"ledtoggle.lss"
	@echo 'Finished building: $@'
	@echo ' '

ledtoggle.hex: ledtoggle.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ledtoggle.elf  "ledtoggle.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ledtoggle.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ledtoggle.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ledtoggle.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
