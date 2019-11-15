
extern zend_class_entry *zp_strie_fnt_utf8_ce;

ZEPHIR_INIT_CLASS(Zp_Strie_Fnt_Utf8);

PHP_METHOD(Zp_Strie_Fnt_Utf8, makeWord);
PHP_METHOD(Zp_Strie_Fnt_Utf8, makeText);
PHP_METHOD(Zp_Strie_Fnt_Utf8, toCharList);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zp_strie_fnt_utf8_makeword, 0, 1, Zp_Strie\\Trie, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zp_strie_fnt_utf8_makeword, 0, 1, IS_OBJECT, "Zp_Strie\\Trie", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, word, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, word)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zp_strie_fnt_utf8_maketext, 0, 2, Zp_Strie\\Trie, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zp_strie_fnt_utf8_maketext, 0, 2, IS_OBJECT, "Zp_Strie\\Trie", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
	ZEND_ARG_INFO(0, isWordEnding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zp_strie_fnt_utf8_tocharlist, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zp_strie_fnt_utf8_method_entry) {
	PHP_ME(Zp_Strie_Fnt_Utf8, makeWord, arginfo_zp_strie_fnt_utf8_makeword, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zp_Strie_Fnt_Utf8, makeText, arginfo_zp_strie_fnt_utf8_maketext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zp_Strie_Fnt_Utf8, toCharList, arginfo_zp_strie_fnt_utf8_tocharlist, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
