/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    TriBoard TC3X5 V1.X
 *
 * UC SUPPORT:
 *
 *    TC375, TC365 (LQFP-176 Package)
 *
 * DESCRIPTION:
 *
 *    Board support package specification and types.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined(TRIBOARD_TC3X5_V1_X)

#ifndef BOARD_H
#define BOARD_H


/* BSP Board low level specification header files */
#include "board_spec.h"
#include "board_types.h"

/* LED Board configuration array declaration */
extern const BOARD_LED_S board_led[BOARD_NB_LEDS];


#endif /* BOARD_H */
#endif /* TRIBOARD_TC3X5_V1_X */
