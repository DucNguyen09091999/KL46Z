################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/ARM_CM33/secure/secure_context.c \
../FreeRTOS/portable/GCC/ARM_CM33/secure/secure_context_port.c \
../FreeRTOS/portable/GCC/ARM_CM33/secure/secure_heap.c \
../FreeRTOS/portable/GCC/ARM_CM33/secure/secure_init.c 

OBJS += \
./FreeRTOS/portable/GCC/ARM_CM33/secure/secure_context.o \
./FreeRTOS/portable/GCC/ARM_CM33/secure/secure_context_port.o \
./FreeRTOS/portable/GCC/ARM_CM33/secure/secure_heap.o \
./FreeRTOS/portable/GCC/ARM_CM33/secure/secure_init.o 

C_DEPS += \
./FreeRTOS/portable/GCC/ARM_CM33/secure/secure_context.d \
./FreeRTOS/portable/GCC/ARM_CM33/secure/secure_context_port.d \
./FreeRTOS/portable/GCC/ARM_CM33/secure/secure_heap.d \
./FreeRTOS/portable/GCC/ARM_CM33/secure/secure_init.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/ARM_CM33/secure/%.o: ../FreeRTOS/portable/GCC/ARM_CM33/secure/%.c FreeRTOS/portable/GCC/ARM_CM33/secure/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Device" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/include" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Driver/uart" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Source" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

