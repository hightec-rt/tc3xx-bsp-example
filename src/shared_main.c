/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * DESCRIPTION:
 *
 *    Application main file supporting multicore execution implemented as shared code.
 *
 *************************************************************************************************/

#include "bsp.h"
#include "main.h"


/* ================================================================================================
 * SYMBOLS
 * ==============================================================================================*/

/* Time Base Period - each Core sets its period derived from this base */
#define TIMER_BASE_PERIOD    (250 * UC_NB_TICKS_1MS)

/* Timer Interrupt priority the same on each core */
#define TIMER_INTERRUPT_PRIO    10


/* ================================================================================================
 * FUNCTIONS
 * ==============================================================================================*/

/* ------------------------------------------------------------------------------------------------
 * FUNCTION: TimerMulticoreIsrHandler()
 *
 * Shared code implementation of interrupt handler for BSP Timer.
 * Each core executes three operations
 * 1. Toggle Core's LED
 * 2. Reloads STM module (each core controls on STM module)
 * 3. Clears STM interrupt flag
 * ------------------------------------------------------------------------------------------------
 */
void TimerMulticoreIsrHandler(void)
{
    /* Use BSP API to get current CoreId */
    uint32_t coreId = bsp_uc_core_GetCurrentCore();

    /* Get Core dependent Time period */
    uint32_t corePeriod = (coreId + 1) * TIMER_BASE_PERIOD;

    /* Interrupt Action based on current CoreId */
    bsp_board_led_Set((BOARD_LED_e) coreId, BOARD_LED_SET_TOGGLE);
    bsp_uc_stm_ReloadChannel(coreId, corePeriod);
    bsp_uc_stm_ClearChannelIsrFlag(coreId);
}

/* ------------------------------------------------------------------------------------------------
 * FUNCTION: shared_main()
 *
 * Shared entry point if there are more core present in uC derivative.
 * It is called by crt0 startup code after crt0 finishes 'C' runtime environment initialization.
 *
 * To get a HW platform in an expected state, the initialization is done within Crt0PostInit
 * hook called before entering shared_main from crt0.
 * ------------------------------------------------------------------------------------------------
 */
void shared_main(void)
{
    /* Use BSP API to get current CoreId */
    uint32_t coreId = bsp_uc_core_GetCurrentCore();

    /* Get Core dependent Time period */
    uint32_t corePeriod = (coreId + 1U) * TIMER_BASE_PERIOD;

    /* Core dependent execution
     * 1. Register Timer Interrupt Handler to the core ISR Vector Table
     * 2. Prepare STM timer period counter
     * 3. Initialize SRC ISR router module
     * 4. Enable STM timer interrupt and start it
     */
    bsp_isr_RegisterInterruptHandler(coreId, (BspInterruptHandler) TimerMulticoreIsrHandler, TIMER_INTERRUPT_PRIO);
    bsp_uc_stm_ReloadChannel(coreId, corePeriod);
    bsp_uc_intc_stm_SetSRC(coreId, coreId, TIMER_INTERRUPT_PRIO);
    bsp_uc_stm_EnableChannelIsr(coreId);

    /* Enable External interrupts in the current Core */
    bsp_uc_intc_EnableExternalInterrupts();

    switch (coreId) {
#if (UC_NB_CORES > 0U)
        case 0U: {
            core0_main();
            break;
        }
#if (UC_NB_CORES > 1U)
        case 1U: {
            core1_main();
            break;
        }
#if (UC_NB_CORES > 2U)
        case 2U: {
            core2_main();
            break;
        }
#if (UC_NB_CORES > 3U)
        case 3U: {
            core3_main();
            break;
        }
#if (UC_NB_CORES > 4U)
        case 4U: {
            core4_main();
            break;
        }
#if (UC_NB_CORES > 5U)
        case 5U: {
            core5_main();
            break;
        }
#endif /* CORE 5 */
#endif /* CORE 4 */
#endif /* CORE 3 */
#endif /* CORE 2 */
#endif /* CORE 1 */
#endif /* CORE 0 */
        default: {
            break;
        }
    }

    /* Forever empty loop - All activity executed in periodic interrupts on each core */
    for (;;);
}

/* ------------------------------------------------------------------------------------------------
 * FUNCTION: Crt0PreInit()
 *
 *  Crt0 Hook before memory clear & copy operation take place.
 *  The code cannot rely on initialized and cleared global data !
 * ------------------------------------------------------------------------------------------------
 */
void Crt0PreInit(void)
{
    /* Use BSP API to get current CoreId */
    uint32_t coreId = bsp_uc_core_GetCurrentCore();

    /* disable Safety WATCHDOG by the RESET Core only */
    if (coreId == UC_RESET_CORE)
    {
        bsp_uc_scu_wdt_DisableSafetyWatchdog();
    }

    /* disable Core WATCHDOG */
    bsp_uc_scu_wdt_DisableCpuWatchdog();

    /* enable Core instruction cache */
    bsp_uc_core_EnableICache();
}

/* ------------------------------------------------------------------------------------------------
 * FUNCTION: Crt0PostInit()
 *
 * Crt0 Hook after complete crt0 initialization, just before shared_main() entry point is called.
 * It is the place of uC shared HW resource initialization.
 * ------------------------------------------------------------------------------------------------
 */
void Crt0PostInit(void)
{
    /* Use BSP API to get current CoreId */
    uint32_t coreId = bsp_uc_core_GetCurrentCore();

    /* Initialization of shared resources by RESET core */
    if (coreId == UC_RESET_CORE)
    {
        /* setup clock system of uC */
        bsp_uc_InitClock();

        /* disable eventual external WATCHDOG on the board (not available on litekit)*/
#if !defined(LITEKIT_TC375_V2) && !defined(LITEKIT_TCXX4_V1)
        bsp_board_wdg_Disable();
#endif

        /* switch off all supported LEDs on the board */
        bsp_board_led_InitAll(BOARD_LED_SET_OFF);

        /* start other cores */
        bsp_uc_core_StartAllCores();
    }

    /* setup ISR sub-system on each core */
    bsp_isr_InterruptInit();
}
