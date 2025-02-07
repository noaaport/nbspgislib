#
# Copyright (c) 2005-2011 Jose F. Nieves <nieves@ltp.upr.clu.edu>
# Copyright (c) 2025 Jose F. Nieves <nieves@ltp.uprrp.edu>
#
# See LICENSE
#
# $Id$
#

SUBDIRS = dcnids dcgoesr dcgini unz

all:
	for dir in ${SUBDIRS}; do \
	(cd $$dir; ${MAKE} all) \
	done

install:
	for dir in ${SUBDIRS}; do \
	(cd $$dir; ${MAKE} install) \
	done

clean:
	rm -f *~
	for dir in ${SUBDIRS}; do \
	(cd $$dir; ${MAKE} clean) \
	done
