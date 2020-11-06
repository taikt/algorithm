# make -f makefile1.mk
# target ... : prerequisites ..
#	recipe(rule) (one tab before rule) 
#	...
#	...
IDIR =../include
CFLAGS=-I$(IDIR)

hellomake : hellomake.o hellofunc.o
	cc -o hellomake hellomake.o hellofunc.o

hellomake.o : hellomake.c $(IDIR)/hellomake.h
	cc -c hellomake.c $(CFLAGS)

hellofunc.o : hellofunc.c $(IDIR)/hellomake.h
	cc -c hellofunc.c $(CFLAGS)

clean:
	rm hellomake hellomake.o hellofunc.o
