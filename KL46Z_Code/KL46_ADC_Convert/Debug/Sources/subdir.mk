################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/main.c \
../Sources/sa_mtb.c 

OBJS += \
./Sources/main.o \
./Sources/sa_mtb.o 

C_DEPS += \
./Sources/main.d \
./Sources/sa_mtb.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"C:\Users\LapPV\workspace.kds\KL46_ADC_Convert\Sources\drivers\adc16" -I"C:\Users\LapPV\workspace.kds\KL46_ADC_Convert\Sources\drivers\io" -I"C:\Users\LapPV\workspace.kds\KL46_ADC_Convert\Sources\drivers\mcg" -I"C:\Users\LapPV\workspace.kds\KL46_ADC_Convert\Sources\drivers\uart" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


