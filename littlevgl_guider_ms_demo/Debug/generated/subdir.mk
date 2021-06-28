################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generated/events_init.c \
../generated/gui_guider.c \
../generated/setup_scr_homepage_screen.c \
../generated/setup_scr_page1_screen.c \
../generated/setup_scr_page2_screen.c \
../generated/setup_scr_page3_screen.c \
../generated/setup_scr_page4_screen.c \
../generated/setup_scr_page5_screen.c \
../generated/setup_scr_page6_screen.c \
../generated/setup_scr_page7_screen.c \
../generated/setup_scr_page8_screen.c \
../generated/setup_scr_page9_screen.c \
../generated/setup_scr_splash_screen.c 

OBJS += \
./generated/events_init.o \
./generated/gui_guider.o \
./generated/setup_scr_homepage_screen.o \
./generated/setup_scr_page1_screen.o \
./generated/setup_scr_page2_screen.o \
./generated/setup_scr_page3_screen.o \
./generated/setup_scr_page4_screen.o \
./generated/setup_scr_page5_screen.o \
./generated/setup_scr_page6_screen.o \
./generated/setup_scr_page7_screen.o \
./generated/setup_scr_page8_screen.o \
./generated/setup_scr_page9_screen.o \
./generated/setup_scr_splash_screen.o 

C_DEPS += \
./generated/events_init.d \
./generated/gui_guider.d \
./generated/setup_scr_homepage_screen.d \
./generated/setup_scr_page1_screen.d \
./generated/setup_scr_page2_screen.d \
./generated/setup_scr_page3_screen.d \
./generated/setup_scr_page4_screen.d \
./generated/setup_scr_page5_screen.d \
./generated/setup_scr_page6_screen.d \
./generated/setup_scr_page7_screen.d \
./generated/setup_scr_page8_screen.d \
./generated/setup_scr_page9_screen.d \
./generated/setup_scr_splash_screen.d 


# Each subdirectory must supply rules for building sources it contributes
generated/%.o: ../generated/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MIMXRT1052DVL6B -DCPU_MIMXRT1052DVL6B_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DSKIP_SYSCLK_INIT -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DLV_EX_CONF_INCLUDE_SIMPLE=1 -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\board" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\source" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\drivers" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\touchpanel" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\littlevgl\lvgl" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\littlevgl\lvgl\src" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\littlevgl" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\device" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\utilities" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\component\uart" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\component\serial_manager" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\component\lists" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\xip" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\CMSIS" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\freertos\freertos_kernel\include" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\generated" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\custom" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\generated\guider_customer_fonts" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\generated\guider_fonts" -I"C:\Users\rapicano\Documents\MCUXpressoProjects\littlevgl_guider_ms_demo\evkbimxrt1050\littlevgl_examples\littlevgl_guider" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


