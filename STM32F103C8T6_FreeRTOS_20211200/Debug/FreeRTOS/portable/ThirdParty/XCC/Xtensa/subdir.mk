################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/port.c \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/portclib.c \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_init.c \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_intr.c \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_overlay_os_hook.c 

S_UPPER_SRCS += \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/portasm.S \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_context.S \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_intr_asm.S \
../FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_vectors.S 

OBJS += \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/port.o \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/portasm.o \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/portclib.o \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_context.o \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_init.o \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_intr.o \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_intr_asm.o \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_overlay_os_hook.o \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_vectors.o 

S_UPPER_DEPS += \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/portasm.d \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_context.d \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_intr_asm.d \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_vectors.d 

C_DEPS += \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/port.d \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/portclib.d \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_init.d \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_intr.d \
./FreeRTOS/portable/ThirdParty/XCC/Xtensa/xtensa_overlay_os_hook.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/ThirdParty/XCC/Xtensa/%.o: ../FreeRTOS/portable/ThirdParty/XCC/Xtensa/%.c FreeRTOS/portable/ThirdParty/XCC/Xtensa/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Device" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/include" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Driver/uart" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/Source" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/portable/ThirdParty/XCC/Xtensa/%.o: ../FreeRTOS/portable/ThirdParty/XCC/Xtensa/%.S FreeRTOS/portable/ThirdParty/XCC/Xtensa/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

