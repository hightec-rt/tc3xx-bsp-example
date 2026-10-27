/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * UC SUPPORT:
 *
 *    TC33xx
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
 * TC33XA MEMORY REGIONS
 * ==============================================================================================*/

MEMORY
{
  /* User configuration block - BMHD headers only */
  ucb_bmhd_orig (rx):  org = 0xaf400000, len = 2K
  ucb_bmhd_copy (rx):  org = 0xaf401000, len = 2K

  /* Program Flash memory - cached region */
  int_flash0 (rx):     org = 0x80000000, len = 2M

  /* Program scratchpad memories */
  pspr_cpu0 (rx):      org = 0x70100000, len = 8K

  /* Data scratchpad memories */
  dspr_cpu0 (w!x):     org = 0x70000000, len = 192K

  /* Distributed LMU RAM - Non-Cached regions selected
   * Local core access is always non-cached */
  dlmu_cpu0 (wx):      org = 0xB0000000, len = 8K

  /* Periphery memory space region */
  periphery_base :     org = 0xF0000000, len = 0
  periphery_end  :     org = 0xFFFF0000, len = 0
}

/* ================================================================================================
 * MEMORY REGION SYMBOLS
 * ==============================================================================================*/

/* Internal Flash memory */
INT_FLASH_MEMORY_BASE = ORIGIN(int_flash0);
INT_FLASH_MEMORY_SIZE = 2M;
