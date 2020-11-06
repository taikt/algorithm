# https://www.gnu.org/software/make/manual/make.html#Phony-Targets
# http://stackoverflow.com/questions/11206500/compile-several-projects-with-makefile-but-stop-on-first-broken-build/11206700#11206700
# http://www.eecs.wsu.edu/~cs224/notes/makefile.html
# http://stackoverflow.com/questions/9249757/recursive-make-in-subdirectories
# http://lackof.org/taggart/hacking/make-example/
# make -f makefile1.mk (run both bar, foo)
# make -f makefile1.mk bar (only run bar)
# this makefile using PHONY target runs recursively two makefiles in sub-directories as bar, foo
# Advantage: if makefile in bar is failed, it stops without running the one in foo

SUBDIRS = bar foo
.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -C $@

bar: foo #run 'foo' completely before running 'bar'
# foo: bar #run 'bar' completely before running 'foo'
# without mentioning, it runs parallel 	


#TODO: make clean at top-level