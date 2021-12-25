AM_LIBS = @PTHREAD_LIBS@ @LIBS@
AM_CFLAGS = @CFLAGS@ @PTHREAD_CFLAGS@ -I $(top_srcdir)/include
AM_CC = @PTHREAD_CC@

# Defines a library top be installed under /usr/local/lib/ directory.
lib_LTLIBRARIES = libmy_program.la
# Defines sources to be used in the library.
libmy_program_la_SOURCES = \
    common.c \
    my_program.c \
    util.c

# Libraries to be linked to the library.
libmy_program_la_LIBADD = $(LIBSUBUNIT_LIBS)

# Defines my_programs to be installed under the /usr/local/bin/ directory.
bin_PROGRAMS = my_program
# my_program sources.
my_program_SOURCES = main.c
# Libraries to be linked to my_program.
my_program_LDADD = libmy_program.la
