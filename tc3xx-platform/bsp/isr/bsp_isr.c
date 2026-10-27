/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * UC SUPPORT:
 *
 *    TC3xx
 *
 * DESCRIPTION:
 *
 *    Initialization of the Core's interrupt system (BIV register).
 *    Each core has its own interrupt vector table provided by this BSP.
 *    Initialization of the trap system (BTV register).
 *    Each core has a common tape vector table provided by this BSP.
 *
 ************************************************************************************************/

/* include BSP API interface */
#include "bsp.h"

/* implement only when BSP provides HW Interrupt support */
#ifndef BSP_INTERRUPT_SUPPORT_DISABLED


/* ================================================================================================
 * Undefined handler implementation
 * ==============================================================================================*/

void interrupt_undef_handler(void)
{
    __asm ("debug");
    for (;;);
}


/* ================================================================================================
 * Trap and Interrupt vector table for each uC core
 * ==============================================================================================*/

extern uint32_t* BSP_INTERRUPT_VECTOR_TABLE_CPU0;

#if (UC_NB_CORES > 1)
extern uint32_t* BSP_INTERRUPT_VECTOR_TABLE_CPU1;

#if (UC_NB_CORES > 2)
extern uint32_t* BSP_INTERRUPT_VECTOR_TABLE_CPU2;

#if (UC_NB_CORES > 3)
extern uint32_t* BSP_INTERRUPT_VECTOR_TABLE_CPU3;

#if (UC_NB_CORES > 4)
extern uint32_t* BSP_INTERRUPT_VECTOR_TABLE_CPU4;

#if (UC_NB_CORES > 5)
extern uint32_t* BSP_INTERRUPT_VECTOR_TABLE_CPU5;

#endif /* CORE 5 */
#endif /* CORE 4 */
#endif /* CORE 3 */
#endif /* CORE 2 */
#endif /* CORE 1 */


/* ================================================================================================
 * BSP interrupt vector table for each core
 * in case the RAM version is configured
 * ==============================================================================================*/

TOOLCHAIN_SECTION_BSS_START(".bsp_ram_interrupt_vector_table_cpu0");
BspInterruptHandler BspRamInterruptVectorTable_Cpu0[BSP_INTERRUPT_MAX_VECTORS];
TOOLCHAIN_SECTION_BSS_END();

#if (UC_NB_CORES > 1)
TOOLCHAIN_SECTION_BSS_START(".bsp_ram_interrupt_vector_table_cpu1");
BspInterruptHandler BspRamInterruptVectorTable_Cpu1[BSP_INTERRUPT_MAX_VECTORS];
TOOLCHAIN_SECTION_BSS_END();

#if (UC_NB_CORES > 2)
TOOLCHAIN_SECTION_BSS_START(".bsp_ram_interrupt_vector_table_cpu2");
BspInterruptHandler BspRamInterruptVectorTable_Cpu2[BSP_INTERRUPT_MAX_VECTORS];
TOOLCHAIN_SECTION_BSS_END();

#if (UC_NB_CORES > 3)
TOOLCHAIN_SECTION_BSS_START(".bsp_ram_interrupt_vector_table_cpu3");
BspInterruptHandler BspRamInterruptVectorTable_Cpu3[BSP_INTERRUPT_MAX_VECTORS];
TOOLCHAIN_SECTION_BSS_END();

#if (UC_NB_CORES > 4)
TOOLCHAIN_SECTION_BSS_START(".bsp_ram_interrupt_vector_table_cpu4");
BspInterruptHandler BspRamInterruptVectorTable_Cpu4[BSP_INTERRUPT_MAX_VECTORS];
TOOLCHAIN_SECTION_BSS_END();

#if (UC_NB_CORES > 5)
TOOLCHAIN_SECTION_BSS_START(".bsp_ram_interrupt_vector_table_cpu5");
BspInterruptHandler BspRamInterruptVectorTable_Cpu5[BSP_INTERRUPT_MAX_VECTORS];
TOOLCHAIN_SECTION_BSS_END();

#endif /* CORE 5 */
#endif /* CORE 4 */
#endif /* CORE 3 */
#endif /* CORE 2 */
#endif /* CORE 1 */


/* ================================================================================================
 * ISR API
 * ==============================================================================================*/

/* ------------------------------------------------------------------------------------------------
 * FUNCTION: bsp_isr_InterruptInit
 *     It sets interrupt vector table in the corresponding Core's BIV register.
 *     It initializes RAM ISR Table with all priority vectors pointing
 *     to Undefined Handler routine.
 * ------------------------------------------------------------------------------------------------
 */
