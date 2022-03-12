################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/pit_drv/pit_drv.c 

OBJS += \
./Libraries/pit_drv/pit_drv.o 

C_DEPS += \
./Libraries/pit_drv/pit_drv.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/pit_drv/%.o: ../Libraries/pit_drv/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -I"D:\nhung_EP_101\code\KL46Z_Project\KL46-PIT-Timer\Libraries\gpio_drv" -I"D:\nhung_EP_101\code\KL46Z_Project\KL46-PIT-Timer\Libraries\pit_drv" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


