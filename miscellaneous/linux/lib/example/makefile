IDIR=./include
CPPFLAGS=-I$(IDIR)
#if c source file, use CFLAGS, otherwise CPPFLAGS for c++
LDFLAGS :=-L./lib/ex2/lib2 -L./lib/ex2/lib4 \
	-L./lib/ex2/lib3 -L./lib/ex2/lib1 \
	-lctest2 -lcpptest2 -lcpptest1 -lctest1 \
	-Wl,-rpath=./lib/ex2/lib2 -Wl,-rpath=./lib/ex2/lib4 \
   	-Wl,-rpath=./lib/ex2/lib3 -Wl,-rpath=./lib/ex2/lib1
#LDFLAGS=-L./lib/ex2/lib4 -lcpptest2 -Wl,-rpath=./lib/ex2/lib4
#LDFLAGS=-L./lib/ex2/lib2 -lctest2 -Wl,-rpath=./lib/ex2/lib2
CXX=g++
CC=gcc

OBJ = main.o test1.o test2.o

app : $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)
# $@ = app
# $^ = $(OBJ)

#.o : .cpp $(IDIR)/h1.h
.o : .cpp $(IDIR)
	$(CXX) -c $< $(CPPFLAGS)
# $< = .cpp (first reprerequisite, i.e test.cpp)

clean:
	rm *.o app

print-%  : ; @echo $* = $($*)


# make -f makefile1.mk
# make -f makefile1.mk clean
