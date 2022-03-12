################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/rtc/rtc.c 

OBJS += \
./drivers/rtc/rtc.o 

C_DEPS += \
./drivers/rtc/rtc.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/rtc/%.o: ../drivers/rtc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"C:\Users\LapPV\workspace.kds\KL46_RTC\drivers\rtc" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


