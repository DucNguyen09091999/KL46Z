################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/ARM_CM3/port.c 

OBJS += \
./FreeRTOS/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./FreeRTOS/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/ARM_CM3/%.o: ../FreeRTOS/portable/GCC/ARM_CM3/%.c FreeRTOS/portable/GCC/ARM_CM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Device" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/FreeRTOS/include" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Driver/uart" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Source" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3

clean-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3:
	-$(RM) ./FreeRTOS/portable/GCC/ARM_CM3/port.d ./FreeRTOS/portable/GCC/ARM_CM3/port.o

.PHONY: clean-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3

