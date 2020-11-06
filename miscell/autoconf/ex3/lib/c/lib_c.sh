#!/bin/bash


# sudo chmod +x lib.sh
# ./lib.sh make: to build lib
# ./lib.sh local: to create lib in local path
# ./lib.sh install: to install lib into system, avoid exporting lib when executing app
# ./lib.sh install

mylibc="libctest"
#echo $x

case "$1" in
    'install')
        echo "install lib to /lib"
        sudo cp -rf .libs/$mylibc.so.0.0.0 /lib/$mylibc.so.0.0.0
        sudo ln -sf /lib/$mylibc.so.0.0.0 /lib/$mylibc.so
        sudo ln -sf /lib/$mylibc.so.0.0.0 /lib/$mylibc.so.0
        sudo ln -sf /lib/$mylibc.so.0.0.0 /lib/$mylibc.so.1
        ;;
    
    'remove')
        echo "remove lib from /lib"
        sudo rm -rf /lib/$mylibc*
        ;;
    
esac


        
      
