CC=gcc
CXX=g++
RM=rm -f
IDIR=./include
CPPFLAGS=-g -I$(IDIR)
LDFLAGS=-g
#LDLIBS=$(shell root-config --libs)

SRCS=test1.cpp main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: app

app: $(OBJS)
	$(CXX) $(LDFLAGS) -o app $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend
