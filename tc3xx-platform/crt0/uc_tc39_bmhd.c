/**************************************************************************************************
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2015-2026 HighTec EDV-Systeme GmbH.
 * All rights reserved.
 *************************************************************************************************/

/**************************************************************************************************
 * UC SUPPORT:
 *
 *    TC39x
 *
 * DESCRIPTION:
 *
 *    Boot Header Mode read by uC firmware after the reset at fixed location.
 *    Each uC has fixed structure how BMHD array looks like
 *
 *************************************************************************************************/

/* uC derivative protection guard */
#ifdef __TC39XX__

#include <stdint.h>
#include "toolchain.h"

/* Boot Mode Header Structure type */
typedef struct
{
    uint16_t bmi;           /**< \brief Boot Mode Index (BMI)*/
    uint16_t bmhdid;        /**< \brief Boot Mode Header ID (CODE) = B359H*/
    uint32_t stad;          /**< \brief User Code start address*/
    uint32_t crc;           /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    uint32_t crcInv;        /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    uint32_t reserved[120]; /**< \brief Reserved area till the offset 0x1F0*/
    uint32_t confirmation;  /**< \brief 32-bit CODE, (always same)*/
} IfxCpu_Bmhd;


TOOLCHAIN_SECTION_RODATA_START(".bmhd_0_orig");
/* BMHD Setting
 * Core[0-3] = LOCKSTEP ON
 * Core[4-5] = LOCKSTEP OFF
 * LBIST = OFF
 */
const IfxCpu_Bmhd bmhd_0_orig=
{
    .bmi          = 0x00FE,     /**< \brief Boot Mode Index (BMI)*/
    .bmhdid       = 0xB359,     /**< \brief Boot Mode Header ID (CODE) = B359H*/
    .stad         = 0xA0000000, /**< \brief User Code start address*/
    .crc          = 0x31795570, /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    .crcInv       = 0xCE86AA8F, /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    .confirmation = 0x43211234, /**< \brief 32-bit CODE, (always same)*/
};
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_RODATA_START(".bmhd_1_orig");
/* BMHD Setting
 * Core[0-3] = LOCKSTEP ON
 * Core[4-5] = LOCKSTEP OFF
 * LBIST = OFF
 */
const IfxCpu_Bmhd bmhd_1_orig=
{
    .bmi          = 0x00FE,     /**< \brief Boot Mode Index (BMI)*/
    .bmhdid       = 0xB359,     /**< \brief Boot Mode Header ID (CODE) = B359H*/
    .stad         = 0xA0000000, /**< \brief User Code start address*/
    .crc          = 0x31795570, /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    .crcInv       = 0xCE86AA8F, /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    .confirmation = 0x43211234, /**< \brief 32-bit CODE, (always same)*/
};
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_RODATA_START(".bmhd_2_orig");
/* BMHD Setting
 * Core[0-3] = LOCKSTEP ON
 * Core[4-5] = LOCKSTEP OFF
 * LBIST = ON
 */
const IfxCpu_Bmhd bmhd_2_orig=
{
    .bmi          = 0x01FE,     /**< \brief Boot Mode Index (BMI)*/
    .bmhdid       = 0xB359,     /**< \brief Boot Mode Header ID (CODE) = B359H*/
    .stad         = 0xA0000000, /**< \brief User Code start address*/
    .crc          = 0xFA2586D5, /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    .crcInv       = 0x05DA792A, /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    .confirmation = 0x43211234, /**< \brief 32-bit CODE, (always same)*/
};
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_RODATA_START(".bmhd_3_orig");
/* BMHD Setting
 * Core[0-3] = LOCKSTEP ON
 * Core[4-5] = LOCKSTEP OFF
 * LBIST = ON
 */
const IfxCpu_Bmhd bmhd_3_orig=
{
    .bmi          = 0x01FE,     /**< \brief Boot Mode Index (BMI)*/
    .bmhdid       = 0xB359,     /**< \brief Boot Mode Header ID (CODE) = B359H*/
    .stad         = 0xA0000000, /**< \brief User Code start address*/
    .crc          = 0xFA2586D5, /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    .crcInv       = 0x05DA792A, /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    .confirmation = 0x43211234, /**< \brief 32-bit CODE, (always same)*/
};
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_RODATA_START(".bmhd_0_copy");
/* BMHD Setting
 * Core[0-3] = LOCKSTEP ON
 * Core[4-5] = LOCKSTEP OFF
 * LBIST = OFF
 */
const IfxCpu_Bmhd bmhd_0_copy=
{
    .bmi          = 0x00FE,     /**< \brief Boot Mode Index (BMI)*/
    .bmhdid       = 0xB359,     /**< \brief Boot Mode Header ID (CODE) = B359H*/
    .stad         = 0xA0000000, /**< \brief User Code start address*/
    .crc          = 0x31795570, /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    .crcInv       = 0xCE86AA8F, /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    .confirmation = 0x43211234, /**< \brief 32-bit CODE, (always same)*/
};
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_RODATA_START(".bmhd_1_copy");
/* BMHD Setting
 * Core[0-3] = LOCKSTEP ON
 * Core[4-5] = LOCKSTEP OFF
 * LBIST = OFF
 */
const IfxCpu_Bmhd bmhd_1_copy=
{
    .bmi          = 0x00FE,     /**< \brief Boot Mode Index (BMI)*/
    .bmhdid       = 0xB359,     /**< \brief Boot Mode Header ID (CODE) = B359H*/
    .stad         = 0xA0000000, /**< \brief User Code start address*/
    .crc          = 0x31795570, /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    .crcInv       = 0xCE86AA8F, /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    .confirmation = 0x43211234, /**< \brief 32-bit CODE, (always same)*/
};
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_RODATA_START(".bmhd_2_copy");
/* BMHD Setting
 * Core[0-3] = LOCKSTEP ON
 * Core[4-5] = LOCKSTEP OFF
 * LBIST = ON
 */
const IfxCpu_Bmhd bmhd_2_copy=
{
    .bmi          = 0x01FE,     /**< \brief Boot Mode Index (BMI)*/
    .bmhdid       = 0xB359,     /**< \brief Boot Mode Header ID (CODE) = B359H*/
    .stad         = 0xA0000000, /**< \brief User Code start address*/
    .crc          = 0xFA2586D5, /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    .crcInv       = 0x05DA792A, /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    .confirmation = 0x43211234, /**< \brief 32-bit CODE, (always same)*/
};
TOOLCHAIN_SECTION_RODATA_END();


TOOLCHAIN_SECTION_RODATA_START(".bmhd_3_copy");
/* BMHD Setting
 * Core[0-3] = LOCKSTEP ON
 * Core[4-5] = LOCKSTEP OFF
 * LBIST = ON
 */
const IfxCpu_Bmhd bmhd_3_copy=
{
    .bmi          = 0x01FE,     /**< \brief Boot Mode Index (BMI)*/
    .bmhdid       = 0xB359,     /**< \brief Boot Mode Header ID (CODE) = B359H*/
    .stad         = 0xA0000000, /**< \brief User Code start address*/
    .crc          = 0xFA2586D5, /**< \brief Check Result for the BMI Header (offset 000H - 007H)*/
    .crcInv       = 0x05DA792A, /**< \brief Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    .confirmation = 0x43211234, /**< \brief 32-bit CODE, (always same)*/
};
TOOLCHAIN_SECTION_RODATA_END();

#endif /* uC protection guard */
