
extern zend_class_entry *zp_strie_trie_ce;

ZEPHIR_INIT_CLASS(Zp_Strie_Trie);

PHP_METHOD(Zp_Strie_Trie, __construct);
PHP_METHOD(Zp_Strie_Trie, toChar);
PHP_METHOD(Zp_Strie_Trie, toLeaf);
PHP_METHOD(Zp_Strie_Trie, insert);
PHP_METHOD(Zp_Strie_Trie, next);
PHP_METHOD(Zp_Strie_Trie, parent);
zend_object *zephir_init_properties_Zp_Strie_Trie(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zp_strie_trie___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _char, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, _char)
#endif
	ZEND_ARG_INFO(0, parent)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zp_strie_trie_tochar, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zp_strie_trie_tochar, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zp_strie_trie_toleaf, 0, 0, Zp_Strie\\Trie, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zp_strie_trie_toleaf, 0, 0, IS_OBJECT, "Zp_Strie\\Trie", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zp_strie_trie_insert, 0, 1, Zp_Strie\\Trie, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zp_strie_trie_insert, 0, 1, IS_OBJECT, "Zp_Strie\\Trie", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _char, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, _char)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zp_strie_trie_next, 0, 1, Zp_Strie\\Trie, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zp_strie_trie_next, 0, 1, IS_OBJECT, "Zp_Strie\\Trie", 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _char, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, _char)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zp_strie_trie_parent, 0, 0, Zp_Strie\\Trie, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zp_strie_trie_parent, 0, 0, IS_OBJECT, "Zp_Strie\\Trie", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zp_strie_trie_method_entry) {
	PHP_ME(Zp_Strie_Trie, __construct, arginfo_zp_strie_trie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zp_Strie_Trie, toChar, arginfo_zp_strie_trie_tochar, ZEND_ACC_PUBLIC)
	PHP_ME(Zp_Strie_Trie, toLeaf, arginfo_zp_strie_trie_toleaf, ZEND_ACC_PUBLIC)
	PHP_ME(Zp_Strie_Trie, insert, arginfo_zp_strie_trie_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Zp_Strie_Trie, next, arginfo_zp_strie_trie_next, ZEND_ACC_PUBLIC)
	PHP_ME(Zp_Strie_Trie, parent, arginfo_zp_strie_trie_parent, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
