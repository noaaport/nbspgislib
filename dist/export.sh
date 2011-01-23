#!/bin/sh
#
# $Id: export.sh,v 6fc78581a72d 2011/01/23 03:09:44 nieves $
#

# read name and version
. ../VERSION

hg archive -t tgz "%b-${version}.tgz"
