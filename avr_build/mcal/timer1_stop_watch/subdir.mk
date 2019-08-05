################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mcal/timer1_stop_watch/timer1_spw.c 

OBJS += \
./mcal/timer1_stop_watch/timer1_spw.o 

C_DEPS += \
./mcal/timer1_stop_watch/timer1_spw.d 


# Each subdirectory must supply rules for building sources it contributes
mcal/timer1_stop_watch/%.o: ../mcal/timer1_stop_watch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


