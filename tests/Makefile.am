# Defines programs that test the code.
TESTS = program_test util_test

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

# Auto generated check-valgrind rules
@VALGRIND_CHECK_RULES@
# Files used to silence errors
VALGRIND_SUPPRESSIONS_FILES = $(addsuffix .supp, $(TESTS))

# Despite all this automatic inclusion, it is still common to have files to be
# distributed which are not found by the automatic rules. You should listed
# these files in the EXTRA_DIST variable. You can mention files in
# subdirectories in EXTRA_DIST. 
EXTRA_DIST = $(VALGRIND_SUPPRESSIONS_FILES)

# CFLAGS to be used in test programs.
TEST_PROGRAM_CFLAGS = $(CFLAGS) $(CMOCKA_CFLAGS) -I $(top_srcdir)/include
# LDADD to ber used in test programs.
TEST_PROGRAM_LDADD = $(LDFLAGS) $(CMOCKA_LIBS) $(top_srcdir)/src/libprogram.la

# Defines program sources.
program_test_SOURCES = program_test.c
# Defines CFlags to add to program.
program_test_CFLAGS = $(TEST_PROGRAM_CFLAGS)
# Defines libraries to be linked to program.
program_test_LDADD = $(TEST_PROGRAM_LDADD)
# Flags passed to the linker program.
program_test_LDFLAGS = "-Wl,--wrap=sum"

# Defines program sources.
util_test_SOURCES = util_test.c
# Defines CFlags to add to the program.
util_test_CFLAGS = $(TEST_PROGRAM_CFLAGS)
# Defines libraries to be linked to program.
util_test_LDADD = $(TEST_PROGRAM_LDADD)
