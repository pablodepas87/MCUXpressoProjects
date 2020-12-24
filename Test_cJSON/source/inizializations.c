#include <stdio.h>
#include "pin_mux.h"
#include "board.h"
#include "fsl_power.h"


void board_init(){

	/* set BOD VBAT level to 1.65V */
	POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
	CLOCK_EnableClock(kCLOCK_InputMux);
	/* attach 12 MHz clock to FLEXCOMM0 (debug console) */
	CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

	BOARD_InitPins();
	BOARD_BootClockPLL150M();
	BOARD_InitDebugConsole();


}
