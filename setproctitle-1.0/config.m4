dnl $Id$
dnl config.m4 for extension setproctitle

PHP_ARG_WITH(setproctitle, for setproctitle support,
[  --with-setproctitle[=DIR] Include setprotitle support])

if test "$PHP_SETPROCTITLE" != "no"; then
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/setproctitle.h"

  if test -r $PHP_SETPROCTITLE/$SEARCH_FOR; then # path given as parameter
    SETPROCTITLE_DIR=$PHP_SETPROCTITLE
  else
    AC_MSG_CHECKING([for setproctitle files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        SETPROCTITLE_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi

  if test -z "$SETPROCTITLE_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall setproctitle])
  fi

  PHP_ADD_INCLUDE($SETPROCTITLE_DIR/include)

  dnl # --with-setproctitle -> check for lib and symbol presence
  LIBNAME=setproctitle
  LIBSYMBOL=setproctitle

  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SETPROCTITLE_DIR/lib, SETPROCTITLE_SHARED_LIBADD)
    AC_DEFINE(HAVE_SETPROCTITLELIB,1,[ ])
  ],[
    AC_MSG_ERROR([wrong setproctitle lib version or lib not found])
  ],[
    -L$SETPROCTITLE_DIR/lib -lm -ldl
  ])
  PHP_SUBST(SETPROCTITLE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(setproctitle, title.c, $ext_shared)
fi
