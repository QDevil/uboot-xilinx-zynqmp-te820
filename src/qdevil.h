/*
 * U-Boot configuration for Xilinx ZynqMP Trenz TE820 board.
 *
 * Copyright (c) 2020 by QDevil, ApS.
 * Jimmi Marquart <jim@qdevil.com>
 * Jens Peter Secher <jps@qdevil.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __CONFIG_QDEVIL_H
#define __CONFIG_QDEVIL_H

/* #define FLASH_ENV_OFFSET  0x0120000  // CONFIG_ENV_OFFSET in config file */
/* #define FLASH_ENV_LENGTH  0x0010000  // CONFIG_ENV_SIZE in config file */

#define FLASH_APU0_OFFSET 0x0130000  /* First free addr after evironment */
#define FLASH_APU0_LENGTH 0x000d048  /* Size of remote-reset app (max 62 MiB) */

#define FLASH_APU1_OFFSET 0x4000000  /* Between APU0 and PL */
#define FLASH_APU1_LENGTH 0x0000000  /* (max 32 MiB) */

#define FLASH_PL_OFFSET   0x6000000  /* Between APU1 and last addr */
#define FLASH_PL_LENGTH   0x0000000  /* (max 32 MiB) */

#define DRAM_APU0_ADDRESS 0x0001000  /* First DRAM addr after intr. vect. */
#define DRAM_APU1_ADDRESS 0x4000000  /* 64 MiB after APU0 */

#include <configs/xilinx_zynqmp_te820.h>

#endif /* __CONFIG_QDEVIL_H */