void bsp_isr_InterruptInit(void)
{
    /* holds the interrupt vector table for the requested Core */
    uint32_t interrupt_vector_table;

    /* Get current Core logical number */
    uint32_t coreId = bsp_uc_core_GetCurrentCore();

    /* Select right table */
    switch (coreId)
    {
        case UC_CORE_MAIN_0:
            interrupt_vector_table = (uint32_t) &BSP_INTERRUPT_VECTOR_TABLE_CPU0;
            break;

#if (UC_NB_CORES > 1)
        case UC_CORE_MAIN_1:
            interrupt_vector_table = (uint32_t) &BSP_INTERRUPT_VECTOR_TABLE_CPU1;
            break;

#if (UC_NB_CORES > 2)
        case UC_CORE_MAIN_2:
            interrupt_vector_table = (uint32_t) &BSP_INTERRUPT_VECTOR_TABLE_CPU2;
            break;

#if (UC_NB_CORES > 3)
        case UC_CORE_MAIN_3:
            interrupt_vector_table = (uint32_t) &BSP_INTERRUPT_VECTOR_TABLE_CPU3;
            break;

#if (UC_NB_CORES > 4)
        case UC_CORE_MAIN_4:
            interrupt_vector_table = (uint32_t) &BSP_INTERRUPT_VECTOR_TABLE_CPU4;
            break;

#if (UC_NB_CORES > 5)
        case UC_CORE_MAIN_5:
            interrupt_vector_table = (uint32_t) &BSP_INTERRUPT_VECTOR_TABLE_CPU5;
            break;

#endif /* CORE 5 */
#endif /* CORE 4 */
#endif /* CORE 3 */
#endif /* CORE 2 */
#endif /* CORE 1 */

        default:
            return; // nothing to do in case of wrong coreId parameter
    }

    /* Register the table (dispatch table) to Core BIV register
     * Set VSS = 0 to get expected 32B spacing in between vectors
     */
    bsp_uc_intc_SetBIV(interrupt_vector_table, 0);

    /* Initialize RAM Handler table entries */
    uint32_t i;
    for (i=0; i < BSP_INTERRUPT_MAX_VECTORS; i++)
        bsp_isr_RegisterInterruptHandler(coreId, (BspInterruptHandler) interrupt_undef_handler, i);
}


/* ------------------------------------------------------------------------------------------------
 * FUNCTION: bsp_isr_RegisterInterruptHandler
 *    It stores the ISR Handler coordinates in RAM table in case of
 *    selected RAM mode, otherwise does nothing
 * ------------------------------------------------------------------------------------------------
 */
void bsp_isr_RegisterInterruptHandler(uint32_t coreId, BspInterruptHandler handler, uint32_t prio)
{
    /* holds RAM Handler table for requested core */
    BspInterruptHandler *handler_table;

    /* Select right vector table */
    switch (coreId)
    {
        case UC_CORE_MAIN_0:
            handler_table = (BspInterruptHandler *) BspRamInterruptVectorTable_Cpu0;
            break;

#if (UC_NB_CORES > 1)
        case UC_CORE_MAIN_1:
            handler_table = (BspInterruptHandler *) BspRamInterruptVectorTable_Cpu1;
            break;

#if (UC_NB_CORES > 2)
        case UC_CORE_MAIN_2:
            handler_table = (BspInterruptHandler *) BspRamInterruptVectorTable_Cpu2;
            break;

#if (UC_NB_CORES > 3)
        case UC_CORE_MAIN_3:
            handler_table = (BspInterruptHandler *) BspRamInterruptVectorTable_Cpu3;
            break;

#if (UC_NB_CORES > 4)
        case UC_CORE_MAIN_4:
            handler_table = (BspInterruptHandler *) BspRamInterruptVectorTable_Cpu4;
            break;

#if (UC_NB_CORES > 5)
        case UC_CORE_MAIN_5:
            handler_table = (BspInterruptHandler *) BspRamInterruptVectorTable_Cpu5;
            break;

#endif /* CORE 5 */
#endif /* CORE 4 */
#endif /* CORE 3 */
#endif /* CORE 2 */
#endif /* CORE 1 */

        default:
            return; // nothing to do in case of wrong coreId parameter
    }

    /* Update table entry, only for supported priorities,
     * otherwise nothing happens
     */
    if (prio < BSP_INTERRUPT_MAX_VECTORS)
        handler_table[prio] = handler;
}

#endif /* BSP_INTERRUPT_SUPPORT_DISABLED */
