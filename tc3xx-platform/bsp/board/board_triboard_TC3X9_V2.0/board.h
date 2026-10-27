/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    TriBoard TC3X9 V2.0
 *
 * UC SUPPORT:
 *
 *    TC399, TC389 (LFBGA-516 Package)
 *    TC397, TC387 (LFBGA-292 Package)
 *
 * DESCRIPTION:
 *
 *    Board support package specification and types.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined(TRIBOARD_TC3X9_V2_0)

#ifndef BOARD_H
#define BOARD_H


/* BSP Board low level specification header files */
#include "board_spec.h"
#include "board_types.h"

/* LED Board configuration array declaration */
extern const BOARD_LED_S board_led[BOARD_NB_LEDS];


#endif /* BOARD_H */
#endif /* TRIBOARD_TC3X9_V2_0 */
