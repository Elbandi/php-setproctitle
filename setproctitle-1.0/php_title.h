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

/* $Id$ */

#ifndef PHP_TITLE_H
#define PHP_TITLE_H

extern zend_module_entry setproctitle_module_entry;
#define phpext_setproctitle_ptr &setproctitle_module_entry

#define PHP_SETPROCTITLE_VERSION "0.1"

#ifdef PHP_WIN32
#define PHP_SETPROCTITLE_API __declspec(dllexport)
#else
#define PHP_SETPROCTITLE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINFO_FUNCTION(setproctitle);

PHP_FUNCTION(setproctitle);

#ifdef ZTS
#define SETPROCTITLE_G(v) TSRMG(setproctitle_globals_id, zend_setproctitle_globals *, v)
#else
#define SETPROCTITLE_G(v) (setproctitle_globals.v)
#endif

#endif	/* PHP_TITLE_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
