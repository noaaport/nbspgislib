#
# $Id: pkg-info.mk,v 4c420d7ff2ca 2015/01/06 00:48:25 nieves $
#
pkg_build != cat pkg-build
abi != pkg -vv | awk '$$1 == "ABI" {print $$NF}'
