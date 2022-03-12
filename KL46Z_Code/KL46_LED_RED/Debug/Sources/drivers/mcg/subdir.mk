################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/drivers/mcg/mcg.c 

OBJS += \
./Sources/drivers/mcg/mcg.o 

C_DEPS += \
./Sources/drivers/mcg/mcg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/drivers/mcg/%.o: ../Sources/drivers/mcg/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"C:\Users\LapPV\workspace.kds\KL46_LED_RED\Sources\drivers\mcg" -I"C:\Users\LapPV\workspace.kds\KL46_LED_RED\Sources\drivers\uart" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


