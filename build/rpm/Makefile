#
# $Id$
#

include ../../VERSION

all: package

spec: rpm-spec
tgz: ${name}-${version}.tgz

${name}-${version}.tgz:
	cd ../../..;\
	cp -r ${name} ${name}-${version};\
	tar -czf ${name}-${version}.tgz ${name}-${version};\
	rm -rf ${name}-${version}
	mv ../../../${name}-${version}.tgz .

rpm-spec: rpm-spec.in
	rpmrelease=`cat rpm-release`
	sed -e "/@name@/s//${name}/" \
	-e "/@version@/s//${version}/" \
	-e "/@rpmrelease@/s//$${rpmrelease}/" \
	-e "/@plist@/r rpm-plist" -e "/@plist@/d" \
	rpm-spec.in > rpm-spec

package: rpm-spec ${name}-${version}.tgz
	mv ${name}-${version}.tgz ~/rpmbuild/SOURCES
	rpmbuild -bb rpm-spec

clean:
	rm -f rpm-spec ${name}-${version}.tgz *~
