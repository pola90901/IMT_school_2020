################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../LCD_prog.c \
../PWM_prog.c \
../SPI_program2.c \
../main2.c 

OBJS += \
./DIO_Prog.o \
./LCD_prog.o \
./PWM_prog.o \
./SPI_program2.o \
./main2.o 

C_DEPS += \
./DIO_Prog.d \
./LCD_prog.d \
./PWM_prog.d \
./SPI_program2.d \
./main2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


