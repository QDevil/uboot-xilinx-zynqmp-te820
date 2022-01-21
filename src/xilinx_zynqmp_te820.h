/*
 * U-Boot configuration for Xilinx ZynqMP Trenz TE820 board.
 *
 * Copyright (c) 2020 by QDevil, ApS.
 * Jimmi Marquart <jim@qdevil.com>
 * Jens Peter Secher <jps@qdevil.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __CONFIG_ZYNQMP_TE820_H
#define __CONFIG_ZYNQMP_TE820_H

#define CONFIG_ZYNQ_SDHCI1
#define CONFIG_SYS_I2C_MAX_HOPS 1
#define CONFIG_SYS_NUM_I2C_BUSES 18
#define CONFIG_SYS_I2C_BUSES { \
    {0, {I2C_NULL_HOP} }, \
    {0, {{I2C_MUX_PCA9544, 0x75, 0} } }, \
    {0, {{I2C_MUX_PCA9544, 0x75, 1} } }, \
    {0, {{I2C_MUX_PCA9544, 0x75, 2} } }, \
    {1, {I2C_NULL_HOP} }, \
    {1, {{I2C_MUX_PCA9548, 0x74, 0} } }, \
    {1, {{I2C_MUX_PCA9548, 0x74, 1} } }, \
    {1, {{I2C_MUX_PCA9548, 0x74, 2} } }, \
    {1, {{I2C_MUX_PCA9548, 0x74, 3} } }, \
    {1, {{I2C_MUX_PCA9548, 0x74, 4} } }, \
    {1, {{I2C_MUX_PCA9548, 0x75, 0} } }, \
    {1, {{I2C_MUX_PCA9548, 0x75, 1} } }, \
    {1, {{I2C_MUX_PCA9548, 0x75, 2} } }, \
    {1, {{I2C_MUX_PCA9548, 0x75, 3} } }, \
    {1, {{I2C_MUX_PCA9548, 0x75, 4} } }, \
    {1, {{I2C_MUX_PCA9548, 0x75, 5} } }, \
    {1, {{I2C_MUX_PCA9548, 0x75, 6} } }, \
    {1, {{I2C_MUX_PCA9548, 0x75, 7} } }, \
    }

#define CONFIG_SYS_I2C_ZYNQ
#define CONFIG_PCA953X

#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN  1
#define CONFIG_ZYNQ_EEPROM_BUS 5
#define CONFIG_ZYNQ_GEM_EEPROM_ADDR 0x50
#define CONFIG_ZYNQ_GEM_I2C_MAC_OFFSET 0xFA

/* Macro string expansion voodoo */
#define TE820_XSTR(s) TE820_STR(s)
#define TE820_STR(s) #s

/* Initial environment variables */
#define CONFIG_EXTRA_ENV_SETTINGS \
    "uboot_ver=2018.1\0" \
    "qdevil_ver=1\0" \
    "firmware_updates=0\0" \
    "pl_addr=" TE820_XSTR(DRAM_APU0_ADDRESS) "\0" \
    "pl_off=" TE820_XSTR(FLASH_PL_OFFSET) "\0" \
    "pl_len=" TE820_XSTR(FLASH_PL_LENGTH) "\0" \
    "apu0_addr=" TE820_XSTR(DRAM_APU0_ADDRESS) "\0" \
    "apu0_off=" TE820_XSTR(FLASH_APU0_OFFSET) "\0" \
    "apu0_len=" TE820_XSTR(FLASH_APU0_LENGTH) "\0"\
    "apu1_addr=" TE820_XSTR(DRAM_APU1_ADDRESS) "\0" \
    "apu1_off=" TE820_XSTR(FLASH_APU1_OFFSET) "\0" \
    "apu1_len=" TE820_XSTR(FLASH_APU1_LENGTH) "\0"\
    "boot_apu0=sf probe;sf read $apu0_addr $apu0_off $apu0_len;go $apu0_addr\0" \
    "boot_apus=sf probe;sf read $apu0_addr $apu0_off $apu0_len;sf read $apu1_addr $apu1_off $apu1_len;go $apu0_addr\0" \
    "boot_full=sf probe;sf read $pl_addr $pl_off $pl_len;fpga load 0 $pl_addr $pl_len;sf read $apu0_addr $apu0_off $apu0_len;sf read $apu1_addr $apu1_off $apu1_len;go $apu0_addr\0"

#include <configs/xilinx_zynqmp.h>

/* Allow higher baud rates to speed up firmware updates. */
#undef CONFIG_SYS_BAUDRATE_TABLE
#define CONFIG_SYS_BAUDRATE_TABLE \
    { 4800, 9600, 19200, 38400, 57600, 115200, 921600, 1843200, 3686400 }

#ifdef CONFIG_PREBOOT
#undef CONFIG_PREBOOT
#define CONFIG_PREBOOT  "echo U-Boot for Trenz TE820;setenv preboot; echo"
#endif

#ifdef CONFIG_BOOTCOMMAND
#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND  "run boot_apu0"
#endif

#endif /* __CONFIG_ZYNQMP_TE820_H */
