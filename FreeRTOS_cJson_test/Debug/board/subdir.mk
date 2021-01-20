################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/peripherals.c \
../board/pin_mux.c \
../board/sdmmc_config.c 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o \
./board/sdmmc_config.o 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/peripherals.d \
./board/pin_mux.d \
./board/sdmmc_config.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC55S28JBD100 -DCPU_LPC55S28JBD100_cm33 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSCANF_FLOAT_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\board" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\source" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\freertos\freertos_kernel\include" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\freertos\freertos_kernel\portable\GCC\ARM_CM33_NTZ\non_secure" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\drivers" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\device" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\CMSIS" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\utilities" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\component\serial_manager" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\component\lists" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\component\uart" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\sdmmc\host" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\sdmmc\inc" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\sdmmc\osa" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\component\osa" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\fatfs\source\fsl_sd_disk" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\fatfs\source" -I"C:\Users\rapicano\Documents\MCUXpressoIDE_11.2.1_4149\workspace\FreeRTOS_cJson_test\fatfs\source\fsl_ram_disk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


