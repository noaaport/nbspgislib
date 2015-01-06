#
# Copyright (c) 2015 Jose F. Nieves <nieves@ltp.uprrp.edu>
#
# See LICENSE
#
# $Id$
#
SOURCES = nbspunz.man \
	nbspradinfo.man nbspradgis.man \
	nbspsatinfo.man nbspsatgis.man

OBJECTS = nbspunz.1 \
	nbspradinfo.1 nbspradgis.1 \
	nbspsatinfo.1 nbspsatgis.1

TARGET = nbspunz.1.gz \
	nbspradinfo.1.gz nbspradgis.1.gz \
	nbspsatinfo.1.gz nbspsatgis.1.gz

all: ${TARGET}

nbspunz.1.gz: nbspunz.man
	cp nbspunz.man nbspunz.1
	gzip -9 -c nbspunz.1 > nbspunz.1.gz

nbspradinfo.1.gz: nbspradinfo.man
	cp nbspradinfo.man nbspradinfo.1
	gzip -9 -c nbspradinfo.1 > nbspradinfo.1.gz

nbspradgis.1.gz: nbspradgis.man
	cp nbspradgis.man nbspradgis.1
	gzip -9 -c nbspradgis.1 > nbspradgis.1.gz

nbspsatinfo.1.gz: nbspsatinfo.man
	cp nbspsatinfo.man nbspsatinfo.1
	gzip -9 -c nbspsatinfo.1 > nbspsatinfo.1.gz

nbspsatgis.1.gz: nbspsatgis.man
	cp nbspsatgis.man nbspsatgis.1
	gzip -9 -c nbspsatgis.1 > nbspsatgis.1.gz

clean:
	rm -f *~ ${OBJECTS} ${TARGET}
