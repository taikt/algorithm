IDIR=./include
CPPFLAGS=-I$(IDIR) -Werror -fpic
#CFLAGS += -Werror -fpic
#if c source file, use CFLAGS, otherwise CPPFLAGS for c++
#LDFLAGS=-L./lib/ -lctest -lcpptest
LIBS := \
	-L./../lib3/ \
	-lcpptest1
	   
#LDFLAGS += -Wl,--start-group $(LIBS) -Wl,--end-group -lpthread -lrt
LDFLAGS += $(LIBS) -lpthread -lrt
CXX=g++
CC=gcc

OBJ = cpptest3.o cpptest4.o

#gcc -Wall -fPIC -c *.c
#gcc -shared -Wl,-soname,$mylibc.so.1 -o $mylibc.so.1.0 *.o
TARGET = libcpptest2.so
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -shared -o $@ $^ $(LDFLAGS)

# $(CC) -shared -Wl,-soname,$@.1 -o $@.1.0 $^ $(LDFLAGS)
# https://stackoverflow.com/questions/18360776/how-to-not-print-in-the-output-a-comment-in-a-makefile
# https://stackoverflow.com/questions/12637841/what-is-the-soname-option-for-building-shared-libraries-for
#
.o : .cpp
	@echo "complie $^"
	$(CXX) $(CPPFLAGS) -c $^ -o $@


#app : $(OBJ)
#	$(CXX) -o $@ $^ $(LDFLAGS)
# $@ = app
# $^ = $(OBJ)

#.o : .cpp $(IDIR)/h1.h
#.o : .cpp $(IDIR)
#	$(CXX) -c $< $(CPPFLAGS)
# $< = .cpp (first reprerequisite, i.e test.cpp)

clean:
	rm *.o libcpptest*

print-%  : ; @echo $* = $($*)


# make -f makefile1.mk
# make -f makefile1.mk clean
