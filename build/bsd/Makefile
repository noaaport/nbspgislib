#
# $Id$
#
.include "../../VERSION"
.include "pkginfo.mk"

DESTDIR = /usr/local

package_version = ${version}_${package_build} 
package_origin = ${package_category}/${name}
package_name = ${name}-${package_version}
package_file = ${package_name}.${package_ext}

option_files = -f pkg-plist \
	-c pkg-comment \
	-d pkg-descr \
	-r pkg-req

configure: stage.configure

build: stage.build

stage.configure:
	cd ../../compile; ./configure.sh
	touch stage.configure

stage.build: stage.configure
	cd ../../compile; ${MAKE}
	touch stage.build

install: build
	rm -rf pkg
	install -d pkg
	DESTDIR=`pwd`/pkg; \
		cd ../../compile; \
		${MAKE} DESTDIR=$${DESTDIR} install

package: install
	pkg_create -p ${DESTDIR} -s `pwd`/pkg -o ${package_origin} \
	${option_files} ${package_file}

clean:
	rm -f *~
	rm -rf pkg stage.*
	rm -f ${package_file}
	cd ../../compile; ${MAKE} distclean
