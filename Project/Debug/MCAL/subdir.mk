################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC_Function.c \
../MCAL/EEPROM.c \
../MCAL/External_interrupt_Atmega32.c \
../MCAL/GPIO.c \
../MCAL/UART_driver_new.c 

OBJS += \
./MCAL/ADC_Function.o \
./MCAL/EEPROM.o \
./MCAL/External_interrupt_Atmega32.o \
./MCAL/GPIO.o \
./MCAL/UART_driver_new.o 

C_DEPS += \
./MCAL/ADC_Function.d \
./MCAL/EEPROM.d \
./MCAL/External_interrupt_Atmega32.d \
./MCAL/GPIO.d \
./MCAL/UART_driver_new.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


