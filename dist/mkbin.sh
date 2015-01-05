#!/bin/sh

. ./mk.subr
. ../VERSION

## Get the os parameters
set `upload_get_osparams`
osname=$1
osrelease=$2
osarch=$3

pkgname=${name}-${version}-${osname}-${osrelease}-${osarch}.tgz

cd ../compile
./configure.sh
make install
make install-man
tar -czf ../dist/${pkgname} pkg
make clean
