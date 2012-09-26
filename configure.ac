#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([xForce], [0.0], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([xForce.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(xForce, 0.0)

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([memory.h stdlib.h string.h gcd.h xForce.h byte_alignment.h list.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([gettimeofday])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
