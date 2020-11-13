/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 2011 Andras Elso                                       |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Andras Elso <elso.andras@gmail.com>                          |
   +----------------------------------------------------------------------+
   */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_title.h"

#include <setproctitle.h>

#define EXT_SETPROCTITLE_VERSION PHP_SETPROCTITLE_VERSION

PHP_FUNCTION(setproctitle) {
  char *src;
  int src_len, r;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &src, &src_len) == FAILURE || src_len < 1) {
    RETURN_FALSE;
  }
  r = setproctitle("%s", src);
  RETURN_LONG(r);
/*
  va_list args;
  va_start(args,format);
  setproctitle(format, args);
  va_end(args);
  RETURN_FALSE;
*/
}

/*
ZEND_BEGIN_ARG_INFO_EX(arginfo_setproctitle, 0, 0, 1)
  ZEND_ARG_INFO(0, format)
  ZEND_ARG_INFO(0, arg1)
  ZEND_ARG_INFO(0, ...)
ZEND_END_ARG_INFO()
*/

ZEND_BEGIN_ARG_INFO(arginfo_setproctitle, 0)
  ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()


/* {{{ setproctitle_functions[] */
zend_function_entry setproctitle_functions[] = {
  PHP_FE(setproctitle, arginfo_setproctitle)
  {NULL, NULL, NULL}
};
/* }}} */

#ifdef COMPILE_DL_SETPROCTITLE
ZEND_GET_MODULE(setproctitle)
#endif

/* {{{ PHP_MINFO_FUNCTION
*/
PHP_MINFO_FUNCTION(setproctitle)
{
  php_info_print_table_start();
  php_info_print_table_row(2, "setproctitle support", "enabled");
  php_info_print_table_row(2, "setproctitle extension version", EXT_SETPROCTITLE_VERSION);
  php_info_print_table_end();

  DISPLAY_INI_ENTRIES();
}
/* }}} */

/* {{{ setproctitle_module_entry
*/
zend_module_entry setproctitle_module_entry = {
  STANDARD_MODULE_HEADER,
  "setproctitle",
  setproctitle_functions,
  NULL,
  NULL,
  NULL,
  NULL,
  PHP_MINFO(setproctitle),
  EXT_SETPROCTITLE_VERSION,
  STANDARD_MODULE_PROPERTIES
};
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * vim: set noet sw=4 ts=4:
 * vim600: noet sw=4 ts=4 fdm=marker:
 * End:
 */
