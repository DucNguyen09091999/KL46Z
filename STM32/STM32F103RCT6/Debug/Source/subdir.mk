################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Source/startup_stm32f103rctx.s 

C_SRCS += \
../Source/main.c \
../Source/system_stm32f1xx.c 

OBJS += \
./Source/main.o \
./Source/startup_stm32f103rctx.o \
./Source/system_stm32f1xx.o 

S_DEPS += \
./Source/startup_stm32f103rctx.d 

C_DEPS += \
./Source/main.d \
./Source/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.c Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xE -c -I"D:/nhung_EP_101/code/STM32/STM32F103RCT6/STM32F1xx" -I"D:/nhung_EP_101/code/STM32/STM32F103RCT6/Source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Source/%.o: ../Source/%.s Source/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -I"D:/nhung_EP_101/code/STM32/STM32F103RCT6/Source" -I"D:/nhung_EP_101/code/STM32/STM32F103RCT6/STM32F1xx" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Source

clean-Source:
	-$(RM) ./Source/main.d ./Source/main.o ./Source/startup_stm32f103rctx.d ./Source/startup_stm32f103rctx.o ./Source/system_stm32f1xx.d ./Source/system_stm32f1xx.o

.PHONY: clean-Source

