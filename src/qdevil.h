/*
 * U-Boot configuration for Xilinx ZynqMP Trenz TE820 board.
 *
 * Copyright (c) 2020 by QDevil, ApS.
 * Jimmi Marquart <jim@qdevil.com>
 * Jens Peter Secher <jps@qdevil.com>
 *
 * SPDX-License-Identifier: ISC
 */

#ifndef __CONFIG_QDEVIL_H
#define __CONFIG_QDEVIL_H

#define FLASH_PL_OFFSET   0x003b4c0  /* First free addr after Trenz FSBL */
#define FLASH_PL_LENGTH   0x01dc514  /* Size of Trenz test_board.bit (max 26 MiB) */

/* #define FLASH_ENV_OFFSET  0x1e00000  // CONFIG_ENV_OFFSET in config file */
/* #define FLASH_ENV_LENGTH  0x0008000  // CONFIG_ENV_SIZE in config file */

#define FLASH_APU0_OFFSET 0x2000000  /* First free addr after evironment */
#define FLASH_APU0_LENGTH 0x000d048  /* Size of remote-reset app (max 48 MiB) */

#define FLASH_APU1_OFFSET 0x5000000  /* Halfway between APU0 and last addr */
#define FLASH_APU1_LENGTH 0x000d048  /* Size of dummy app (max 48 MiB) */

#define DRAM_APU0_ADDRESS 0x0000000  /* First DRAM addr */
#define DRAM_APU1_ADDRESS 0x2000000  /* 64 MiB after APU0 */

#include <configs/xilinx_zynqmp_te820.h>

#endif /* __CONFIG_QDEVIL_H */
