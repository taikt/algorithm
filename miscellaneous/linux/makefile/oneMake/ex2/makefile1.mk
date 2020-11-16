# make -f makefile1.mk
# make -f makefile1.mk clean
# This single makefile compiles code at sub-directories
# http://stackoverflow.com/questions/231229/how-to-generate-a-makefile-with-source-in-sub-directories-using-just-one-makefil
# http://stackoverflow.com/questions/1139271/makefiles-with-source-files-in-different-directories

IDIR =include
CC=gcc
# CC, Program for compiling C programs; default ‘cc’.
# CXX,Program for compiling C++ programs; default ‘g++’.

CFLAGS=-I$(IDIR)
# Extra flags to give to the C compiler. 

ODIR=obj
LDIR =lib

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
#DEPS = ../include/hellomake.h

_OBJ = hellofunc.o hellofunc2.o hellomake.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
#OBJ = obj/hellomake.o obj/hellofun.o obj/hellofunc2.o
VPATH = bar foo
# without VPATH, make only find source *.c at current directory
hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
# gcc -o hellomake obj/hellofunc.o obj/hellofunc2.o obj/hellomake.o -Iinclude

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# gcc -c -o obj/hellofunc.o bar/hellofunc.c -I./include
# gcc -c -o obj/hellofunc2.o foo/hellofunc2.c -Iinclude

# automatic varialbes
# https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
# $@ - name of target of the rule
# $< - name of first prerequisite
# $^ - name of all prerequisites 

.PHONY: clean 
# without PHONY target, suppose there is a file named clean, make clean
# will update the file, not the recipe "clean"
# with PHONY target, it will run clean even though there is file "clean" or not
clean:
	rm -f $(ODIR)/*.o *~ hellomake $(INCDIR)/*~ 

print-%  : ; @echo $* = $($*)