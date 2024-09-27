/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright 2023 NXP
 */
#ifndef __OEI_H
#define __OEI_H

#include <stdint.h>
#include <string.h>

/*
 * Success and system ROM code will not request EdgeLock secure enclave to update OEI
 * memory TRDC configuration, which permission is executable and no write permission.
 */
#define OEI_SUCCESS		0xFAu
/*
 * Success with free memory request, system ROM will send release memory request to
 * EdgeLock secure enclave, which should release the write permission but lock the
 * execution permission.
 */
#define OEI_SUCCESS_FREE_MEM	0x55u
/*
 * ROM code will break the boot flow, move to next boot stage and reset the system
 */
#define OEI_FAIL		0x33u

#define OEI_ARG_LEN_IN_WORD       4
#define OEI_ARG_TYPE_INOUT_NA     0
#define OEI_ARG_TYPE_IN_IMG_OFF   1
#define OEI_ARG_TYPE_OUT_IMG_INFO 2

/*!
 * @name Register accecss macros
 * @{
 */
/*! Macros for reading register values */
#define Read32(a)     (*(volatile uint32_t *)(a))
#define Read16(a)     (*(volatile uint16_t *)(a))

/*! Macro for writing register value */
#define Write32(a,v)  (*(volatile uint32_t *)(a) = (v))
#define Write16(a,v)  (*(volatile uint16_t *)(a) = (v))
/** @} */

#if !defined(DEBUG)
#define printf(...)
#define __stringify(x...)
#else
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)
#endif

/**
 * OEI main function
 *
 * @retun 0 on success, error code otherwise
 */
int oei_main(uint32_t argc, uint32_t *argv);

#endif
