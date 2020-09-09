#!/bin/bash -e

REPODIR=u-boot-xlnx
REPOTAG=xilinx-v2018.3

scriptdir=$(realpath `dirname $0`)
workdir=$(realpath $scriptdir/..)

pushd "$workdir"

if [ -d $REPODIR ]; then
    cd $REPODIR
    git reset --hard $REPOTAG
    git clean -fd
else
    git clone -b $REPOTAG --depth 1 https://github.com/Xilinx/$REPODIR.git
    cd $REPODIR
fi

popd
