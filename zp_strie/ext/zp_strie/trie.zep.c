
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Zp_Strie_Trie) {

	ZEPHIR_REGISTER_CLASS(Zp_Strie, Trie, zp_strie, trie, zp_strie_trie_method_entry, 0);

	zend_declare_property_null(zp_strie_trie_ce, SL("_char"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(zp_strie_trie_ce, SL("children"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(zp_strie_trie_ce, SL("parent"), ZEND_ACC_PRIVATE);

	zp_strie_trie_ce->create_object = zephir_init_properties_Zp_Strie_Trie;
	return SUCCESS;

}

PHP_METHOD(Zp_Strie_Trie, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *_char_param = NULL, *parent = NULL, parent_sub, __$null, _0, _1;
	zend_long _char;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parent_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_char_param, &parent);

	_char = zephir_get_intval(_char_param);
	if (!parent) {
		parent = &parent_sub;
		parent = &__$null;
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, _char);
	zephir_update_property_zval(this_ptr, SL("_char"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (ZEPHIR_IS_EMPTY(parent)) {
		ZEPHIR_CPY_WRT(&_1, this_ptr);
	} else {
		ZEPHIR_CPY_WRT(&_1, parent);
	}
	zephir_update_property_zval(this_ptr, SL("parent"), &_1);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zp_Strie_Trie, toChar) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_char");

}

PHP_METHOD(Zp_Strie_Trie, toLeaf) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_char"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, ((int) (zephir_get_numberval(&_0)) | 1));
	zephir_update_property_zval(this_ptr, SL("_char"), &_1);
	RETURN_THISW();

}

PHP_METHOD(Zp_Strie_Trie, insert) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *_char_param = NULL, _0, _6, _7, _1$$4, _2$$4, _3$$5, _4$$5, _5$$5;
	zend_long _char, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_char_param);

	_char = zephir_get_intval(_char_param);


	zephir_read_property(&_0, this_ptr, SL("children"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_long(&_0, (_char >> 1))) {
		if ((_char & 1)) {
			zephir_read_property(&_1$$4, this_ptr, SL("children"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_long(&_2$$4, &_1$$4, (_char >> 1), PH_NOISY | PH_READONLY, "zp_strie/trie.zep", 31);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "toleaf", NULL, 0);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, zp_strie_trie_ce);
		ZVAL_LONG(&_4$$5, _char);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 1, &_4$$5, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_LONG(&_5$$5, (_char >> 1));
		zephir_update_property_array(this_ptr, SL("children"), &_5$$5, &_3$$5);
	}
	zephir_read_property(&_6, this_ptr, SL("children"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_7, &_6, (_char >> 1), PH_NOISY | PH_READONLY, "zp_strie/trie.zep", 37);
	RETURN_CTOR(&_7);

}

PHP_METHOD(Zp_Strie_Trie, next) {

	zval *_char_param = NULL, _0, _1$$3, _2$$3;
	zend_long _char;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	zephir_fetch_params_without_memory_grow(1, 0, &_char_param);

	_char = zephir_get_intval(_char_param);


	zephir_read_property(&_0, this_ptr, SL("children"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_long(&_0, (_char >> 1))) {
		zephir_read_property(&_1$$3, this_ptr, SL("children"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_2$$3, &_1$$3, (_char >> 1), PH_NOISY | PH_READONLY, "zp_strie/trie.zep", 43);
		RETURN_CTORW(&_2$$3);
	}
	RETURN_NULL();

}

PHP_METHOD(Zp_Strie_Trie, parent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parent");

}

zend_object *zephir_init_properties_Zp_Strie_Trie(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("children"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("children"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

