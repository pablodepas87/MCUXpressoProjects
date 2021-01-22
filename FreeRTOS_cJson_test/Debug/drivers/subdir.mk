################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_flexcomm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_power.c \
../drivers/fsl_reset.c \
../drivers/fsl_sdif.c \
../drivers/fsl_usart.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flexcomm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_power.o \
./drivers/fsl_reset.o \
./drivers/fsl_sdif.o \
./drivers/fsl_usart.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_flexcomm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_power.d \
./drivers/fsl_reset.d \
./drivers/fsl_sdif.d \
./drivers/fsl_usart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC55S28JBD100 -DCPU_LPC55S28JBD100_cm33 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSCANF_FLOAT_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\board" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\freertos\freertos_kernel\include" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\freertos\freertos_kernel\portable\GCC\ARM_CM33_NTZ\non_secure" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\drivers" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\device" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\CMSIS" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\utilities" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\component\serial_manager" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\component\lists" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\component\uart" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\sdmmc\host" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\sdmmc\inc" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\sdmmc\osa" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\component\osa" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\fatfs\source\fsl_sd_disk" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\fatfs\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\FreeRTOS_cJson_test\fatfs\source\fsl_ram_disk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


