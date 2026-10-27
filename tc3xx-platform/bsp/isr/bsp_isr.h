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
 *    BSP Interrupt interface file
 *
 *************************************************************************************************/

#ifndef BSP_ISR_H_
#define BSP_ISR_H_


/* ================================================================================================
 * DEFINES
 * ==============================================================================================*/

/* Number of BSP supported Interrupt Vectors
 * Must correspond to number of vectors in bsp_interrupt_vector_table.c file
 * that are created manually
 */
#define BSP_INTERRUPT_MAX_VECTORS            (32U)


/* ================================================================================================
 * TYPEDEFS
 * ==============================================================================================*/

/* BSP Interrupt Handler Prototype */
typedef void (*BspInterruptHandler)(void);


/* ================================================================================================
 * EXTERN DECLARATION
 * ==============================================================================================*/

/* Default Interrupt Handler for Undefined Interrupt Handlers (not mapped to any HW module) */
extern void interrupt_undef_handler(void);


#endif /* BSP_ISR_H_ */
