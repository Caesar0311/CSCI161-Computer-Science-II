#ifndef __KEYVALUE_HEADER__
#define __KEYVALUE_HEADER__

/*
 * Forward declaration of ArrayMap class to make it friend of KeyValue class
 */
template <typename K, typename V> class ArrayMap;

/*
 * Forward declaration of LinkedMap class to make it friend of KeyValue class
 */
template <typename K, typename V> class LinkedMap;

/*
 * Defination of KeyValue class.
 * KeyValue class will be used by both ArrayMap and LinkedMap classes
 */
template <typename K, typename V>
class KeyValue {
	private:
		K key;
		V value;
	public:
		KeyValue(){};
		KeyValue(K key, V value): key(key), value(value) {}
		friend class ArrayMap<K,V>;
		friend class LinkedMap<K,V>;

};

#endif
