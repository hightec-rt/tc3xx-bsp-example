/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * BOARD FAMILY:
 *
 *    Radar board TC3X6 V1.3
 *
 * UC SUPPORT:
 *
 *    TC356, TC336_EXT
 *
 * DESCRIPTION:
 *
 *    Board specification file
 *
 *************************************************************************************************/

/* board implementation guard */
#if defined (RADAR_TC3X6_V1_3)

#ifndef BOARD_SPEC_H
#define BOARD_SPEC_H


/* ------------------------------------------------------------------------------------------------
 * External crystal clock in [MHz]
 *    It can be overridden by the user, in case the board is populated with a different crystal
 * ----------------------------------------------------------------------------------------------*/

#ifndef BOARD_XTAL_CLOCK
#define BOARD_XTAL_CLOCK               20
#endif


/* ------------------------------------------------------------------------------------------------
 * OnBoard External WATCHDOG specification (SBC chip)
 *    Board QSPI module and GPIO mapping
 * ----------------------------------------------------------------------------------------------*/

/* External WATCHDOG not presence on the board */
#define BOARD_NO_EXTERNAL_WDG          1


#endif /* BOARD_SPEC_H */
#endif /* RADAR_TC3X6_V1_3 */
