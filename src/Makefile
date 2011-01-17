#
# Copyright (c) 2005-2011 Jose F. Nieves <nieves@ltp.upr.clu.edu>
#
# See LICENSE
#
# $Id$
#

SUBDIRS = dcgini dcnids unz

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
