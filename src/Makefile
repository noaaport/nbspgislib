#
# Copyright (c) 2005-2011 Jose F. Nieves <nieves@ltp.upr.clu.edu>
#
# See LICENSE
#
# $Id: Makefile,v 7b89a4bfdaf1 2011/01/17 00:15:52 nieves $
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
