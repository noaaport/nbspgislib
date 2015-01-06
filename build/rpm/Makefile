#
# $Id$
#

include ../../VERSION

# requires = $(shell grep -v "^\#" rpm-requires)
rpmrelease = $(shell grep -v "^\#" rpm-release)
rpmroot = ${HOME}/docs/devel/rpmbuild

arch =  $(shell uname -m)
# flavor = $(shell ./flavor.sh)
dist = $(shell ./dist.sh)

tgzfile = ${name}-${version}.tgz
rpmfile = ${name}-${version}-${rpmrelease}${dist}.${arch}.rpm

default: package

spec: rpm-spec
tgz: ${tgzfile}

${tgzfile}:
	cd ../../..;\
	cp -r ${name} ${name}-${version};\
	tar -czf ${name}-${version}.tgz ${name}-${version};\
	rm -rf ${name}-${version}
	mv ../../../${name}-${version}.tgz .

rpm-spec: rpm-spec.in
	sed -e "/@name@/s//${name}/" \
	-e "/@version@/s//${version}/" \
	-e "/@rpmrelease@/s//${rpmrelease}/" \
	-e "/@plist@/r rpm-plist" -e "/@plist@/d" \
	rpm-spec.in > rpm-spec

package: rpm-spec ${tgzfile}
	mv ${name}-${version}.tgz ${rpmroot}/SOURCES
	rpmbuild -bb rpm-spec
	cp ${rpmroot}/RPMS/${arch}/${rpmfile} .

clean:
	rm -f *~ rpm-spec ${tgzfile} ${rpmfile}
