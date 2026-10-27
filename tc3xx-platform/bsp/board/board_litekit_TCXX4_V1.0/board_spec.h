/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    LiteKit TCxx4 V1
 *
 * UC SUPPORT:
 *
 *    TCxx4
 *
 * DESCRIPTION:
 *
 *    Board specification file.
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined (LITEKIT_TCXX4_V1)

#ifndef BOARD_SPEC_H
#define BOARD_SPEC_H


/* ------------------------------------------------------------------------------------------------
 * External crystal clock in [MHz]
 *    It can be overridden by the user, in case the board is populated with a different crystal
 * ----------------------------------------------------------------------------------------------*/

#ifndef BOARD_XTAL_CLOCK
#define BOARD_XTAL_CLOCK               20
#endif

#endif /* BOARD_SPEC_H */
#endif /* LITEKIT_TCXX4_V1 */
