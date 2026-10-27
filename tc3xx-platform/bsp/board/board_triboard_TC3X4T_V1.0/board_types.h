/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    TriBoard TC3X4T V1.0
 *
 * UC SUPPORT:
 *
 *    TC364, TC334, TC324 (TQFP-144 Package)
 *
 * DESCRIPTION:
 *
 *    Board specific types.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined(TRIBOARD_TC3X4T_V1_0)

#ifndef BOARD_TYPES_H
#define BOARD_TYPES_H


/* PORT LEDs */
typedef enum {
    BOARD_LED_0 = 0,
    BOARD_LED_1,
    BOARD_LED_2,
    BOARD_LED_3,
    BOARD_LED_4,
    BOARD_LED_5,
    BOARD_LED_6,
    BOARD_LED_7,
    BOARD_NB_LEDS
} BOARD_LED_e;

/* PORT OUTPUT control */
typedef enum {
    BOARD_LED_SET_NO_CHANGE = 0,
    BOARD_LED_SET_OFF       = 1,
    BOARD_LED_SET_ON        = 2,
    BOARD_LED_SET_TOGGLE    = 3,
} BOARD_LED_SET_e;


#endif /* BOARD_TYPES_H */
#endif /* TRIBOARD_TC3X4T_V1_0 */
