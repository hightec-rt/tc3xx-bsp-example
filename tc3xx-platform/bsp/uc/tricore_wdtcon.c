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
 *    Low Level Driver for watchdog timer for AURIX TC3xx uC family.
 *
 *************************************************************************************************/

/* Lock/unlock the ENDINIT bit in WDTCON to gain write access
   for ENDINIT-protected SFRs (such as BIV, BTV and the CLC
   registers of the various core functional blocks).  */


#include "toolchain.h"

#if defined(__TC161__) || defined(__TC162__)

void unlock_wdtcon(void);
void lock_wdtcon(void);
void unlock_safety_wdtcon(void);
void lock_safety_wdtcon(void);

typedef struct
{
    unsigned int _con0;
} WdtCon_t;


/* on the AURIX (TC27XX) and AURIX 2G (TC39XX) each core has its own WDTCON address
   therefore we need special read/write-function to the wdtcon0/1
   registers
   */
#define CORE_ID_ADDR            0xFE1C
#define CORE_ID_MASK            0x00000007
#if defined(__TC161__)
#define WDTCON_BASE_ADDR        0xF0036100
#define WDTCON_CPU_STRIDE       0x0C
/* safety watchdog */
#define WDTS_BASE_ADDR          0xF00360F0
#elif defined(__TC162__)
#define WDTCON_BASE_ADDR        0xF003624C
#define WDTCON_CPU_STRIDE       0x0C
/* safety watchdog */
#define WDTS_BASE_ADDR          0xF00362A8
#endif /* __TC161__ */

static __inline WdtCon_t * __getWdtBase(void)
{
    unsigned int coreId;

    /* get the core ID from CPU_ID (csfr_base + 0xfe1c) */
    coreId = TOOLCHAIN_MFCR(CORE_ID_ADDR) & CORE_ID_MASK;

#if defined(__TC162__)
    /* special mapping for CPU5: CORE_ID == 6 */
    if (coreId == 6)
    {
        coreId = 5;
    }
#endif /* __TC162__ */

    return (WdtCon_t *)(WDTCON_BASE_ADDR + (coreId * WDTCON_CPU_STRIDE));
}

static __inline WdtCon_t * __getWdtsBase(void)
{
    return (WdtCon_t *)(WDTS_BASE_ADDR);
}


/* Unlock (reset) the ENDINIT bit.  */
TOOLCHAIN_SECTION_TEXT_START(".text.semihost.unlock_wdtcon");
void unlock_wdtcon(void)
{
    unsigned int passwd;
    volatile WdtCon_t *wdtaddr;

    wdtaddr = __getWdtBase();

    passwd  = wdtaddr->_con0;
    passwd &= 0xffffff00;
    wdtaddr->_con0 = passwd | 0xf1;
    TOOLCHAIN_DSYNC();
    wdtaddr->_con0 = passwd | 0xf2;
    /* read back new value ==> synchronise LFI */
    passwd = wdtaddr->_con0;
}
TOOLCHAIN_SECTION_TEXT_END();

/* Lock (set) the ENDINIT bit.  */
TOOLCHAIN_SECTION_TEXT_START(".text.semihost.lock_wdtcon");
void lock_wdtcon(void)
{
    unsigned int passwd;
    volatile WdtCon_t *wdtaddr;

    wdtaddr = __getWdtBase();

    passwd  = wdtaddr->_con0;
    passwd &= 0xffffff00;
    wdtaddr->_con0 = passwd | 0xf1;
    TOOLCHAIN_DSYNC();
    passwd |= 3;
    wdtaddr->_con0 = passwd | 0xf2;
    /* read back new value ==> synchronise LFI */
    passwd = wdtaddr->_con0;
}
TOOLCHAIN_SECTION_TEXT_END();

/* Unlock (reset) the SAFETY ENDINIT bit.  */
TOOLCHAIN_SECTION_TEXT_START(".text.semihost.unlock_safety_wdtcon");
void unlock_safety_wdtcon(void)
{
    unsigned int passwd;
    volatile WdtCon_t *wdtaddr;

    wdtaddr = __getWdtsBase();

    passwd  = wdtaddr->_con0;
    passwd &= 0xffffff00;
    wdtaddr->_con0 = passwd | 0xf1;
    TOOLCHAIN_DSYNC();
    wdtaddr->_con0 = passwd | 0xf2;
    /* read back new value ==> synchronise LFI */
    passwd = wdtaddr->_con0;
}
TOOLCHAIN_SECTION_TEXT_END();

/* Lock (set) the SAFETY ENDINIT bit.  */
TOOLCHAIN_SECTION_TEXT_START(".text.semihost.lock_safety_wdtcon");
void lock_safety_wdtcon(void)
{
    unsigned int passwd;
    volatile WdtCon_t *wdtaddr;

    wdtaddr = __getWdtsBase();

    passwd  = wdtaddr->_con0;
    passwd &= 0xffffff00;
    wdtaddr->_con0 = passwd | 0xf1;
    TOOLCHAIN_DSYNC();
    passwd |= 3;
    wdtaddr->_con0 = passwd | 0xf2;
    /* read back new value ==> synchronise LFI */
    passwd = wdtaddr->_con0;
}
TOOLCHAIN_SECTION_TEXT_END();

#endif /* __TC161__ || __TC162__ */
