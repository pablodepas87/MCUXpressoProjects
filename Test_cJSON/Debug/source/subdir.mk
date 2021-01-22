################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Test_cJSON.c \
../source/cJSON.c \
../source/inizializations.c \
../source/json_handler.c \
../source/sd_handler.c \
../source/semihost_hardfault.c 

OBJS += \
./source/Test_cJSON.o \
./source/cJSON.o \
./source/inizializations.o \
./source/json_handler.o \
./source/sd_handler.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/Test_cJSON.d \
./source/cJSON.d \
./source/inizializations.d \
./source/json_handler.d \
./source/sd_handler.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC55S28JBD100 -DCPU_LPC55S28JBD100_cm33 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\drivers" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\sdmmc\host" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\utilities" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\sdmmc\inc" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\component\lists" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\sdmmc\osa" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\fatfs\source\fsl_sd_disk" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\component\serial_manager" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\device" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\fatfs\source\fsl_ram_disk" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\fatfs\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\CMSIS" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\component\osa" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\component\uart" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\board" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\drivers" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\device" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\CMSIS" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\utilities" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\component\serial_manager" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\component\lists" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\component\uart" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\fatfs\source\fsl_sd_disk" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\fatfs\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\fatfs\source\fsl_ram_disk" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\sdmmc\inc" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\sdmmc\host" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\sdmmc\osa" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\Test_cJSON\component\osa" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


