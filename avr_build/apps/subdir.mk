################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../apps/fire_app.c \
../apps/i2c_app.c \
../apps/ldr_app.c \
../apps/led_app.c \
../apps/pwm_app.c \
../apps/rfid_app.c \
../apps/robot_app.c \
../apps/seven_segmen_app.c \
../apps/spi_test_transmition.c \
../apps/temprture_app.c \
../apps/temprture_serial_app.c \
../apps/test_lcd_app.c \
../apps/uart_app.c \
../apps/ultra_sonic_app.c 

OBJS += \
./apps/fire_app.o \
./apps/i2c_app.o \
./apps/ldr_app.o \
./apps/led_app.o \
./apps/pwm_app.o \
./apps/rfid_app.o \
./apps/robot_app.o \
./apps/seven_segmen_app.o \
./apps/spi_test_transmition.o \
./apps/temprture_app.o \
./apps/temprture_serial_app.o \
./apps/test_lcd_app.o \
./apps/uart_app.o \
./apps/ultra_sonic_app.o 

C_DEPS += \
./apps/fire_app.d \
./apps/i2c_app.d \
./apps/ldr_app.d \
./apps/led_app.d \
./apps/pwm_app.d \
./apps/rfid_app.d \
./apps/robot_app.d \
./apps/seven_segmen_app.d \
./apps/spi_test_transmition.d \
./apps/temprture_app.d \
./apps/temprture_serial_app.d \
./apps/test_lcd_app.d \
./apps/uart_app.d \
./apps/ultra_sonic_app.d 


# Each subdirectory must supply rules for building sources it contributes
apps/%.o: ../apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


