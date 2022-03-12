################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Source/startup_stm32f103c8tx.s 

C_SRCS += \
../Source/main.c \
../Source/syscalls.c \
../Source/sysmem.c \
../Source/system_stm32f1xx.c 

OBJS += \
./Source/main.o \
./Source/startup_stm32f103c8tx.o \
./Source/syscalls.o \
./Source/sysmem.o \
./Source/system_stm32f1xx.o 

S_DEPS += \
./Source/startup_stm32f103c8tx.d 

C_DEPS += \
./Source/main.d \
./Source/syscalls.d \
./Source/sysmem.d \
./Source/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.c Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Device" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/FreeRTOS/include" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Driver/uart" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Source" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Source/%.o: ../Source/%.s Source/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Source

clean-Source:
	-$(RM) ./Source/main.d ./Source/main.o ./Source/startup_stm32f103c8tx.d ./Source/startup_stm32f103c8tx.o ./Source/syscalls.d ./Source/syscalls.o ./Source/sysmem.d ./Source/sysmem.o ./Source/system_stm32f1xx.d ./Source/system_stm32f1xx.o

.PHONY: clean-Source

