# make -f makefile1.mk
# target ... : prerequisites ..
#	recipe(rule)
#	...
#	...
IDIR =../include
ODIR =../obj
CFLAGS=-I$(IDIR)
_OBJ = hellofunc2.o

all : $(ODIR)/$(_OBJ)
#if only create objects, need set target as "all"


# automatic variables
# https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
# $@ - name of target of the rule
# $< - name of first prerequisite
# $^ - name of all prerequisites 

#$(ODIR)/%.o : %.c $(IDIR)/hellomake.h
$(ODIR)/%.o : %.c $(IDIR)/hellomake.h
	cc -c -o $@ $< $(CFLAGS)
# cc -c -o obj/hellofunc.o obj/hellofunc.c -I./../include

#hellomake.o : hellomake.c $(IDIR)/hellomake.h
#	cc -c hellomake.c $(CFLAGS)
#   cc -c hellofunc.c -I./../include

#hellofunc.o : hellofunc.c $(IDIR)/hellomake.h
#	cc -c hellofunc.c $(CFLAGS)

# replace "hellomake.c" in rule by "$<"
.PHONY: clean
clean:
	    rm $(ODIR)/*.o


