#!/bin/bash


# sudo chmod +x lib.sh
# ./lib.sh make: to build lib
# ./lib.sh install

mylibcpp="libcpptest"

case "$1" in
    'install')
        echo "install lib to /lib"
        sudo cp -rf .libs/$mylibcpp.so.0.0.0 /lib/$mylibcpp.so.0.0.0
        sudo ln -sf /lib/$mylibcpp.so.0.0.0 /lib/$mylibcpp.so
        sudo ln -sf /lib/$mylibcpp.so.0.0.0 /lib/$mylibcpp.so.0
        ;;

    'remove')
       echo "remove lib from /lib"
       sudo rm -rf /lib/$mylibcpp*
       ;;

esac


        
      
