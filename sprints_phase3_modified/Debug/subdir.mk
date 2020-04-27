################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../motor.c \
../phase3.c \
../pwm.c \
../timer0.c \
../timer2.c \
../ultrasonic.c 

OBJS += \
./motor.o \
./phase3.o \
./pwm.o \
./timer0.o \
./timer2.o \
./ultrasonic.o 

C_DEPS += \
./motor.d \
./phase3.d \
./pwm.d \
./timer0.d \
./timer2.d \
./ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


