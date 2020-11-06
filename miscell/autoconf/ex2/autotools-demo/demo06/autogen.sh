#!/bin/sh

# ./autogen.sh make: to build
# ./autogen.sh clean: to clean
case "$1" in
    'make')
        echo "make source"
        autoreconf --verbose --install --force
        ./configure
        make
        ;;

    'clean')
        echo "clean source"
        make clean
        make distclean
        rm -rf aclocal.m4 autom4te.cache configure depcomp install-sh Makefile.in \
                clean compile missing config.log config.status *.o Makefile
        ;;
esac
        

