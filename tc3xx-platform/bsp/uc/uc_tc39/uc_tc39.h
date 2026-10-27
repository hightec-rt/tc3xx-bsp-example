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
#ifdef __TC39XX__

#ifndef UC_TC39_H
#define UC_TC39_H

/* Check supported uC Steps, if not defined in the project setting by the user
 * the most recent uC step is selected
 */
#if !defined(TC39XA) && !defined(TC39XB)
#define TC39XB
#endif

/* Import of uC Specific header files */
#include "uc_tc39_spec.h"

/* DECLARATION OF FAMILY SPECIFIC API IMPLEMENTATIONS
 *
 * Definition of specific MACRO disables function in generic uc_bsp.c and replaces it
 * with uc_<derivative> implementation. This allows to use different header files etc.
 * that is not possible in a WEAK function system.
 *
 * MACRO:  #define <uc_fce>_UC_SPECIFIC
 */
#if defined (TC39XA)
#define BSP_UC_SCU_ENABLEXOSC_UC_SPECIFIC
#define BSP_UC_INTC_STM_SETSRC_UC_SPECIFIC

#elif defined (TC39XB)
/* nothing to override yet */

#endif

/* Include of peripheral register headers files
 */
#if defined (TC39XB)

#include "TC39xB_RegCHeaders/_Reg/Ifx_reg.h"

#include "TC39xB_RegCHeaders/_Reg/IfxAgbt_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxAsclin_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxCan_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxCbs_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxCcu6_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxConverter_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxCpu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxDam_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxDma_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxDmu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxDom_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxEbcu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxEbu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxEdsadc_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxEmem_mpu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxEmem_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxEray_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxEvadc_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxFce_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxFsi_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxGeth_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxGpt12_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxGtm_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxHsct_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxHspdm_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxHssl_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxI2c_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxInt_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxIom_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxLmu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxMcds_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxMsc_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxMtu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxPfi_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxPms_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxPmu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxPort_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxPsi5_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxPsi5s_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxQspi_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxRif_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxSbcu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxScu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxSdmmc_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxSent_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxSmu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxSpu_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxSpulckstp_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxSrc_bf.h"
#include "TC39xB_RegCHeaders/_Reg/IfxStm_bf.h"

#elif defined (TC39XA)
#include "_Reg_TC39xA_V3.0.R0/_Reg/Ifx_reg.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxAsclin_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxCan_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxCbs_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxCcu6_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxCif_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxConverter_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxCpu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxDam_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxDma_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxDmu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxDom_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxEbcu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxEbu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxEdsadc_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxEmem_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxEmemram_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxEray_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxEth_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxEvadc_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxFce_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxFsi_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxGpt12_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxGtm_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxHsct_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxHssl_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxI2c_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxInt_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxIom_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxLmu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxMinimcds_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxMsc_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxMtu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxOvc_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxPfi_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxPms_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxPmu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxPort_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxPsi5_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxPsi5s_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxQspi_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxRif_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxSbcu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxScu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxSent_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxSmu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxSpu_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxSrc_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxStm_bf.h"
#include "_Reg_TC39xA_V3.0.R0/_Reg/IfxTram_bf.h"

#endif

#endif /* UC_TC39_H */
#endif /* #ifdef __TC39XX__ */
