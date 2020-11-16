IDIR =../include
CC=gcc
#CC, Program for compiling C programs; default ‘cc’.
#CXX,Program for compiling C++ programs; default ‘g++’.

CFLAGS=-I$(IDIR)
#Extra flags to give to the C compiler. 

ODIR=obj
LDIR =../lib

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
#$(CC) -c $< $(CFLAGS)
# gcc -c -o obj/hellofunc.o obj/hellofunc.c -I./../include ===>create objects at another directory
# gcc -c hellofunc.c -I./../include ===> create objects at current directory
# => $(CC) -c $< $(CFLAGS) or $(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

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