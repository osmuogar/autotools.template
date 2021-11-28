# Subdirectories to be included
SUBDIRS = include src tests
# Extra files to be added to the distribution file
EXTRA_DIST =
# Auto configure local Automake flags
ACLOCAL_AMFLAGS=-I m4

# Enables code coverage
include Makefile.coverage.am

# Starts the program
.PHONY: start
start: all
	time ./src/${PACKAGE_NAME}

# Used to remove the remaining folders created when installing the application
uninstall-hook:
	if test -d ${prefix}/include/${PACKAGE_NAME}; then \
		rmdir ${prefix}/include/${PACKAGE_NAME}; fi

# Checks for memory leaks in the simulator
.PHONY: memory-leaks.check
memory-leaks.check: all
	./libtool --mode=execute \
		valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all  \
		./src/${PACKAGE_NAME} --verbose

# Checks for memory leaks in the simulator
.PHONY: memory-leaks.check
memory-leaks.test.check: all
	./libtool --mode=execute \
		valgrind --tool=memcheck --leak-check=yes \
		./tests/test
