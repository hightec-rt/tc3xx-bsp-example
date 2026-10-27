/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * UC SUPPORT:
 *
 *    TC3xx
 *
 * DESCRIPTION:
 *
 *    Definition of necessary types extensions mainly required by uC register header files.
 *
 *************************************************************************************************/

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <stdint.h>

/* volatile types */

typedef volatile signed char vint8_t;
typedef volatile unsigned char vuint8_t;

typedef volatile signed short vint16_t;
typedef volatile unsigned short vuint16_t;

typedef volatile signed int vint32_t;
typedef volatile unsigned int vuint32_t;

#endif
