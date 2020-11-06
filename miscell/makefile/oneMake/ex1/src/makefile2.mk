# make -f makefile1.mk
# target ... : prerequisites ..
#	recipe(rule)
#	...
#	...
IDIR =../include
CFLAGS=-I$(IDIR)

_OBJ = hellomake.o hellofunc.o
# SRC = $(patsubst %.o,%.c,$(_OBJ))
# => SRC = hellomake.c hellofunc.c
# replace all *.o by *.c from set of _OBJ 
# for patsubst
# https://www.gnu.org/software/make/manual/make.html#Wildcard-Function


hellomake : $(_OBJ)
	cc -o $@ $^

# hellomake : hellomake.o hellofunc.o
#	 cc -o hellomake hellomake.o hellofunc.o

# 
# replace "hellomake.o hellofunc.o" in prerequisites by $(_OBJ)
# replace "hellomake" in rule by $@
# replace "hellomake.o hellofunc.o" in rule by $^

# automatic variables
# https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
# $@ - name of target of the rule
# $< - name of first prerequisite
# $^ - name of all prerequisites 

.o : .c $(IDIR)/hellomake.h
	cc -c $< $(CFLAGS)

#hellomake.o : hellomake.c $(IDIR)/hellomake.h
#	cc -c hellomake.c $(CFLAGS)

#hellofunc.o : hellofunc.c $(IDIR)/hellomake.h
#	cc -c hellofunc.c $(CFLAGS)

# replace "hellomake.c" in rule by "$<"
# cc -c hellofunc.c -I./../include
# above rule creates object at currect directory
# to create object file in another directory, check makefile3.mk
clean :
	rm hellomake *.o


print-%  : ; @echo $* = $($*)
# to print variable, add above line at any position in makefile
# at cmd, type printf-"variable name", ie. printf-OBJ