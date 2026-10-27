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
 *    Include of target uC header files used by BSP.
 *
 ************************************************************************************************/


/* uC derivative protection guard */
#ifdef __TC33XX__

#ifndef UC_TC33_H
#define UC_TC33_H

/* Check supported uC Steps, if not defined in the project setting by the user
 * the most recent uC step is selected
 */
#if !defined(TC33XA)
#define TC33XA
#endif

/* Import of uC Specific header files */
#include "uc_tc33_spec.h"

/* DECLARATION OF FAMILY SPECIFIC API IMPLEMENTATIONS
 *
 * Definition of specific MACRO disables function in generic uc_bsp.c and replaces it
 * with uc_<derivative> implementation. This allows to use different header files etc.
 * that is not possible in a WEAK function system.
 *
 * MACRO:  #define <uc_fce>_UC_SPECIFIC
 */
#if defined (TC33XA)

#endif

/* Include of peripheral register headers files
 */
#if defined (TC33XA)

#include "TC33x32x_RegCHeaders/_Reg/Ifx_reg.h"

#include "TC33x32x_RegCHeaders/_Reg/IfxAsclin_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxCan_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxCbs_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxCcu6_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxConverter_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxCpu_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxDma_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxDmu_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxDom_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxEray_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxEvadc_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxFce_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxFsi_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxGpt12_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxGtm_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxInt_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxIom_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxMtu_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxPfi_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxPms_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxPmu_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxPort_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxQspi_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxSbcu_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxScu_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxSent_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxSmu_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxSrc_bf.h"
#include "TC33x32x_RegCHeaders/_Reg/IfxStm_bf.h"

#endif

#endif /* UC_TC33_H */
#endif /* uC protection guard */
