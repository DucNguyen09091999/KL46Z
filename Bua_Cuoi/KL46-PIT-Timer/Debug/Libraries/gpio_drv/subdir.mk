################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/gpio_drv/gpio_drv.c 

OBJS += \
./Libraries/gpio_drv/gpio_drv.o 

C_DEPS += \
./Libraries/gpio_drv/gpio_drv.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/gpio_drv/%.o: ../Libraries/gpio_drv/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -I"C:\Users\quocl\OneDrive\workspace.kds\EP\KL46-PIT-Timer\Libraries\gpio_drv" -I"C:\Users\quocl\OneDrive\workspace.kds\EP\KL46-PIT-Timer\Libraries\pit_drv" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


