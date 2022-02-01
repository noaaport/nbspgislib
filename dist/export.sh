#!/bin/sh
#
# $Id$
#

# read name and version
. ../VERSION

cd ..
git archive --format tgz --prefix "${name}-${version}/" \
    -o "dist/${name}-${version}.tgz" HEAD
