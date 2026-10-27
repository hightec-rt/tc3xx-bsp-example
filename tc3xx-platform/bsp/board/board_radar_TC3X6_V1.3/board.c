/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    Radar Base board TC3X6 V1.3
 *
 * UC SUPPORT:
 *
 *    TC356, TC336_EXT
 *
 * DESCRIPTION:
 *
 *    Implementation of Board support routines.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined (RADAR_TC3X6_V1_3)

/* include common BSP header file */
#include "bsp.h"


/* ------------------------------------------------------------------------------------------------
 * Board LED port-pin setup
 *    The EVB has only 4 on-board LEDs, the rest is GPIOs
 * ----------------------------------------------------------------------------------------------*/

const BOARD_LED_S board_led[BOARD_NB_LEDS] =
{
    {02, 1}, /* LED_0 Blue */
    {02, 2}, /* LED_1 Red */
    {02, 8}, /* LED_2 Green */
};

#endif /* RADAR_TC3X6_V1_3 */
