/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * DESCRIPTION:
 *
 *    Main interface file.
 *
 *************************************************************************************************/

#ifndef MAIN_H
#define MAIN_H

#include "bsp.h"

#if (UC_NB_CORES > 0U)
extern void core0_main(void);
#if (UC_NB_CORES > 1U)
extern void core1_main(void);
#if (UC_NB_CORES > 2U)
extern void core2_main(void);
#if (UC_NB_CORES > 3U)
extern void core3_main(void);
#if (UC_NB_CORES > 4U)
extern void core4_main(void);
#if (UC_NB_CORES > 5U)
extern void core5_main(void);
#endif /* CORE 5 */
#endif /* CORE 4 */
#endif /* CORE 3 */
#endif /* CORE 2 */
#endif /* CORE 1 */
#endif /* CORE 0 */

#endif
