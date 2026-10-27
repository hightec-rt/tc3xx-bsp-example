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
 *    Toolchain abstration
 *
 *************************************************************************************************/

#ifndef TOOLCHAIN_H
#define TOOLCHAIN_H


#if defined(__clang__)
    #define COMPILER_CLANG 1
    #include <tricoreintrin.h>
    #include <wdtcon.h>

#elif defined(__GNUC__)
    #define COMPILER_GCC 1
    #include <machine/intrinsics.h>
    #include <machine/wdtcon.h>

#else
    #error "Unsupported compiler"
#endif



#if defined(__clang__)

    #define TOOLCHAIN_MTCR(id, val) __builtin_tricore_mtcr(id, val)
    #define TOOLCHAIN_MFCR(id)      __builtin_tricore_mfcr(id)
    #define TOOLCHAIN_ISYNC()       __builtin_tricore_isync()
    #define TOOLCHAIN_ENABLE()      __builtin_tricore_enable()
    #define TOOLCHAIN_DSYNC()       __builtin_tricore_dsync()

#elif defined(__GNUC__)

    #define TOOLCHAIN_MTCR(id, val) _mtcr(id, val)
    #define TOOLCHAIN_MFCR(id)      _mfcr(id)
    #define TOOLCHAIN_ISYNC()       _isync()
    #define TOOLCHAIN_ENABLE()      _enable()
    #define TOOLCHAIN_DSYNC()       _dsync()

#endif



#define TOOLCHAIN_STRINGIFY(x) #x

#if defined(__clang__)

    #define TOOLCHAIN_SECTION_TEXT_START(section_name) \
        _Pragma(TOOLCHAIN_STRINGIFY(clang section text=section_name))

    #define TOOLCHAIN_SECTION_TEXT_END() \
        _Pragma("clang section text=\"\"")


    #define TOOLCHAIN_SECTION_BSS_START(section_name) \
        _Pragma(TOOLCHAIN_STRINGIFY(clang section bss=section_name))

    #define TOOLCHAIN_SECTION_BSS_END() \
        _Pragma("clang section bss=\"\"")


    #define TOOLCHAIN_SECTION_DATA_START(section_name) \
        _Pragma(TOOLCHAIN_STRINGIFY(clang section data=section_name))

    #define TOOLCHAIN_SECTION_DATA_END() \
        _Pragma("clang section data=\"\"")


    #define TOOLCHAIN_SECTION_RODATA_START(section_name) \
        _Pragma(TOOLCHAIN_STRINGIFY(clang section rodata=section_name))

    #define TOOLCHAIN_SECTION_RODATA_END() \
        _Pragma("clang section rodata=\"\"")

#elif defined(__GNUC__)

    #define TOOLCHAIN_SECTION_TEXT_START(section_name) \
        _Pragma(TOOLCHAIN_STRINGIFY(section section_name ax 4))

    #define TOOLCHAIN_SECTION_TEXT_END() \
        _Pragma("section")


    #define TOOLCHAIN_SECTION_BSS_START(section_name) \
        _Pragma(TOOLCHAIN_STRINGIFY(section section_name aw 4))

    #define TOOLCHAIN_SECTION_BSS_END() \
        _Pragma("section")


    #define TOOLCHAIN_SECTION_DATA_START(section_name) \
        _Pragma(TOOLCHAIN_STRINGIFY(section section_name aw 4))

    #define TOOLCHAIN_SECTION_DATA_END() \
        _Pragma("section")


    #define TOOLCHAIN_SECTION_RODATA_START(section_name) \
        _Pragma(TOOLCHAIN_STRINGIFY(section section_name a))

    #define TOOLCHAIN_SECTION_RODATA_END() \
        _Pragma("section")

#endif


#endif /* TOOLCHAIN_H */
