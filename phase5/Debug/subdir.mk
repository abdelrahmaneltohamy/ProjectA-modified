################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../motor.c \
../phase5.c \
../pwm.c \
../timer0.c \
../timer2.c \
../uart_driver.c \
../ultrasonic.c \
../wifi_driver.c 

OBJS += \
./motor.o \
./phase5.o \
./pwm.o \
./timer0.o \
./timer2.o \
./uart_driver.o \
./ultrasonic.o \
./wifi_driver.o 

C_DEPS += \
./motor.d \
./phase5.d \
./pwm.d \
./timer0.d \
./timer2.d \
./uart_driver.d \
./ultrasonic.d \
./wifi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


