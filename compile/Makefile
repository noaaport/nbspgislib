#
# $Id$
#

# These are for manipulation by packaging tools
PKGBUILDDIR = pkg
PREFIX = usr/local
MANPREFIX =		# or "share" when prefix=usr
MANSUBDIR = man/man1

DESTDIR = ${PKGBUILDDIR}/${PREFIX}

BINDIR = ${DESTDIR}/bin
DOCDIR = ${DESTDIR}/share/doc
MANDIR = ${DESTDIR}/${MANPREFIX}/${MANSUBDIR}

BINFILES = \
	${UNZ_DIR}/nbspunz \
	${DCNIDS_DIR}/nbspradinfo \
	${DCNIDS_DIR}/nbspradgis \
	${DCGINI_DIR}/nbspsat \
	${DCGINI_DIR}/nbspsatinfo \
	${DCGINI_DIR}/nbspsatgis \
	${DCGOESR_DIR}/nbspgoesr \
	${DCGOESR_DIR}/nbspgoesrinfo \
	${DCGOESR_DIR}/nbspgoesrgis

MANFILES = \
	doc/nbspunz.1.gz \
	doc/nbspradinfo.1.gz \
	doc/nbspradgis.1.gz \
	doc/nbspsat.1.gz \
	doc/nbspsatinfo.1.gz \
	doc/nbspsatgis.1.gz

UNZ_DIR = src/unz
DCNIDS_DIR = src/dcnids
DCGINI_DIR = src/dcgini
DCGOESR_DIR = src/dcgoesr

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
