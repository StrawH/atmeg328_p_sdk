################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../apps/led_app.c \
../apps/seven_segmen_app.c \
../apps/temprture_app.c \
../apps/test_lcd_app.c 

OBJS += \
./apps/led_app.o \
./apps/seven_segmen_app.o \
./apps/temprture_app.o \
./apps/test_lcd_app.o 

C_DEPS += \
./apps/led_app.d \
./apps/seven_segmen_app.d \
./apps/temprture_app.d \
./apps/test_lcd_app.d 


# Each subdirectory must supply rules for building sources it contributes
apps/%.o: ../apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


