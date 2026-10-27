/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    AppKit TC3X7 V2.0
 *
 * UC SUPPORT:
 *
 *    TC397, TC387 (LFBA-292 Package)
 *
 * DESCRIPTION:
 *
 *    Board support package specification and types.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined (APPKIT_TC3X7_V2_0)

#ifndef BOARD_H
#define BOARD_H


/* BSP Board low level specification header files */
#include "board_spec.h"
#include "board_types.h"

/* Board configuration */
extern const BOARD_LED_S board_led[BOARD_NB_LEDS];


#endif /* BOARD_H */
#endif /* APPKIT_TC3X7_V2_0 */
