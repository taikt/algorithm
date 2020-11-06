obj-m	:= oops.o 
KDIR    := /lib/modules/$(shell uname -r)/build
PWD     := $(shell pwd) 
MYCFLAGS	+= -g
ccflags-y += ${MYCFLAGS}
CC += ${MYCFLAGS}
SYM=$(PWD) 
 
all: 
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

debug:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	EXTRA_CFLAGS="$(MYCFLAGS)"

clean:
	#rm -rf oops.ko oops.o
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
