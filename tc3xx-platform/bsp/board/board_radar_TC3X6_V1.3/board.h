/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *     Radar Board TC3X6 V1.3
 *
 * UC SUPPORT:
 *
 *     TC356, TC336_EXT
 *
 * DESCRIPTION:
 *
 *     Board support package specification and types.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined (RADAR_TC3X6_V1_3)

#ifndef BOARD_H
#define BOARD_H


/* BSP Board low level specification header files */
#include "board_spec.h"
#include "board_types.h"

/* Board configuration */
extern const BOARD_LED_S board_led[BOARD_NB_LEDS];


#endif /* BOARD_H */
#endif /* RADAR_TC3X6_V1_3 */
