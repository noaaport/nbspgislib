#
# Copyright (c) 2024 Jose F. Nieves <nieves@ltp.uprrp.edu>
#
# See LICENSE
#
# $Id$
#
TARGET = nbspgoesr nbspgoesrinfo nbspgoesrgis
TARGET_OBJECTS = nbspgoesr.o nbspgoesrinfo.o nbspgoesrgis.o

GOESR_OBJECTS = nbspgoesr.o ${COMMON_OBJECTS} \
	dcgoesr_nc.o dcgoesr_xy2lonlat.o dcgoesr_png.o
GOESRINFO_OBJECTS = nbspgoesrinfo.o ${COMMON_OBJECTS}
GOESRGIS_OBJECTS = nbspgoesrgis.o ${COMMON_OBJECTS} \
	dcgoesr_nc.o dcgoesr_xy2lonlat.o \
	dcgoesr_shp.o dcgoesr_dbf.o dcgoesr_csv.o \
	dcgoesr_asc.o dcgoesr_regrid_asc.o \
	dcgoesr_info.o dcgoesr_name.o

GOESR_LIBS = -lm -lnetcdf -lpng
GOESRINFO_LIBS = -lnetcdf
GOESRGIS_LIBS = -lm -lnetcdf

DC_SOURCES = dcgoesr_nc.c dcgoesr_xy2lonlat.c dcgoesr_png.c \
	dcgoesr_shp.c dcgoesr_dbf.c dcgoesr_csv.c \
	dcgoesr_asc.c dcgoesr_regrid_asc.c \
	dcgoesr_info.c dcgoesr_name.c
DC_HEADERS = dcgoesr.h \
	dcgoesr_nc.h dcgoesr_xy2lonlat.h dcgoesr_png.h \
	dcgoesr_shp.h dcgoesr_regrid_asc.h dcgoesr_name.h
DC_OBJECTS = dcgoesr_nc.o dcgoesr_xy2lonlat.o dcgoesr_png.o \
	dcgoesr_shp.o dcgoesr_dbf.o dcgoesr_csv.o \
	dcgoesr_asc.o dcgoesr_regrid_asc.o \
	dcgoesr_info.o dcgoesr_name.o

COMMON_DIR = ../common
COMMON_SOURCES = err.c
COMMON_OBJECTS = err.o
COMMON_HEADERS = ${COMMON_DIR}/err.h

HEADERS = ${DC_HEADERS} ${COMMON_HEADERS}

ALL_OBJECTS = ${TARGET_OBJECTS} ${COMMON_OBJECTS} ${DC_OBJECTS}

INCDIRS = 	-iquote . -iquote ../common
INCDIRS += 	-I /usr/local/include
LIBDIRS =       -L /usr/local/lib
INSTALL =       install
CC =		cc
CCWFLAGS =	-Wall -Wextra -Wformat-security -Werror

INCDIRS +=	-iquote ..

CFLAGS +=	${DEBUGFLAGS} -c ${CCWFLAGS} ${INCDIRS}
DEBUGFLAGS =	-g
#DEBUGFLAGS =	-DNDEBUG
LDFLAGS +=	${LIBDIRS} ${LIBS}

all: ${TARGET}

.c.o: ${HEADERS}
	${CC} ${CFLAGS} $<

err.c: ${COMMON_DIR}/err.c
	cp ${COMMON_DIR}/err.c .

nbspgoesr: ${GOESR_OBJECTS}
	${CC} -o nbspgoesr ${GOESR_OBJECTS} ${LDFLAGS} ${GOESR_LIBS}

nbspgoesrinfo: ${GOESRINFO_OBJECTS}
	${CC} -o nbspgoesrinfo ${GOESRINFO_OBJECTS} ${LDFLAGS} ${GOESRINFO_LIBS}

nbspgoesrgis: ${GOESRGIS_OBJECTS}
	${CC} -o nbspgoesrgis ${GOESRGIS_OBJECTS} ${LDFLAGS} ${GOESRGIS_LIBS}

clean:
	rm -f *~ ${TARGET} ${ALL_OBJECTS} ${COMMON_SOURCES}
