################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/drivers/lcd/LCD.c \
../Sources/drivers/lcd/s401.c 

OBJS += \
./Sources/drivers/lcd/LCD.o \
./Sources/drivers/lcd/s401.o 

C_DEPS += \
./Sources/drivers/lcd/LCD.d \
./Sources/drivers/lcd/s401.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/drivers/lcd/%.o: ../Sources/drivers/lcd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"C:\Users\LapPV\workspace.kds\KL46_sLCD\Sources\drivers\io" -I"C:\Users\LapPV\workspace.kds\KL46_sLCD\Sources\drivers\lcd" -I"C:\Users\LapPV\workspace.kds\KL46_sLCD\Sources\drivers\mcg" -I"C:\Users\LapPV\workspace.kds\KL46_sLCD\Sources\drivers\uart" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


