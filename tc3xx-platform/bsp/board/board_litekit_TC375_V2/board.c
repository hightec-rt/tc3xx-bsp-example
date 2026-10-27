/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    LiteKit TC375 V2
 *
 * UC SUPPORT:
 *
 *    TC375 (LQFP-176 package)
 *
 * DESCRIPTION:
 *
 *    Implementation of Board support routines.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined (LITEKIT_TC375_V2)

/* include common BSP header file */
#include "bsp.h"


/* ------------------------------------------------------------------------------------------------
 * Board LED port-pin setup
 *    The EVB has only 2 on-board LEDs, the rest is GPIOs
 * ----------------------------------------------------------------------------------------------*/

const BOARD_LED_S board_led[BOARD_NB_LEDS] =
{
    {0, 5},  /* LED_0 */
    {0, 6},  /* LED_1 */
};


#endif /* #if defined (LITEKIT_TC375_V2) */
