################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/port.c 

S_UPPER_SRCS += \
../FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/portasm.S 

OBJS += \
./FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/port.o \
./FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/portasm.o 

S_UPPER_DEPS += \
./FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/portasm.d 

C_DEPS += \
./FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/%.o: ../FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/%.c FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Device" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/include" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Driver/uart" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Source" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/%.o: ../FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/%.S FreeRTOS/portable/ThirdParty/CDK/T-HEAD_CK802/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

