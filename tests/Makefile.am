# Defines programs that test the code
TESTS = test

# Programs listed in check_PROGRAMS (and check_LIBRARIES, check_LTLIBRARIES,
# ...) are only built during make check, not during make all. You should list
# there any program needed by your tests that does not need to be built by make
# all. The programs in check_PROGRAMS are not automatically added to TESTS
# because check_PROGRAMS usually lists programs used by the tests, not the tests
# themselves. If all your programs are in fact test cases, you can set TESTS =
# $(check_PROGRAMS). 
check_PROGRAMS =
# Defines programs that must not be installed.
noinst_PROGRAMS = $(TESTS)

# Defines program sources
test_SOURCES = test.c
# Defines CFlags to add to the program
test_CFLAGS = $(CFLAGS) $(CHECK_CFLAGS) -I $(top_srcdir)/include
# Defines libraries to be linked to the program
test_LDADD = $(LDFLAGS) $(CHECK_LIBS) $(top_srcdir)/src/libprogram.la
