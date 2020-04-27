################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../motor.c \
../phase4.c \
../pwm.c \
../uart_driver.c \
../wifi_driver.c 

OBJS += \
./motor.o \
./phase4.o \
./pwm.o \
./uart_driver.o \
./wifi_driver.o 

C_DEPS += \
./motor.d \
./phase4.d \
./pwm.d \
./uart_driver.d \
./wifi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


