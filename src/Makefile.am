AM_LIBS = @PTHREAD_LIBS@ @LIBS@
AM_CFLAGS = @CFLAGS@ @PTHREAD_CFLAGS@ -I $(top_srcdir)/include
AM_CC = @PTHREAD_CC@

# Defines a library top be installed under /usr/local/lib/ directory.
lib_LTLIBRARIES = libprogram.la
# Defines sources to be used in the library.
libprogram_la_SOURCES = \
    common.c \
    program.c \
    util.c

# Libraries to be linked to the library.
libprogram_la_LIBADD = $(LIBSUBUNIT_LIBS)

# Defines programs to be installed under the /usr/local/bin/ directory.
bin_PROGRAMS = program
# Program sources.
program_SOURCES = main.c
# Libraries to be linked to program.
program_LDADD = libprogram.la
