
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Zp_Strie_Fnt) {

	ZEPHIR_REGISTER_CLASS(Zp_Strie, Fnt, zp_strie, fnt, zp_strie_fnt_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Zp_Strie_Fnt, makeWord) {

	unsigned char _5$$3;
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _3, _4;
	zval *word_param = NULL, ch, trie, _0, local, _1, _6$$3, _7$$3;
	zval word;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&word);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&trie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &word_param);

	if (UNEXPECTED(Z_TYPE_P(word_param) != IS_STRING && Z_TYPE_P(word_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'word' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(word_param) == IS_STRING)) {
		zephir_get_strval(&word, word_param);
	} else {
		ZEPHIR_INIT_VAR(&word);
		ZVAL_EMPTY_STRING(&word);
	}


	ZEPHIR_INIT_VAR(&trie);
	object_init_ex(&trie, zp_strie_trie_ce);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &trie, "__construct", NULL, 1, &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&local, &trie);
	_4 = (zephir_fast_strlen_ev(&word) - 1);
	_3 = 0;
	_2 = 0;
	if (_3 <= _4) {
		while (1) {
			if (_2) {
				_3++;
				if (!(_3 <= _4)) {
					break;
				}
			} else {
				_2 = 1;
			}
			i = _3;
			_5$$3 = ZEPHIR_STRING_OFFSET(&word, i);
			ZEPHIR_INIT_NVAR(&ch);
			ZVAL_LONG(&ch, _5$$3);
			ZVAL_LONG(&_7$$3, ((int) (zephir_get_numberval(&ch)) << 1));
			ZEPHIR_CALL_METHOD(&_6$$3, &local, "insert", &_8, 0, &_7$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&local, &_6$$3);
		}
	}
	RETURN_CCTOR(&trie);

}

PHP_METHOD(Zp_Strie_Fnt, makeText) {

	unsigned char _5$$3;
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _3, _4;
	zval *text_param = NULL, *isWordEnding, isWordEnding_sub, ch, trie, _0, local, _1, _6$$3, _8$$5, _9$$5;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&isWordEnding_sub);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&trie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &text_param, &isWordEnding);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&trie);
	object_init_ex(&trie, zp_strie_trie_ce);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &trie, "__construct", NULL, 1, &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&local, &trie);
	_4 = (zephir_fast_strlen_ev(&text) - 1);
	_3 = 0;
	_2 = 0;
	if (_3 <= _4) {
		while (1) {
			if (_2) {
				_3++;
				if (!(_3 <= _4)) {
					break;
				}
			} else {
				_2 = 1;
			}
			i = _3;
			_5$$3 = ZEPHIR_STRING_OFFSET(&text, i);
			ZEPHIR_INIT_NVAR(&ch);
			ZVAL_LONG(&ch, _5$$3);
			ZEPHIR_CALL_ZVAL_FUNCTION(&_6$$3, isWordEnding, NULL, 0, &ch, &local);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$3)) {
				ZEPHIR_CALL_METHOD(NULL, &local, "toleaf", &_7, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&local, &trie);
			} else {
				ZVAL_LONG(&_9$$5, ((int) (zephir_get_numberval(&ch)) << 1));
				ZEPHIR_CALL_METHOD(&_8$$5, &local, "insert", &_10, 0, &_9$$5);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&local, &_8$$5);
			}
		}
	}
	RETURN_CCTOR(&trie);

}

PHP_METHOD(Zp_Strie_Fnt, toCharList) {

	unsigned char _4$$3;
	zend_bool _1;
	zval charList;
	zend_long i = 0, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *text_param = NULL, ch, _0, _5$$3;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&charList);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&charList);
	array_init(&charList);
	_3 = (zephir_fast_strlen_ev(&text) - 1);
	_2 = 0;
	_1 = 0;
	if (_2 <= _3) {
		while (1) {
			if (_1) {
				_2++;
				if (!(_2 <= _3)) {
					break;
				}
			} else {
				_1 = 1;
			}
			i = _2;
			_4$$3 = ZEPHIR_STRING_OFFSET(&text, i);
			ZEPHIR_INIT_NVAR(&ch);
			ZVAL_LONG(&ch, _4$$3);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_LONG(&_5$$3, ((int) (zephir_get_numberval(&ch)) << 1));
			zephir_array_append(&charList, &_5$$3, PH_SEPARATE, "zp_strie/fnt.zep", 50);
		}
	}
	RETURN_CTOR(&charList);

}

PHP_METHOD(Zp_Strie_Fnt, toUtf8CharList) {

	unsigned char _4$$3;
	zend_bool _1, _5$$5;
	zval charList;
	zend_long i = 0, ch = 0, utf8Ch = 0, octetSize = 0, cnt = 0, zChar = 0, code = 0, _2, _3, _6$$5, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *text_param = NULL, _0, _8$$10;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&charList);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}


	ZEPHIR_INIT_VAR(&charList);
	array_init(&charList);
	octetSize = 0;
	utf8Ch = 0;
	_3 = (zephir_fast_strlen_ev(&text) - 1);
	_2 = 0;
	_1 = 0;
	if (_2 <= _3) {
		while (1) {
			if (_1) {
				_2++;
				if (!(_2 <= _3)) {
					break;
				}
			} else {
				_1 = 1;
			}
			i = _2;
			_4$$3 = ZEPHIR_STRING_OFFSET(&text, i);
			ch = _4$$3;
			if (octetSize == 0) {
				utf8Ch = 0;
				cnt = 7;
				while (1) {
					if (!(cnt != 3)) {
						break;
					}
					zChar = (ch >> cnt);
					code = 0;
					_7$$5 = (8 - cnt);
					_6$$5 = 1;
					_5$$5 = 0;
					if (_6$$5 <= _7$$5) {
						while (1) {
							if (_5$$5) {
								_6$$5++;
								if (!(_6$$5 <= _7$$5)) {
									break;
								}
							} else {
								_5$$5 = 1;
							}
							_6$$5 = _6$$5;
							code = (((code << 1)) | 1);
						}
					}
					if (zChar != code) {
						if (cnt == 7) {
							octetSize = (8 - cnt);
						} else {
							octetSize = ((8 - cnt) - 1);
						}
						break;
					}
					cnt = (cnt - 1);
				}
			}
			utf8Ch = (((utf8Ch << ((octetSize * 8)))) | ch);
			octetSize = (octetSize - 1);
			if (octetSize == 0) {
				ZEPHIR_INIT_NVAR(&_8$$10);
				ZVAL_LONG(&_8$$10, utf8Ch);
				zephir_array_append(&charList, &_8$$10, PH_SEPARATE, "zp_strie/fnt.zep", 98);
			}
		}
	}
	RETURN_CTOR(&charList);

}

