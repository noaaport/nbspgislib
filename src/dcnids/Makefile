#
# Copyright (c) 2005-2011 Jose F. Nieves <nieves@ltp.upr.clu.edu>
#
# See LICENSE
#
# $Id: Makefile,v 6353839bd4d6 2011/10/27 19:40:06 nieves $
#
TARGET = nbspradinfo nbspradgis
OBJECTS = nbspradinfo.o nbspradgis.o ${DC_OBJECTS}

RADINFO_OBJECTS = nbspradinfo.o ${COMMON_OBJECTS} ${DC_OBJECTS}
RADGIS_OBJECTS = nbspradgis.o ${COMMON_OBJECTS} ${DC_OBJECTS}

DC_SOURCES = dcnids_extract.c dcnid_header.c dcnids_misc.c \
	dcnids_name.c dcnids_transform.c \
	dcnids_shp.c dcnids_csv.c dcnids_dbf.c dcnids_info.c dcnids_bunz.c \
	dcnids_decode_radials_af1f.c dcnids_decode_digital_radials_16.c \
	dbfread.c dbfwrite.c \
	nbspradinfo.c nbspradgis.c
DC_HEADERS = dcnids.h dcnids_extract.h dcnids_header.h dcnids_misc.h \
	dcnids_info.h dcnids_name.h dcnids_shp.h

DC_OBJECTS = dcnids_extract.o dcnids_header.o dcnids_name.o dcnids_misc.o \
	dcnids_transform.o \
	dcnids_decode_radials_af1f.o dcnids_decode_digital_radials_16.o \
	dcnids_shp.o dcnids_csv.o dcnids_dbf.o dcnids_info.o dcnids_bunz.o

COMMON_DIR = ../common
COMMON_SOURCES = err.c io.c misc.c mfile.c util.c unz.c
COMMON_OBJECTS = err.o io.o misc.o mfile.o util.o unz.o
COMMON_HEADERS = ${COMMON_DIR}/common.h \
	${COMMON_DIR}/const.h \
	${COMMON_DIR}/err.h \
	${COMMON_DIR}/io.h \
	${COMMON_DIR}/misc.h \
	${COMMON_DIR}/unz.h \
	${COMMON_DIR}/util.h

HEADERS = ${DC_HEADERS} ${COMMON_HEADERS}

ALL_OBJECTS = ${OBJECTS} ${COMMON_OBJECTS}

INCDIRS = 	-iquote . -iquote ../common
INCDIRS += 	-I /usr/local/include
LIBDIRS = 	-L /usr/local/lib
LIBS =		-lz -lbz2 -lm
LDFLAGS += 	${LIBDIRS} ${LIBS}

#DEBUGFLAGS =	-g
#DEBUGFLAGS =	-DNDEBUG
CCWFLAGS = 	-Wall -Wextra -Werror
CFLAGS +=	-c ${DEBUGFLAGS} ${CCWFLAGS} ${INCDIRS}

INSTALL = install
CC = cc

all: ${TARGET}

.c.o: ${HEADERS}
	${CC} ${CFLAGS} $<

err.c: ${COMMON_DIR}/err.c
	cp ${COMMON_DIR}/err.c .

io.c: ${COMMON_DIR}/io.c
	cp ${COMMON_DIR}/io.c .

misc.c: ${COMMON_DIR}/misc.c
	cp ${COMMON_DIR}/misc.c .

mfile.c: ${COMMON_DIR}/mfile.c
	cp ${COMMON_DIR}/mfile.c .

util.c: ${COMMON_DIR}/util.c
	cp ${COMMON_DIR}/util.c .

unz.c: ${COMMON_DIR}/unz.c
	cp ${COMMON_DIR}/unz.c .

nbspradinfo: ${RADINFO_OBJECTS}
	${CC} -o nbspradinfo ${RADINFO_OBJECTS} ${LDFLAGS}

nbspradgis: ${RADGIS_OBJECTS}
	${CC} -o nbspradgis ${RADGIS_OBJECTS} ${LDFLAGS}

clean:
	rm -f *~ ${TARGET} ${ALL_OBJECTS} ${COMMON_SOURCES}
