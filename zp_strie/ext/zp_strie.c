
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "zp_strie.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *zp_strie_fnt_ce;
zend_class_entry *zp_strie_fnt_utf8_ce;
zend_class_entry *zp_strie_trie_ce;

ZEND_DECLARE_MODULE_GLOBALS(zp_strie)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(zp_strie)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Zp_Strie_Fnt);
	ZEPHIR_INIT(Zp_Strie_Fnt_Utf8);
	ZEPHIR_INIT(Zp_Strie_Trie);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(zp_strie)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zp_strie_globals *zp_strie_globals TSRMLS_DC)
{
	zp_strie_globals->initialized = 0;

	/* Cache Enabled */
	zp_strie_globals->cache_enabled = 1;

	/* Recursive Lock */
	zp_strie_globals->recursive_lock = 0;

	/* Static cache */
	memset(zp_strie_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_zp_strie_globals *zp_strie_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(zp_strie)
{
	zend_zp_strie_globals *zp_strie_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	zp_strie_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zp_strie_globals_ptr);
	zephir_initialize_memory(zp_strie_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(zp_strie)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(zp_strie)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ZP_STRIE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ZP_STRIE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ZP_STRIE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ZP_STRIE_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ZP_STRIE_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(zp_strie)
{
	php_zephir_init_globals(zp_strie_globals);
	php_zephir_init_module_globals(zp_strie_globals);
}

static PHP_GSHUTDOWN_FUNCTION(zp_strie)
{
	
}


zend_function_entry php_zp_strie_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_zp_strie_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry zp_strie_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_zp_strie_deps,
	PHP_ZP_STRIE_EXTNAME,
	php_zp_strie_functions,
	PHP_MINIT(zp_strie),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(zp_strie),
#else
	NULL,
#endif
	PHP_RINIT(zp_strie),
	PHP_RSHUTDOWN(zp_strie),
	PHP_MINFO(zp_strie),
	PHP_ZP_STRIE_VERSION,
	ZEND_MODULE_GLOBALS(zp_strie),
	PHP_GINIT(zp_strie),
	PHP_GSHUTDOWN(zp_strie),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(zp_strie),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ZP_STRIE
ZEND_GET_MODULE(zp_strie)
#endif
