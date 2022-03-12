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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6-Projects/Device" -I"C:/Users/quocl/STM32CubeIDE/workspace_1.7.0/STM32F103C8T6-Projects/Source" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Source/%.o: ../Source/%.s Source/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

