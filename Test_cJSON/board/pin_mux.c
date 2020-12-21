/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v8.0
processor: LPC55S28
package_id: LPC55S28JBD100
mcu_data: ksdk2_0
processor_version: 8.0.3
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm33_core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '92', peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI_DATA, pin_signal: PIO0_29/FC0_RXD_SDA_MOSI_DATA/SD1_D2/CTIMER2_MAT3/SCT0_OUT8/CMP0_OUT/PLU_OUT2/SECURE_GPIO0_29,
    mode: inactive, slew_rate: standard, invert: disabled, open_drain: disabled}
  - {pin_num: '94', peripheral: FLEXCOMM0, signal: TXD_SCL_MISO_WS, pin_signal: PIO0_30/FC0_TXD_SCL_MISO_WS/SD1_D3/CTIMER0_MAT0/SCT0_OUT9/SECURE_GPIO0_30, mode: inactive,
    slew_rate: standard, invert: disabled, open_drain: disabled}
  - {pin_num: '6', peripheral: SDIF, signal: SD0_CLK, pin_signal: PIO0_7/FC3_RTS_SCL_SSEL1/SD0_CLK/FC5_SCK/FC1_SCK/SECURE_GPIO0_7, slew_rate: fast}
  - {pin_num: '26', peripheral: SDIF, signal: SD0_CMD, pin_signal: PIO0_8/FC3_SSEL3/SD0_CMD/FC5_RXD_SDA_MOSI_DATA/SWO/SECURE_GPIO0_8, slew_rate: fast}
  - {pin_num: '55', peripheral: SDIF, signal: SD0_POW_EN, pin_signal: PIO0_9/FC3_SSEL2/SD0_POW_EN/FC5_TXD_SCL_MISO_WS/SECURE_GPIO0_9/ACMP0_B, asw: enabled}
  - {pin_num: '70', peripheral: SDIF, signal: 'SD0_D, 0', pin_signal: PIO0_24/FC0_RXD_SDA_MOSI_DATA/SD0_D0/CT_INP8/SCT_GPI0/SECURE_GPIO0_24, slew_rate: fast}
  - {pin_num: '79', peripheral: SDIF, signal: 'SD0_D, 1', pin_signal: PIO0_25/FC0_TXD_SCL_MISO_WS/SD0_D1/CT_INP9/SCT_GPI1/SECURE_GPIO0_25, slew_rate: fast}
  - {pin_num: '23', peripheral: SDIF, signal: 'SD0_D, 2', pin_signal: PIO0_31/FC0_CTS_SDA_SSEL0/SD0_D2/CTIMER0_MAT1/SCT0_OUT3/SECURE_GPIO0_31/ADC0_3, slew_rate: fast,
    asw: enabled}
  - {pin_num: '11', peripheral: SDIF, signal: 'SD0_D, 3', pin_signal: PIO1_0/FC0_RTS_SCL_SSEL1/SD0_D3/CT_INP2/SCT_GPI4/PLU_OUT3/ADC0_11, slew_rate: fast, asw: enabled}
  - {pin_num: '22', peripheral: SDIF, signal: SD0_WR_PRT, pin_signal: PIO0_15/FC6_CTS_SDA_SSEL0/UTICK_CAP2/CT_INP16/SCT0_OUT2/SD0_WR_PRT/SECURE_GPIO0_15/ADC0_2, asw: enabled}
  - {pin_num: '8', peripheral: SDIF, signal: SD0_CARD_DET, pin_signal: PIO0_17/FC4_SSEL2/SD0_CARD_DET_N/SCT_GPI7/SCT0_OUT0/SD0_CARD_INT_N/PLU_IN2/SECURE_GPIO0_17}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M33 (Core #0) */
void BOARD_InitPins(void)
{
    /* Enables the clock for the I/O controller.: Enable Clock. */
    CLOCK_EnableClock(kCLOCK_Iocon);

    IOCON->PIO[0][15] = ((IOCON->PIO[0][15] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT015 (pin 22) is configured as SD0_WR_PRT. */
                         | IOCON_PIO_FUNC(PIO0_15_FUNC_ALT5)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_15_DIGIMODE_DIGITAL)

                         /* Analog switch input control.
                          * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                          * PIO1_9 analog switch is closed (enabled). */
                         | IOCON_PIO_ASW(PIO0_15_ASW_VALUE1));

    IOCON->PIO[0][17] = ((IOCON->PIO[0][17] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT017 (pin 8) is configured as SD0_CARD_DET_N. */
                         | IOCON_PIO_FUNC(PIO0_17_FUNC_ALT2)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_17_DIGIMODE_DIGITAL));

    IOCON->PIO[0][24] = ((IOCON->PIO[0][24] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_SLEW_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT024 (pin 70) is configured as SD0_D0. */
                         | IOCON_PIO_FUNC(PIO0_24_FUNC_ALT2)

                         /* Driver slew rate.
                          * : Fast-mode, output slew rate is faster.
                          * Refer to the appropriate specific device data sheet for details. */
                         | IOCON_PIO_SLEW(PIO0_24_SLEW_FAST)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_24_DIGIMODE_DIGITAL));

    IOCON->PIO[0][25] = ((IOCON->PIO[0][25] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_SLEW_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT025 (pin 79) is configured as SD0_D1. */
                         | IOCON_PIO_FUNC(PIO0_25_FUNC_ALT2)

                         /* Driver slew rate.
                          * : Fast-mode, output slew rate is faster.
                          * Refer to the appropriate specific device data sheet for details. */
                         | IOCON_PIO_SLEW(PIO0_25_SLEW_FAST)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_25_DIGIMODE_DIGITAL));

    const uint32_t port0_pin29_config = (/* Pin is configured as FC0_RXD_SDA_MOSI_DATA */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN29 (coords: 92) is configured as FC0_RXD_SDA_MOSI_DATA */
    IOCON_PinMuxSet(IOCON, 0U, 29U, port0_pin29_config);

    const uint32_t port0_pin30_config = (/* Pin is configured as FC0_TXD_SCL_MISO_WS */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN30 (coords: 94) is configured as FC0_TXD_SCL_MISO_WS */
    IOCON_PinMuxSet(IOCON, 0U, 30U, port0_pin30_config);

    IOCON->PIO[0][31] = ((IOCON->PIO[0][31] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_SLEW_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT031 (pin 23) is configured as SD0_D2. */
                         | IOCON_PIO_FUNC(PIO0_31_FUNC_ALT2)

                         /* Driver slew rate.
                          * : Fast-mode, output slew rate is faster.
                          * Refer to the appropriate specific device data sheet for details. */
                         | IOCON_PIO_SLEW(PIO0_31_SLEW_FAST)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_31_DIGIMODE_DIGITAL)

                         /* Analog switch input control.
                          * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                          * PIO1_9 analog switch is closed (enabled). */
                         | IOCON_PIO_ASW(PIO0_31_ASW_VALUE1));

    IOCON->PIO[0][7] = ((IOCON->PIO[0][7] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_SLEW_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT07 (pin 6) is configured as SD0_CLK. */
                        | IOCON_PIO_FUNC(PIO0_7_FUNC_ALT2)

                        /* Driver slew rate.
                         * : Fast-mode, output slew rate is faster.
                         * Refer to the appropriate specific device data sheet for details. */
                        | IOCON_PIO_SLEW(PIO0_7_SLEW_FAST)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_7_DIGIMODE_DIGITAL));

    IOCON->PIO[0][8] = ((IOCON->PIO[0][8] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_SLEW_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT08 (pin 26) is configured as SD0_CMD. */
                        | IOCON_PIO_FUNC(PIO0_8_FUNC_ALT2)

                        /* Driver slew rate.
                         * : Fast-mode, output slew rate is faster.
                         * Refer to the appropriate specific device data sheet for details. */
                        | IOCON_PIO_SLEW(PIO0_8_SLEW_FAST)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_8_DIGIMODE_DIGITAL));

    IOCON->PIO[0][9] = ((IOCON->PIO[0][9] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                        /* Selects pin function.
                         * : PORT09 (pin 55) is configured as SD0_POW_EN. */
                        | IOCON_PIO_FUNC(PIO0_9_FUNC_ALT2)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_9_DIGIMODE_DIGITAL)

                        /* Analog switch input control.
                         * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                         * PIO1_9 analog switch is closed (enabled). */
                        | IOCON_PIO_ASW(PIO0_9_ASW_VALUE1));

    IOCON->PIO[1][0] = ((IOCON->PIO[1][0] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_SLEW_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                        /* Selects pin function.
                         * : PORT10 (pin 11) is configured as SD0_D3. */
                        | IOCON_PIO_FUNC(PIO1_0_FUNC_ALT2)

                        /* Driver slew rate.
                         * : Fast-mode, output slew rate is faster.
                         * Refer to the appropriate specific device data sheet for details. */
                        | IOCON_PIO_SLEW(PIO1_0_SLEW_FAST)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_0_DIGIMODE_DIGITAL)

                        /* Analog switch input control.
                         * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                         * PIO1_9 analog switch is closed (enabled). */
                        | IOCON_PIO_ASW(PIO1_0_ASW_VALUE1));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
