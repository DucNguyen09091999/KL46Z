################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/drivers/uart/uart.c 

OBJS += \
./Sources/drivers/uart/uart.o 

C_DEPS += \
./Sources/drivers/uart/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/drivers/uart/%.o: ../Sources/drivers/uart/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"C:\Users\LapPV\workspace.kds\KL46_PIT_TIMER\Sources\drivers\io" -I"C:\Users\LapPV\workspace.kds\KL46_PIT_TIMER\Sources\drivers\mcg" -I"C:\Users\LapPV\workspace.kds\KL46_PIT_TIMER\Sources\drivers\uart" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


