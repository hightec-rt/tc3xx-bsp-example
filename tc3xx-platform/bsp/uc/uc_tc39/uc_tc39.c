/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * UC SUPPORT:
 *
 *    TC39x
 *
 * DESCRIPTION:
 *
 *    Initialization and fixes for TC39 device.
 *
 *************************************************************************************************/


/* uC derivative protection guard */
#ifdef __TC39XX__

/* Include BSP API interface and types */
#include "bsp.h"


/* ================================================================================================
 * Specifics for TC39x step A
 * ==============================================================================================*/

#if defined(TC39XA)

#define _100MHz_  100
#define _5ms_     5000

/* ------------------------------------------------------------------------------------------------
 * FUNCTION: bsp_uc_scu_EnableXOSC()
 *
 * It enables an internal oscillator in specific way to workaround the issue with not-reliable
 * XOSC watchdog status bits
 * ------------------------------------------------------------------------------------------------
 */
void bsp_uc_scu_EnableXOSC(void)
{
    /* reset safety ENDINIT bit, any CCU write is SE protected */
    unlock_safety_wdtcon();

    /* switch fsystem to BACKUP clock in case it is not done already
     * XOSC setting change might have an impact on system timing otherwise */
    if (SCU_CCUCON0.B.CLKSEL != UC_CCU_CON0_CLKSEL_BACKUP)
    {
        while (SCU_CCUCON0.B.LCK != 0U)
            ; /* wait for register ready to write */
        SCU_CCUCON0.B.CLKSEL = UC_CCU_CON0_CLKSEL_BACKUP;
        SCU_CCUCON0.B.UP = 1; /* update CCU clock module with new parameters */
    }

    /* Enable XOSC (mode = 0 (crystel or ceramic resonator) */
    SCU_OSCCON.B.MODE = 0U;

    /* wait for stabilization of the XOSC
     * ??? enough to use OSC_WDG PLLLV and PLLHV bits
     *     for that XOSC must be selected as source for PLL
     *     1. Select XTAL as input to PLL
     *     2. Set right foscref frequency through OSCVAL
     *     3. Restart OSC WDG in PLL
     *     4. Wait for PLLLV and PLLHV status bits from OSC WDG */

    /* Select XTAL as PLL input clock to enable XOSC WDG functionality
     * PLL remains in free-running mode due to FINDIS bit */
    while (SCU_CCUCON1.B.LCK != 0U)
        ; /* wait for ready to write to reg. */
    SCU_SYSPLLCON0.B.INSEL = UC_CCU_CON1_INSEL_XOSC;
    SCU_CCUCON0.B.UP = 1; /* Update CCU module with new parameters */

    /* OSCVAL defines the divider value that generates the reference clock 'foscref'
     * that is supervised by the oscillator watchdog.
     * foscref = fOSC / (OSCVAL + 1) = ~ 2.5Mhz  => OSCVAL = (fOSC / 2.5Mhz) - 1 */
    SCU_OSCCON.B.OSCVAL = ((uint32_t)(BOARD_XTAL_CLOCK * 1000000) / 2500000) - 1;

    /* The Oscillator Watchdog is cleared and restarted
     * both PLLLV & PLLHV bits are cleared */
    SCU_OSCCON.B.OSCRES = 1U;

    /* set safety ENDINIT bit */
    lock_safety_wdtcon();

    /* The TC39x A-step oscillator watchdog results are not reliable during oscillator startup phase!
     * therefore we need 5ms delay here.
     * Without this delay startup on TriBoard-TC3x7 is not reliable */
    uc_stm_Wait(_100MHz_, _5ms_);

    /* wait until PLLLV and PLLHV flags are set */
    while ((SCU_OSCCON.B.PLLLV == 0) || (SCU_OSCCON.B.PLLHV == 0));
}

/* ------------------------------------------------------------------------------------------------
 * FUNCTION: bsp_uc_intc_SetSRC()
 *
 * Configure Interrupt mode to use on given processor.
 * The peripheral header file fields are not compatible with the latest bit fields.
 *
 * INPUT:
 * channel  : stm channel
 * coreId   : which core will handle the interrupt
 * mode     : 0/1 = SW/HW
 * ------------------------------------------------------------------------------------------------
 */
void bsp_uc_intc_stm_SetSRC(uint32_t channel, uint32_t coreId, uint32_t prio)
{
    Ifx_SRC *const module_src = (Ifx_SRC *)&MODULE_SRC;
    int tos;

    /* Due to Type of Service Control numbering order. See Service Request Control Register (SRC) description */
    if (coreId != 0)
        tos = coreId + 1;

    /* set processor and priority values */
    module_src->STM.STM[channel].SR0.B.TOS = tos;
    module_src->STM.STM[channel].SR0.B.SRPN = prio;

    /* ... and enable it */
    module_src->STM.STM[channel].SR0.B.SRE = 1;
}

#endif /* if defined(TC39XA) */


/* ================================================================================================
 * Specifics for TC39x step B
 * ==============================================================================================*/

#if defined(TC39XB)

#endif /* if defined(TC39XB) */

#endif /* uC protection guard */
