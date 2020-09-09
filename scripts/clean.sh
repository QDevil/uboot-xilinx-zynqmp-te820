#!/bin/bash -e

UBOOTDIR=u-boot-xlnx

scriptdir=$(realpath `dirname $0`)
workdir=$(realpath $scriptdir/..)

pushd "$workdir"

cd "$UBOOTDIR"
make clean

popd
