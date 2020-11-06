IDIR=./include
CPPFLAGS=-I$(IDIR)
#if c source file, use CFLAGS, otherwise CPPFLAGS for c++
CXX=g++
CC=gcc

OBJ = main.o test1.o test2.o

app : $(OBJ)
	$(CXX) -o $@ $^
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
