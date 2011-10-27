#
# Copyright (c) 2005-2011 Jose F. Nieves <nieves@ltp.upr.clu.edu>
#
# See LICENSE
#
# $Id$
#
TARGET = nbspunz

SOURCES = nbspunz.c
OBJECTS = nbspunz.o
HEAERS =

COMMON_DIR = ../common
COMMON_HEADERS = const.h config.h common.h \
		err.h io.h misc.h mfile.h util.h unz.h
COMMON_SOURCES = err.c io.c misc.c mfile.c util.c unz.c
COMMON_OBJECTS = err.o io.o misc.o mfile.o util.o unz.o

ALL_OBJECTS = ${OBJECTS} ${COMMON_OBJECTS}

INCDIRS = 	-iquote . -iquote ../common
INCDIRS += 	-I /usr/local/include
LIBDIRS = 	-L /usr/local/lib
LIBS =		-lz
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

${TARGET}: ${ALL_OBJECTS}
	${CC} -o ${TARGET} ${ALL_OBJECTS} ${LDFLAGS}

install:
	# ${INSTALL} -m 755 ${TARGET} ${BINDIR}

clean:
	rm -f *~ ${TARGET} ${ALL_OBJECTS} ${COMMON_SOURCES}
