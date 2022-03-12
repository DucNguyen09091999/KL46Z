################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/uart/uart.c 

OBJS += \
./Driver/uart/uart.o 

C_DEPS += \
./Driver/uart/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/uart/%.o: ../Driver/uart/%.c Driver/uart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Device" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/FreeRTOS/include" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Driver/uart" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Source" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-uart

clean-Driver-2f-uart:
	-$(RM) ./Driver/uart/uart.d ./Driver/uart/uart.o

.PHONY: clean-Driver-2f-uart

