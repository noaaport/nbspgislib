#
# $Id$
#

# These are for manipulation by packaging tools
PKGBUILDDIR = pkg
PREFIX = usr/local
MANSUBDIR = man/man1

DESTDIR = ${PKGBUILDDIR}/${PREFIX}

BINDIR = ${DESTDIR}/bin
DOCDIR = ${DESTDIR}/share/doc
MANDIR = ${DESTDIR}/${MANSUBDIR}

BINFILES = \
	${UNZ_DIR}/nbspunz \
	${DCNIDS_DIR}/nbspradinfo \
	${DCNIDS_DIR}/nbspradgis \
	${DCGINI_DIR}/nbspsatinfo \
	${DCGINI_DIR}/nbspsatgis

MANFILES = \
	doc/nbspunz.1.gz \
	doc/nbspradinfo.1.gz \
	doc/nbspradgis.1.gz \
	doc/nbspsatinfo.1.gz \
	doc/nbspsatgis.1.gz

UNZ_DIR = src/unz
DCNIDS_DIR = src/dcnids
DCGINI_DIR = src/dcgini

all:
	cd src; ${MAKE} all
	cd doc; ${MAKE} all

install: all
	install -d ${BINDIR}
	install -m 0755 ${BINFILES} ${BINDIR}

install-man: all
	install -d ${MANDIR}
	install -m 0644 ${MANFILES} ${MANDIR}

clean:
	rm -rf *~ ${PKGBUILDDIR} src doc
