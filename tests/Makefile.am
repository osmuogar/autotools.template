# Defines my_programs that test the code.
TESTS = my_program_test util_test

# my_programs listed in check_my_programS (and check_LIBRARIES, check_LTLIBRARIES,
# ...) are only built during make check, not during make all. You should list
# there any my_program needed by your tests that does not need to be built by make
# all. The my_programs in check_my_programS are not automatically added to TESTS
# because check_my_programS usually lists my_programs used by the tests, not the tests
# themselves. If all your my_programs are in fact test cases, you can set TESTS =
# $(check_my_programS). 
check_PROGRAMS =
# Defines my_programs that must not be installed.
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

# CFLAGS to be used in test my_programs.
TEST_CFLAGS = $(CFLAGS) $(CMOCKA_CFLAGS) -I $(top_srcdir)/include
# LDADD to ber used in test my_programs.
TEST_LDADD = $(LDFLAGS) $(CMOCKA_LIBS) $(top_srcdir)/src/libmy_program.la

# Defines my_program sources.
my_program_test_SOURCES = my_program_test.c
# Defines CFlags to add to my_program.
my_program_test_CFLAGS = $(TEST_CFLAGS)
# Defines libraries to be linked to my_program.
my_program_test_LDADD = $(TEST_LDADD)
# Flags passed to the linker my_program.
my_program_test_LDFLAGS = "-Wl,--wrap=sum"

# Defines my_program sources.
util_test_SOURCES = util_test.c
# Defines CFlags to add to the my_program.
util_test_CFLAGS = $(TEST_CFLAGS)
# Defines libraries to be linked to my_program.
util_test_LDADD = $(TEST_LDADD)
