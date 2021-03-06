# Hecate Distributed Server 
# Copyright (C) 2013 Sean Ryan <sryan@evercrack.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

AC_INIT([hecate],[0.0.0],[sryan@evercrack.com])
LT_INIT

AC_CONFIG_SRCDIR(src)
AC_CONFIG_MACRO_DIR([m4])

# Detect the canonical host and target build environment.
AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([tar-ustar nostdinc dist-bzip2 color-tests parallel-tests])
AM_CONFIG_HEADER(src/config.h)

AC_PREREQ(2.62)
AC_COPYRIGHT([This script is under the GPL and is owned by the people in AUTHORS])

AC_ENABLE_SHARED
AC_ENABLE_STATIC

# Checks for Programs
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LIBTOOL

# set default lang
AC_LANG([C++])
AC_REQUIRE_CPP
AX_CXX_COMPILE_STDCXX_11


# Check for C libraries:
AC_LANG_PUSH([C])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(stdlib.h)
AC_CHECK_HEADERS(math.h)
dnl Test for <math.h> header file
AC_CHECK_HEADERS([signal.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_STRUCT_TM


# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([memset select])

# end C check block
AC_LANG_POP([C])


# check sighandler_t in C++
AC_CHECK_TYPES([sighandler_t],[],[],[
#ifdef HAVE_SIGNAL_H
# include <signal.h>
#endif])

# check for glog header
AC_CHECK_HEADERS([glog/logging.h])
AC_CHECK_LIB(glog, main, , [
	AC_MSG_ERROR("Linking against google::glog library failed.")
])

PKG_CHECK_MODULES( CPPUNIT, cppunit >= 1.12 )

# debugging option
AC_ARG_ENABLE(debug,[  --enable-debug     creates debugging code [default=no]],
[ 
   if test x$enableval = xno; then 
		ac_use_debug_code="no"	
   else 
		ac_use_debug_code="yes"
   fi
], [ac_use_debug_code="no"])

if test "$ac_use_debug_code" = "yes"; then
      CFLAGS="$CFLAGS -DDEBUG"
      CXXFLAGS="$CXXFLAGS -DDEBUG"
else
      CFLAGS="$CFLAGS -DNDEBUG"
      CXXFLAGS="$CXXFLAGS -DNDEBUG"
fi

# gprof debugging option
AC_ARG_ENABLE(gprof,[  --enable-gprof     Add flags for gprof [default=no]],
[
   if test x$enableval = xno; then 
		ac_use_gprof_code="no"	
   else 
		ac_use_gprof_code="yes"
   fi
], [ac_use_gprof_code="no"])

if test "$ac_use_gprof_code" = "yes"; then
      CFLAGS="$CFLAGS -pg -g"
      CXXFLAGS="$CXXFLAGS -pg -g"
fi

# gprof debugging option
AC_ARG_ENABLE(effc,[  --enable-effc++     Add warning flags for eff++ [default=no]],
[
   if test x$enableval = xno; then 
		ac_use_effc_code="no"	
   else 
		ac_use_effc_code="yes"
   fi
], [ac_use_effc_code="no"])

if test "$ac_use_effc_code" = "yes"; then
	  # c++ only option
      CXXFLAGS="$CXXFLAGS -Weffc++"
fi

AS_IF([test x"$logdir" = "x"],[logdir="${prefix}/log"])
AS_IF([test x"$rundir" = "x"],[rundir="${prefix}/var"])
AS_IF([test x"$SIGNATURE" = "x"],[SIGNATURE=`uname -a`])
AS_IF([test x"$BUNAME" = "x"],[BUNAME=`uname -a`])
AS_IF([test x"$BHOST" = "x"],[BHOST=`uname -n`])
AS_IF([test x"$BUSER" = "x"],[BUSER=`whoami`])
AS_IF([test x"$BNUM" = "x"],[BNUM=123])
AC_SUBST([logdir])
AC_SUBST([rundir])
AC_SUBST(SIGNATURE)
AC_SUBST(BUNAME)
AC_SUBST(BHOST)
AC_SUBST(BUSER)
AC_SUBST(BNUM)
AC_CONFIG_FILES([Makefile
		 src/Makefile
		 hecate.dox
		 hecate.conf
		 src/Version.hpp
])

AC_OUTPUT

