/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * UC SUPPORT:
 *
 *    TC39xA
 *
 * DESCRIPTION:
 *
 *    uC family memory region definition file.
 *    Not all available memory regions are defined, only those used in BSP example.
 *    It includes the application linker files locating sections to memory regions at the end.
 *
 *************************************************************************************************/

OUTPUT_FORMAT("elf32-tricore")
OUTPUT_ARCH(tricore)
ENTRY(_crt0_reset)


/* ================================================================================================
 * TC39XA MEMORY REGIONS
 * ==============================================================================================*/

MEMORY
{
    /* User configuration block - BMHD headers only */
    ucb_bmhd_orig (rx):  org = 0xaf400000, len = 2K
    ucb_bmhd_copy (rx):  org = 0xaf401000, len = 2K

    /* Program Flash memory - cached region */
    int_flash0 (rx):     org = 0x80000000, len = 3M
    int_flash1 (rx):     org = 0x80300000, len = 3M
    int_flash2 (rx):     org = 0x80600000, len = 3M
    int_flash3 (rx):     org = 0x80900000, len = 3M
    int_flash4 (rx):     org = 0x80C00000, len = 3M
    int_flash5 (rx):     org = 0x80F00000, len = 1M

    /* Program scratchpad memories */
    pspr_cpu0 (rx):      org = 0x70100000, len = 64K
    pspr_cpu1 (rx):      org = 0x60100000, len = 64K
    pspr_cpu2 (rx):      org = 0x50100000, len = 64K
    pspr_cpu3 (rx):      org = 0x40100000, len = 64K
    pspr_cpu4 (rx):      org = 0x30100000, len = 64K
    pspr_cpu5 (rx):      org = 0x10100000, len = 64K

    /* Data scratchpad memories */
    dspr_cpu0 (w!x):     org = 0x70000000, len = 96K
    dspr_cpu1 (w!x):     org = 0x60000000, len = 96K
    dspr_cpu2 (w!x):     org = 0x50000000, len = 96K
    dspr_cpu3 (w!x):     org = 0x40000000, len = 96K
    dspr_cpu4 (w!x):     org = 0x30000000, len = 96K
    dspr_cpu5 (w!x):     org = 0x10000000, len = 96K

    /* Distributed LMU RAM - Non-Cached regions selected
     * Local core access is always non-cached */
    dlmu_cpu0 (wx):      org = 0xB0000000, len = 64K
    dlmu_cpu1 (wx):      org = 0xB0010000, len = 64K
    dlmu_cpu2 (wx):      org = 0xB0020000, len = 64K
    dlmu_cpu3 (wx):      org = 0xB0030000, len = 64K
    dlmu_cpu4 (wx):      org = 0xB0140000, len = 64K
    dlmu_cpu5 (wx):      org = 0xB0150000, len = 64K

    /* Global LMU - Local memory Unit */
    lmu0_cached (wx):    org = 0x90040000, len = 256K
    lmu1_cached (wx):    org = 0x90080000, len = 256K
    lmu2_cached (wx):    org = 0x900C0000, len = 256K
    lmu3_cached (wx):    org = 0x90100000, len = 256K
    lmu0_noncached (wx): org = 0xB0040000, len = 256K
    lmu1_noncached (wx): org = 0xB0080000, len = 256K
    lmu2_noncached (wx): org = 0xB00C0000, len = 256K
    lmu3_noncached (wx): org = 0xB0100000, len = 256K

    /* Periphery memory space region */
    periphery_base :     org = 0xF0000000, len = 0
    periphery_end  :     org = 0xFFFF0000, len = 0
}

/* memory mirrors describe same physical memory accessible by different addresses */
/* "REGION_MIRROR" keyword is not supported by LLVM linker!
REGION_MIRROR("lmu0_cached", "lmu0_noncached")
REGION_MIRROR("lmu1_cached", "lmu1_noncached")
REGION_MIRROR("lmu2_cached", "lmu2_noncached")
REGION_MIRROR("lmu3_cached", "lmu3_noncached")
*/

/* ================================================================================================
 * MEMORY REGION SYMBOLS
 * ==============================================================================================*/

/* Internal Flash memory */
INT_FLASH_MEMORY_BASE = ORIGIN(int_flash0);
INT_FLASH_MEMORY_SIZE = 16M;
