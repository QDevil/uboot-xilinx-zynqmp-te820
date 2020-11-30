# Universal bootloader for Trenz Xilinx ZynqMP SoM

This repository contains the second-stage bootloader for devices based on Xilinx Zynqmp FPGAs on Trenz TE820 SoM boards.

## Background

The U-Boot STBL is meant to be used with this *bootgen* specification:
```
flash_image:
{
    [pmufw_image] zynqmp_pmufw.elf
    [bootloader, destination_cpu = a53-0] zynqmp_fsbl.elf
    [destination_cpu = a53-0, exception_level = el-3, trustzone] bl31.elf
    [destination_cpu = a53-0, exception_level = el-2] u-boot.elf
    // offset 0x0120000 is the U-Boot environment
    [offset = 0x01a0000] app0.bin
    // offset 0x4000000 is for app1.bin
    // offset 0x6000000 is for PL bitstream
}
```

The first-stage bootloader (FSBL), ARM Trusted Firmware (ATF) and Power Management Unit (PMU) firmware are taken directly from Trenz demo project, as is.

The second-stage bootloader (U-Boot), however, needs to have its configuration compiled into the binary, so this repository is an automated way to build U-Boot so that it works with Trenz Xilinx ZyncMP SoM.

The offsets in the flash memory are also reflected in the configuration of U-Boot, more specifically, the offsets are enbedded in U-Boot environment variables.

The files in directory `src` hold the specific U-Boot configuration, so by changing these files you can make customisations.

## Theory of operation

This repository is meant to be built automatically by Jenkins in a container, using the following steps.

- Mount Xilinx Vivado tools into the container.
- Download known-good version of U-Boot source code.
- Compile U-Boot with specific configuration.
- Upload the binary result to an AWS S3 bucket.

## Build server

The Jenkins build server has been configured manually to poll the repository every 5 minutes, and start a build if there are any changes.  The build is controlled by `automation/Jenkinsfile`, picked up by the poll.

The `Jenkinsfile` starts the build in a custom container as described above.

The result of the build is uploaded to `s3://qdevil-artifacts/bootloader/`.

## Debugging the build

You need to have docker-compose installed, like

    $ sudo curl -L https://github.com/docker/compose/releases/download/1.21.2/docker-compose-`uname -s`-`uname -m` -o /usr/local/bin/docker-compose

To emulate what Jenkins does when he builds the container, you can manually start the container by

    $ export XILINX=/tools/Xilinx
    $ cd automation
    $ docker-compose run uboot-te820 bash

where the `XILINX` environment variable points to you local installation of Xilinx Vivado & SDK.

Docker-compose also mounts this repository inside the container under `/home/jenkins/workspace/uboot-te820` so there is direct access to make changes.

Inside the container, run

    $ cd ~/workspace/uboot-te820
    $ scripts/download-xilinx-uboot.sh
    $ scripts/build.sh

## Building the container

To rebuild the container:

    $ cd automation
    $ docker-compose build

## Maunal building

See `scripts/`
