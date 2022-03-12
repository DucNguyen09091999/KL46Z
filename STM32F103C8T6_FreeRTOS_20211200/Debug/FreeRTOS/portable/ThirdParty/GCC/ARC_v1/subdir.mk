################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../FreeRTOS/portable/ThirdParty/GCC/ARC_v1/arc_support.s 

C_SRCS += \
../FreeRTOS/portable/ThirdParty/GCC/ARC_v1/arc_freertos_exceptions.c \
../FreeRTOS/portable/ThirdParty/GCC/ARC_v1/port.c 

OBJS += \
./FreeRTOS/portable/ThirdParty/GCC/ARC_v1/arc_freertos_exceptions.o \
./FreeRTOS/portable/ThirdParty/GCC/ARC_v1/arc_support.o \
./FreeRTOS/portable/ThirdParty/GCC/ARC_v1/port.o 

S_DEPS += \
./FreeRTOS/portable/ThirdParty/GCC/ARC_v1/arc_support.d 

C_DEPS += \
./FreeRTOS/portable/ThirdParty/GCC/ARC_v1/arc_freertos_exceptions.d \
./FreeRTOS/portable/ThirdParty/GCC/ARC_v1/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/ThirdParty/GCC/ARC_v1/%.o: ../FreeRTOS/portable/ThirdParty/GCC/ARC_v1/%.c FreeRTOS/portable/ThirdParty/GCC/ARC_v1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Device" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/include" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Driver/uart" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Source" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/portable/ThirdParty/GCC/ARC_v1/%.o: ../FreeRTOS/portable/ThirdParty/GCC/ARC_v1/%.s FreeRTOS/portable/ThirdParty/GCC/ARC_v1/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

