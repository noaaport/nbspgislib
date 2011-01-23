#!/bin/sh
#
# $Id$
#

# read name and version
. ../VERSION

hg archive -t tgz "%b-${version}.tgz"
