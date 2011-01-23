#
# $Id: Makefile,v 6fc78581a72d 2011/01/23 03:09:44 nieves $
#

# These are for manipulation by packaging tools
PKGBUILDDIR = .
PREFIX = usr/local

DESTDIR = ${PKGBUILDDIR}/${PREFIX}
BINDIR = ${DESTDIR}/bin
DOCDIR = ${DESTDIR}/share/doc

BINFILES = \
	${UNZ_DIR}/nbspunz \
	${DCNIDS_DIR}/nbspradinfo \
	${DCNIDS_DIR}/nbspradgis \
	${DCGINI_DIR}/nbspsatinfo \
	${DCGINI_DIR}/nbspsatgis

UNZ_DIR = src/unz
DCNIDS_DIR = src/dcnids
DCGINI_DIR = src/dcgini

all:
	cd src; ${MAKE} all;

install: all
	install -d ${BINDIR}
	install -m 0755 ${BINFILES} ${BINDIR}

clean:
	rm -rf *~ ${BINDIR} src
