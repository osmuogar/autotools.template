dnl                                               -*- Autoconf -*-
dnl Process this file with autoconf to produce a configure script. Use
dnl `autoscan` to find dependencies to be added to this file.

dnl Process any command-line arguments and perform various initializations and
dnl verifications.
AC_INIT([my_program],[0.1.0],[user@mail.com])

dnl Make AC_OUTPUT create the file(s) in the blank-or-newline-separated list
dnl header containing C preprocessor #define statements, and replace ‘@DEFS@’ in
dnl generated files with -DHAVE_CONFIG_H instead of the value of DEFS.
AC_CONFIG_HEADERS([config.h])

dnl Ensure that a recent enough version of Autoconf is being used.
AC_PREREQ([2.69])

dnl Configure scripts will have a comment with the version of this file.
AC_REVISION([$Revision: 0.1.1$])

dnl This checks if the script is running in the appropiate directory.
AC_CONFIG_SRCDIR([src/my_program.c])

dnl Runs many macros required for proper operation of the generated Makefiles.
dnl -Wall Turn on all categories of warnings.
dnl foreign Automake will check for only those things that are absolutely
dnl     required for proper operation.
dnl subdir-objects If this option is specified, then objects are placed into the
dnl     subdirectory of the build directory corresponding to the subdirectory of
dnl     the source file.
dnl std-options Make the installcheck rule check that installed scripts and
dnl     progrms support the --help and --version options.
AM_INIT_AUTOMAKE([-Wall foreign subdir-objects std-options])

dnl You must use this macro when you use the archiver in your project, if you
dnl want support for unusual archivers such as Microsoft lib.
AM_PROG_AR

dnl Specify dir as the location of additional local Autoconf macros.
AC_CONFIG_MACRO_DIR([m4])

dnl Ensure that a recent enough version of Libtool is being used.
LT_PREREQ([2.2])
dnl This macro adds many new tests to the configure script so that the generated
dnl libtool script will understand the characteristics of the host.
LT_INIT([dlopen shared])

dnl Do compilation tests using the compiler, preprocessor, and file extensions
dnl for the specified language. C and Erlang are supported languages.
AC_LANG(C)
AC_PROG_CC dnl Determines a C compiler to use.
AC_PROG_CXX dnl Determines a C++ compiler to use.
AX_COVERAGE dnl Enables code coverage.
AX_VALGRIND_CHECK dnl Automatically generates rules to run valgrind in tests.
dnl If the Make command, $MAKE if set or else `make', predefines $(MAKE), define
dnl output variable SET_MAKE to be empty. Otherwise, define SET_MAKE to a macro
dnl definition that sets $(MAKE), such as `MAKE=make'.
AC_PROG_MAKE_SET

dnl ############################################################################
dnl Configuration flags.
dnl ############################################################################
dnl Adds feature as a configuration flag.
AC_ARG_ENABLE([MY_FEATURE], dnl feature.
    dnl help-string.
    [AS_HELP_STRING([--enable-my-feature],[Enables my feature.])],
    [], dnl action-if-given.
	[] dnl action-if-not-given.
)
dnl Generates a conditional in Makefiles,"yes" with --enable_my_feature.
AM_CONDITIONAL([ENABLE_MY_FEATURE], [test "x$enable_my_feature" = "xyes"])
AM_COND_IF([ENABLE_MY_FEATURE], (
    AC_DEFINE([ENABLE_MY_FEATURE], [1], [Enables my feature.])))

dnl ############################################################################
dnl Checks for libraries.
dnl ############################################################################
dnl This macro figures out how to build C programs using POSIX threads.
AX_PTHREAD(, [AC_MSG_ERROR([Unable to find library libpthread])])
dnl Check for libcmocka.
AC_CHECK_LIB([cmocka], [_run_group_tests], [],
    [AC_MSG_ERROR([Unable to find library cmocka.])])
dnl Check if clock_gettime, timer_create, timer_settime, and timer_delete are
dnl available in lib rt, and if so, add -lrt to LIBS.
AC_CHECK_LIB([rt], [clock_gettime, timer_create, timer_settime, timer_delete],
    [],[AC_MSG_ERROR([Please install the rt library.])])

dnl ############################################################################
dnl Checks for header files.
dnl ############################################################################
dnl Checks for multiple headers in the system.
dnl AC_CHECK_HEADERS([])

dnl ############################################################################
dnl Checks for typedefs, structures, and compiler characteristics.
dnl ############################################################################
dnl If the C compiler recognizes the restrict keyword, don't do anything. If it
dnl recognizes only a variant spelling (__restrict, __restrict__, or _Restrict),
dnl then define restrict to that. Otherwise, define restrict to be empty. Thus,
dnl programs may simply use restrict as if every C compiler supported it; for
dnl those that do not, the makefile or configuration header defines it away.
AC_C_RESTRICT

dnl ############################################################################
dnl Checks for library functions.
dnl ############################################################################
dnl Search for the following functions.
AC_CHECK_FUNCS([strerror])

dnl ############################################################################
dnl Config files.
dnl ############################################################################
dnl Make AC_OUTPUT create each file by copying an input file (by default
dnl file.in), substituting the output variable values.
AC_CONFIG_FILES([
    Makefile
    src/Makefile
    include/Makefile
    include/my_program/Makefile
    tests/Makefile
])

AC_OUTPUT dnl Generate config.status and launch it.

dnl Check configuration to print it.
if test "x$enable_my_feature" == "xyes"; then
  MY_FEATURE="yes"
  else
  MY_FEATURE="no"
fi

dnl Prints selected configuration.
AC_MSG_NOTICE([
    Host setup:             ${host}
    Install prefix:         ${prefix}
    Compiler:               ${CC}
    CFLAGS:                 ${CFLAGS}
    CPPFLAGS:               ${CPPFLAGS}
    LDFLAGS:                ${LDFLAGS}
    LIBS:                   ${LIBS}
    my_program version:        ${VERSION}
    Build my_program:          Shared=${enable_shared}, Static=${enable_static}
    Built-in manual:        ${user_manual}
    Log level:              ${log_level}
    Valgrind support:       ${enable_valgrind}
    Code coverage support:  ${COVERAGE_SUPPORT}
    My feature:             ${MY_FEATURE}
])
