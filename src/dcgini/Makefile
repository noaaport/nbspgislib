#
# Copyright (c) 2005-2011 Jose F. Nieves <nieves@ltp.upr.clu.edu>
#
# See LICENSE
#
# $Id$
#
TARGET = nbspsat nbspsatinfo nbspsatgis
OBJECTS = nbspsat.o nbspsatinfo.o nbspsatgis.o ${DC_OBJECTS}

SAT_OBJECTS = nbspsat.o ${COMMON_OBJECTS} ${DC_OBJECTS}
SATINFO_OBJECTS = nbspsatinfo.o ${COMMON_OBJECTS} ${DC_OBJECTS}
SATGIS_OBJECTS = nbspsatgis.o ${COMMON_OBJECTS} ${DC_OBJECTS}

DC_SOURCES = dcgini_misc.c dcgini_name.c dcgini_pdb.c \
	dcgini_transform.c dcgini_util.c \
	dcgini_asc.c dcgini_shp.c dcgini_dbf.c dcgini_csv.c dcgini_info.c
DC_HEADERS = dcgini.h dcgini_const.h dcgini_grid.h dcgini_projections.h \
	dcgini_misc.h dcgini_name.h dcgini_pdb.h dcgini_shp.h \
	dcgini_transform.h dcgini_transform_priv.h dcgini_util.h
DC_OBJECTS = dcgini_misc.o dcgini_name.o dcgini_pdb.o \
	dcgini_transform.o dcgini_util.o \
	dcgini_asc.o dcgini_shp.o dcgini_dbf.o dcgini_csv.o dcgini_info.o

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
LIBS =		-lz -lm
LDFLAGS = 	${LIBDIRS} ${LIBS}
#
SAT_LIBS =	-lz -lm -lpng
SAT_LDFLAGS = 	${LIBDIRS} ${SAT_LIBS}

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

nbspsat: ${SAT_OBJECTS}
	${CC} -o nbspsat ${SAT_OBJECTS} ${SAT_LDFLAGS}

nbspsatinfo: ${SATINFO_OBJECTS}
	${CC} -o nbspsatinfo ${SATINFO_OBJECTS} ${LDFLAGS}

nbspsatgis: ${SATGIS_OBJECTS}
	${CC} -o nbspsatgis ${SATGIS_OBJECTS} ${LDFLAGS}

clean:
	rm -f *~ ${TARGET} ${ALL_OBJECTS} ${COMMON_SOURCES}
