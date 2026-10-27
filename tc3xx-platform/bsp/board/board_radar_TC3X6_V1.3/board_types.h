/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    Radar Board TC3X6 V1.3
 *
 * UC SUPPORT:
 *
 *    TC356, TC336_EXT
 *
 * DESCRIPTION:
 *
 *    Board specific types.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined (RADAR_TC3X6_V1_3)

#ifndef BOARD_TYPES_H
#define BOARD_TYPES_H


/* PORT LEDs */
typedef enum
{
    BOARD_LED_0 = 0,
    BOARD_LED_1,
    BOARD_LED_2,
    BOARD_NB_LEDS
} BOARD_LED_e;

/* PORT OUTPUT control */
typedef enum
{
    BOARD_LED_SET_NO_CHANGE = 0,
    BOARD_LED_SET_OFF       = 1,
    BOARD_LED_SET_ON        = 2,
    BOARD_LED_SET_TOGGLE    = 3,
} BOARD_LED_SET_e;


#endif /* BOARD_TYPES_H */
#endif /* RADAR_TC3X6_V1_3 */
