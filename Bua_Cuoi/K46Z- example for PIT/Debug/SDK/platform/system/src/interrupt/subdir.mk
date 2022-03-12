################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/system/src/interrupt/fsl_interrupt_manager.c 

OBJS += \
./SDK/platform/system/src/interrupt/fsl_interrupt_manager.o 

C_DEPS += \
./SDK/platform/system/src/interrupt/fsl_interrupt_manager.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/system/src/interrupt/%.o: ../SDK/platform/system/src/interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL46Z256VLL4" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/hal/inc" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/hal/src/sim/MKL46Z4" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/system/src/clock/MKL46Z4" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/system/inc" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/osa/inc" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/CMSIS/Include" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/devices" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/devices/MKL46Z4/include" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/devices/MKL46Z4/startup" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/Generated_Code/SDK/platform/devices/MKL46Z4/startup" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/Sources" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/Generated_Code" -I"C:/Users/brao/workspace.kds/KDS3.0/K46Z- example for PIT/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


