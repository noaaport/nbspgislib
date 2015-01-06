#!/bin/sh
#
# $Id: mkplist.sh,v 4c420d7ff2ca 2015/01/06 00:48:25 nieves $
#
# Use to generate the deb and rpm plist file when the bsd pkg-plist
# is updated.
#

awk '!/^@/ {printf("/usr/%s\n", $0)}' pkg-plist > ../debian/plist
cp ../debian/plist ../rpm/rpm-plist
