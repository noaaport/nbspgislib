#
# $Id$
#

PKGMAKEFILE = Makefile.pkg
MAKEDEPS = ../../compile/Makefile

default: build

../../compile/Makefile: ../../compile/Makefile.in
	cd ../../compile; ./configure.sh

build: ${MAKEDEPS}
	${MAKE} -f ${PKGMAKEFILE} build

install: ${MAKEDEPS}
	${MAKE} -f ${PKGMAKEFILE} install

package: ${MAKEDEPS}
	${MAKE} -f ${PKGMAKEFILE} package

clean: ${MAKEDEPS}
	${MAKE} -f ${PKGMAKEFILE} clean
