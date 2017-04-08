#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(ble, 0.0.1, liamkit@gmail.com)
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([src/blescan.cxx])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_SEARCH_LIBS([hci_le_create_conn],[bluetooth], [], [AC_MSG_ERROR([unable to find hci_le_create_conn])])

# Checks for header files.
AC_CHECK_HEADERS([bluetooth/bluetooth.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT(Makefile src/Makefile)
