#ifndef __NODE_HEADER__
#define __NODE_HEADER__

#include "keyvalue.h"

/*
 * Forward declaration of LinkedMap class to make it friend of Node class
 */
template <typename K, typename V> class LinkedMap;

/*
 * Definition of Node class.
 * Node class will be used by LinkedMap class
 */
template <typename K, typename V>
class Node {
	private:
		KeyValue<K,V> data;
		Node* next;
	public:
		Node(): next(NULL) {}
		Node(KeyValue<K,V> data): data(data), next(NULL) {}
		friend class LinkedMap<K,V>;

};

#endif
