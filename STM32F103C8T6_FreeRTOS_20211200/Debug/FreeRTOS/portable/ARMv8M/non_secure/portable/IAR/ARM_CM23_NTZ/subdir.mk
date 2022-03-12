################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../FreeRTOS/portable/ARMv8M/non_secure/portable/IAR/ARM_CM23_NTZ/portasm.s 

OBJS += \
./FreeRTOS/portable/ARMv8M/non_secure/portable/IAR/ARM_CM23_NTZ/portasm.o 

S_DEPS += \
./FreeRTOS/portable/ARMv8M/non_secure/portable/IAR/ARM_CM23_NTZ/portasm.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/ARMv8M/non_secure/portable/IAR/ARM_CM23_NTZ/%.o: ../FreeRTOS/portable/ARMv8M/non_secure/portable/IAR/ARM_CM23_NTZ/%.s FreeRTOS/portable/ARMv8M/non_secure/portable/IAR/ARM_CM23_NTZ/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

