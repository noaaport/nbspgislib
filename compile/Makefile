#
# $Id: Makefile,v 7b89a4bfdaf1 2011/01/17 00:15:52 nieves $
#
BINFILES = \
	${UNZ_DIR}/nbspunz \
	${DCNIDS_DIR}/nbspradinfo \
	${DCNIDS_DIR}/nbspradgis \
	${DCGINI_DIR}/nbspsatinfo \
	${DCGINI_DIR}/nbspsatgis

UNZ_DIR = src/unz
DCNIDS_DIR = src/dcnids
DCGINI_DIR = src/dcgini

BINDIR = bin

all:
	cd src; ${MAKE} all;
	install -d ${BINDIR}
	install -m 0755 ${BINFILES} ${BINDIR}

clean:
	rm -rf *~ bin src
