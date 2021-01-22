################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/freertos_kernel/croutine.c \
../freertos/freertos_kernel/event_groups.c \
../freertos/freertos_kernel/list.c \
../freertos/freertos_kernel/queue.c \
../freertos/freertos_kernel/stream_buffer.c \
../freertos/freertos_kernel/tasks.c \
../freertos/freertos_kernel/timers.c 

OBJS += \
./freertos/freertos_kernel/croutine.o \
./freertos/freertos_kernel/event_groups.o \
./freertos/freertos_kernel/list.o \
./freertos/freertos_kernel/queue.o \
./freertos/freertos_kernel/stream_buffer.o \
./freertos/freertos_kernel/tasks.o \
./freertos/freertos_kernel/timers.o 

C_DEPS += \
./freertos/freertos_kernel/croutine.d \
./freertos/freertos_kernel/event_groups.d \
./freertos/freertos_kernel/list.d \
./freertos/freertos_kernel/queue.d \
./freertos/freertos_kernel/stream_buffer.d \
./freertos/freertos_kernel/tasks.d \
./freertos/freertos_kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/freertos_kernel/%.o: ../freertos/freertos_kernel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC55S28JBD100 -DCPU_LPC55S28JBD100_cm33 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSCANF_FLOAT_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\board" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\freertos\freertos_kernel\include" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\freertos\freertos_kernel\portable\GCC\ARM_CM33_NTZ\non_secure" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\drivers" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\device" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\CMSIS" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\utilities" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\component\serial_manager" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\component\lists" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\component\uart" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\sdmmc\host" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\sdmmc\inc" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\sdmmc\osa" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\component\osa" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\fatfs\source\fsl_sd_disk" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\fatfs\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\fatfs\source\fsl_ram_disk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


