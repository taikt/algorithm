#!/bin/bash


# sudo chmod +x lib.sh
# ./lib.sh make: to build lib
# ./lib.sh local: to create lib in local path
# ./lib.sh install: to install lib into system, avoid exporting lib when executing app

# recommened one
# ./lib.sh make
# ./lib.sh install

mylibcpp="libcpptest"

case "$1" in
    'make')
        echo "build lib cpp"
        g++ -Wall -fPIC -c *.cpp
        g++ -shared -Wl,-soname,$mylibcpp.so.1 -o $mylibcpp.so.1.0 *.o
        ;;

    'local')
        ## two above commands creates libctest.so.1.0
        echo "install lib locally"
        ln -sf $mylibcpp.so.1.0 $mylibcpp.so
        ln -sf $mylibcpp.so.1.0 $mylibcpp.so.1
        # need export lib when executing app if using lib at local path
        # export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/$(pwd)/lib
        # test environment variable: echo $LD_LIBRARY_PATH
        ;;

    'install')
        echo "install lib to /lib"
        sudo cp -rf $mylibcpp.so.1.0 /lib/$mylibcpp.so.1.0
        sudo ln -sf /lib/$mylibcpp.so.1.0 /lib/$mylibcpp.so
        sudo ln -sf /lib/$mylibcpp.so.1.0 /lib/$mylibcpp.so.1
        ;;

    'remove')
       echo "remove lib from /lib"
       sudo rm -rf /lib/$mylibcpp*
       ;;

    'clean')
        echo "clean lib"
        rm -rf libcpptest* *.o *.so.1.0
        ;;
esac


        
      
