################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/MemMang/heap_1.c 

OBJS += \
./FreeRTOS/portable/MemMang/heap_1.o 

C_DEPS += \
./FreeRTOS/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/MemMang/%.o: ../FreeRTOS/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"C:\Users\quocl\OneDrive\workspace.kds\EP\KL46_FreeRTOS_V20211200\FreeRTOS\include" -I"C:\Users\quocl\OneDrive\workspace.kds\EP\KL46_FreeRTOS_V20211200\FreeRTOS\portable\GCC\ARM_CM0" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


