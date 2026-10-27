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
 *    Goals
 *      1. It provides certain independence on peripheral header files
 *         from the vendor that might change from one version to another
 *         and between derivatives.
 *      2. Only those used by BSP API functions are defined. The set shall be
 *         kept on minimum to have high probability that it will works across
 *         different derivatives where changes in the module IP implementation
 *         are not expected.
 *      3. The only dependence on target register header file is due to
 *         necessity of module Base address knowledge.
 *
 *    Register definition and access
 *      X_REG
 *         represents register that can be used to read or write register
 *         value directly.
 *         Example: X_REG = VAL
 *      X_REG_BASE
 *         address of the first register from the set, where the other
 *         registers are placed with a known offset => can be calculated.
 *         The internal structure of the same HW module is assumed
 *         to be kept the same among uC derivatives
 *         Example: *(X_REG_BASE + index) = VAL
 *      X_REG_OFFSET
 *         Indirect access through Base address and correct typecast
 *         X_REG_OFFSET must correspond to the typecast size
 *         Example: *(vuintX_t*)(BASE + X_REG_OFFSET) = VAL
 *
 *************************************************************************************************/

#ifndef BSP_UC_REGDEFS_H
#define BSP_UC_REGDEFS_H


/* ================================================================================================
 * MODULE MACROS USED BY BSP LLD
 * ==============================================================================================*/

/* ------------------------------------------------------------------------------------------------
 * PORT module
 * ----------------------------------------------------------------------------------------------*/

#ifndef UC_PORT_IOCR_REG_US_SPECIFIC
#define UC_PORT_IOCR_REG(port, index) \
    (*(vuint32_t *)(UC_PORT_BASE + (0x100 * (uint32_t)(port)) + (0x10 + (4 * (index / 4)))))
#endif

#ifndef UC_PORT_IOCR_REG_BASE_UC_SPECIFIC
#define UC_PORT_IOCR_REG_BASE(port, index) \
    (vuint32_t *)(UC_PORT_BASE + (0x100 * (uint32_t)(port)) + (0x10 + (4 * (index / 4))))
#endif

#ifndef UC_PORT_PDR_REG_UC_SPECIFIC
#define UC_PORT_PDR_REG(port,index) \
    (*(vuint32_t *) (UC_PORT_BASE + (0x100 * (uint32_t)(port)) + (0x40 + (4 * (index / 8)))))
#endif

#ifndef UC_PORT_OUT_REG_UC_SPECIFIC
#define UC_PORT_OUT_REG(port,index) \
    (*(vuint32_t *) (UC_PORT_BASE + (0x100 * (uint32_t)(port))))
#endif

#ifndef UC_PORT_PDR_REG_BASE_UC_SPECIFIC
#define UC_PORT_PDR_REG_BASE(port, index) \
    (vuint32_t *)(UC_PORT_BASE + (0x100 * (uint32_t)(port)) + (0x40 + (4 * (index / 8))))
#endif

#ifndef UC_PORT_OMR_REG_UC_SPECIFIC
#define UC_PORT_OMR_REG(port,index) \
    (*(vuint32_t *) (UC_PORT_BASE + (0x100 * (uint32_t)(port)) + 4))
#endif

#ifndef UC_PORT_IN_REG_UC_SPECIFIC
#define UC_PORT_IN_REG(port,index) \
    (*(vuint32_t *) (UC_PORT_BASE + (0x100 * (uint32_t)(port)) + 0x24))
#endif


#endif /* UC_TC39_REGDEFS_H */
