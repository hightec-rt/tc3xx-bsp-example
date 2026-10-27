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

#if (UC_NB_CORES > 3U)

TOOLCHAIN_SECTION_BSS_START(".CPU3.bss");
volatile uint32_t core3_bss_var;
TOOLCHAIN_SECTION_BSS_END();

TOOLCHAIN_SECTION_DATA_START(".CPU3.data");
volatile uint32_t core3_data_var = 1U;
TOOLCHAIN_SECTION_DATA_END();

TOOLCHAIN_SECTION_RODATA_START(".CPU3.rodata");
volatile const uint32_t core3_rodata_var = 2U;
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_TEXT_START(".CPU3.ramcode");
void core3_main(void)
{
    for (;;)
    {
        uint32_t i;

        for (i = 0U; i < UC_NB_TICKS_1MS; i++) {}

        core3_bss_var += core3_rodata_var;
        core3_data_var += core3_rodata_var;
    }
}
TOOLCHAIN_SECTION_TEXT_END();

#endif /* CORE 3 */
