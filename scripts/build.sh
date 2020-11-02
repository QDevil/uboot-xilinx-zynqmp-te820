#!/bin/bash -e

UBOOTDIR=u-boot-xlnx

scriptdir=$(realpath `dirname $0`)
workdir=$(realpath $scriptdir/..)

pushd "$workdir"

cp src/te820-config "$UBOOTDIR/.config"
cp src/qdevil.h "$UBOOTDIR/include/configs/"
cp src/xilinx_zynqmp_te820.h "$UBOOTDIR/include/configs/"

cp src/handoff.c "$UBOOTDIR/arch/arm/cpu/armv8/zynqmp/handoff.c"
cp src/zynqmp.c "$UBOOTDIR/board/xilinx/zynqmp/zynqmp.c"

export CROSS_COMPILE="${XSDK}/gnu/aarch64/lin/aarch64-linux/bin/aarch64-linux-gnu-"
export ARCH=aarch64

cd "$UBOOTDIR"
make

popd
