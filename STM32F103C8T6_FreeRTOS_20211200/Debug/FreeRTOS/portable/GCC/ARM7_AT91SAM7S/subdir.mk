################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/ARM7_AT91SAM7S/lib_AT91SAM7X256.c \
../FreeRTOS/portable/GCC/ARM7_AT91SAM7S/port.c \
../FreeRTOS/portable/GCC/ARM7_AT91SAM7S/portISR.c 

OBJS += \
./FreeRTOS/portable/GCC/ARM7_AT91SAM7S/lib_AT91SAM7X256.o \
./FreeRTOS/portable/GCC/ARM7_AT91SAM7S/port.o \
./FreeRTOS/portable/GCC/ARM7_AT91SAM7S/portISR.o 

C_DEPS += \
./FreeRTOS/portable/GCC/ARM7_AT91SAM7S/lib_AT91SAM7X256.d \
./FreeRTOS/portable/GCC/ARM7_AT91SAM7S/port.d \
./FreeRTOS/portable/GCC/ARM7_AT91SAM7S/portISR.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/ARM7_AT91SAM7S/%.o: ../FreeRTOS/portable/GCC/ARM7_AT91SAM7S/%.c FreeRTOS/portable/GCC/ARM7_AT91SAM7S/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Device" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/include" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Driver/uart" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Source" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
