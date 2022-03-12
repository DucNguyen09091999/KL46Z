################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/croutine.c \
../FreeRTOS/event_groups.c \
../FreeRTOS/list.c \
../FreeRTOS/queue.c \
../FreeRTOS/stream_buffer.c \
../FreeRTOS/tasks.c \
../FreeRTOS/timers.c 

OBJS += \
./FreeRTOS/croutine.o \
./FreeRTOS/event_groups.o \
./FreeRTOS/list.o \
./FreeRTOS/queue.o \
./FreeRTOS/stream_buffer.o \
./FreeRTOS/tasks.o \
./FreeRTOS/timers.o 

C_DEPS += \
./FreeRTOS/croutine.d \
./FreeRTOS/event_groups.d \
./FreeRTOS/list.d \
./FreeRTOS/queue.d \
./FreeRTOS/stream_buffer.d \
./FreeRTOS/tasks.d \
./FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/%.o: ../FreeRTOS/%.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32F103xB -c -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Device" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/FreeRTOS/include" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Driver/uart" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/Source" -I"D:/nhung_EP_101/code/STM32F103C8T6_FreeRTOS_20211200/FreeRTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-FreeRTOS

clean-FreeRTOS:
	-$(RM) ./FreeRTOS/croutine.d ./FreeRTOS/croutine.o ./FreeRTOS/event_groups.d ./FreeRTOS/event_groups.o ./FreeRTOS/list.d ./FreeRTOS/list.o ./FreeRTOS/queue.d ./FreeRTOS/queue.o ./FreeRTOS/stream_buffer.d ./FreeRTOS/stream_buffer.o ./FreeRTOS/tasks.d ./FreeRTOS/tasks.o ./FreeRTOS/timers.d ./FreeRTOS/timers.o

.PHONY: clean-FreeRTOS

