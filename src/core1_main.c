/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * DESCRIPTION:
 *
 *    Application core specific main file.
 *
 *************************************************************************************************/

#include <stdint.h>
#include "main.h"

#if (UC_NB_CORES > 1U)

TOOLCHAIN_SECTION_BSS_START(".CPU1.bss");
volatile uint32_t core1_bss_var;
TOOLCHAIN_SECTION_BSS_END();

TOOLCHAIN_SECTION_DATA_START(".CPU1.data");
volatile uint32_t core1_data_var = 1U;
TOOLCHAIN_SECTION_DATA_END();

TOOLCHAIN_SECTION_RODATA_START(".CPU1.rodata");
volatile const uint32_t core1_rodata_var = 2U;
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_TEXT_START(".CPU1.ramcode");
void core1_main(void)
{
    for (;;)
    {
        uint32_t i;

        for (i = 0U; i < UC_NB_TICKS_1MS; i++) {}

        core1_bss_var += core1_rodata_var;
        core1_data_var += core1_rodata_var;
    }
}
TOOLCHAIN_SECTION_TEXT_END();

#endif /* CORE 1 */
