/**
 * @file: arraymap.cpp
 * @author: Your name goes here
 * Student Number: Your student number goes here
 */

#include "map.h"
#include "collection.h"

template<typename K, typename V>
class ArrayMap : public Map<K, V> {
private:
    K *keyList;
    V *valueList;
    int capacity;
    int size;
public:
    ArrayMap(int c) : Map<K, V>() {
        keyList = new K[c];
        valueList = new V[c];
        capacity = c;
        size = 0;
    }

    ~ArrayMap() {
        delete[] keyList;
        delete[] valueList;
        keyList = nullptr;
        valueList = nullptr;
    }

    int getSize() {
        return size;
    }

    bool put(K key, V value) {
        if (containsKey(key)) {
            return false;
        }
        keyList[size] = key;
        valueList[size] = value;
        ++size;
        return true;
    }

    V get(K key) {
        for (int i = 0; i < size; ++i) {
            if (key == keyList[i]) {
                return valueList[i];
            }
        }
    }

    V remove(K key) {
        int i = 0;
        for (; i < size; ++i) {
            if (key == keyList[i]) {
                break;
            }
        }
        V value = valueList[i];
        for (; i < size - 1; ++i) {
            keyList[i] = keyList[i + 1];
            valueList[i] = valueList[i + 1];
        }
        --size;
        return value;
    }

    bool containsKey(K key) {
        for (int i = 0; i < size; ++i) {
            if (key == keyList[i]) {
                return true;
            }
        }
        return false;
    }

    bool containsValue(V value) {
        for (int i = 0; i < size; ++i) {
            if (value == valueList[i]) {
                return true;
            }
        }
        return false;
    }

    Collection<K> *keys() {
        Collection<K>* collection = new Collection<K>(size);
        for (int i = 0; i < size; ++i) {
            collection->add(keyList[i]);
        }
        return collection;
    }
    Collection<V>* values() {
        Collection<V>* collection = new Collection<V>(size);
        for (int i = 0; i < size; ++i) {
            collection->add(valueList[i]);
        }
        return collection;
    }
};
