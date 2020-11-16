#!/bin/bash


# sudo chmod +x lib.sh
# ./lib.sh make: to build lib
# ./lib.sh local: to create lib in local path
# ./lib.sh install: to install lib into system, avoid exporting lib when executing app

# recommened one
# ./lib.sh make
# ./lib.sh install

mylibc="libctest"
#echo $x

case "$1" in
    'make')
        echo "build lib c"
        gcc -Wall -fPIC -c *.c
        gcc -shared -Wl,-soname,$mylibc.so.1 -o $mylibc.so.1.0 *.o
        ;;

    'local')
        ## two above commands creates libctest.so.1.0
        echo "install lib locally"
        ln -sf $mylibc.so.1.0 $mylibc.so
        ln -sf $mylibc.so.1.0 $mylibc.so.1
        # need export lib when executing app if using lib at local path
        # export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/$(pwd)/lib
        # test environment variable: echo $LD_LIBRARY_PATH
        ;;

    'install')
        echo "install lib to /lib"
        sudo cp -rf $mylibc.so.1.0 /lib/$mylibc.so.1.0
        sudo ln -sf /lib/$mylibc.so.1.0 /lib/$mylibc.so
        sudo ln -sf /lib/$mylibc.so.1.0 /lib/$mylibc.so.1
        ;;
    
    'remove')
        echo "remove lib from /lib"
        sudo rm -rf /lib/$mylibc*
        ;;

    'clean')
        echo "clean lib"
        rm -rf libctest* *.o *.so.1.0
        ;;
    
esac


        
      
