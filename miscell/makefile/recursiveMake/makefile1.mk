# https://www.gnu.org/software/make/manual/make.html#Phony-Targets
# make -f makefile1.mk (run both bar, foo)
# make -f makefile1.mk bar (only run bar)
# this makefile runs recursively two makefiles in sub-directories as bar, foo
# Disadvantage: if makefile in bar is failed, it continues run the one in foo without stopping

SUBDIRS = bar foo

subdirs:
	for dir in $(SUBDIRS) ; do \
		$(MAKE) -C $$dir; \
	done
