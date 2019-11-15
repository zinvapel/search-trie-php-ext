
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ZP_STRIE_H
#define PHP_ZP_STRIE_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ZP_STRIE_NAME        "zp_strie"
#define PHP_ZP_STRIE_VERSION     "0.0.1"
#define PHP_ZP_STRIE_EXTNAME     "zp_strie"
#define PHP_ZP_STRIE_AUTHOR      "Pavel Murtazin"
#define PHP_ZP_STRIE_ZEPVERSION  "0.12.11-$Id$"
#define PHP_ZP_STRIE_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(zp_strie)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(zp_strie)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(zp_strie)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(zp_strie, v)
#else
	#define ZEPHIR_GLOBAL(v) (zp_strie_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_zp_strie_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(zp_strie_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(zp_strie_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def zp_strie_globals
#define zend_zephir_globals_def zend_zp_strie_globals

extern zend_module_entry zp_strie_module_entry;
#define phpext_zp_strie_ptr &zp_strie_module_entry

#endif
