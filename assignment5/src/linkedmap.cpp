/**
 * @file: linkedmap.cpp
 * @author: Your name goes here
 * Student Number: Your student number goes here
 */

#include "keyvalue.h"
#include "map.h"
#include "node.h"
#include "collection.h"


template<typename K, typename V>
class LinkedMap : public Map<K, V> {
private:
    Node<K, V> *head;
    Node<K, V> *tail;
    int size;

public:
    LinkedMap() : Map<K, V>() {
        head = new Node<K, V>;
        head->next = nullptr;
        tail = head;
        size = 0;
    }

    ~LinkedMap() {
        while (head != nullptr) {
            Node<K, V> *cur = head;
            head = head->next;
            delete cur;
        }
        head = nullptr;
        tail = nullptr;
    }

    int getSize() {
        return size;
    }

    bool put(K key, V value) {
        if (containsKey(key)) {
            return false;
        }
        tail->next = new Node<K, V>(KeyValue<K, V>(key, value));
        tail = tail->next;
        tail->next = nullptr;
        ++size;
        return true;
    }

    V get(K key) {
        Node<K, V> *p = head->next;
        while (p != nullptr) {
            if (p->data.key == key) {
                return p->data.value;
            }
            p = p->next;
        }
    }

    V remove(K key) {
        Node<K, V> *p = head->next;
        Node<K, V> *last_p = head;
        while (p != nullptr) {
            if (p->data.key == key) {
                V value = p->data.value;
                last_p->next = p->next;
                delete p;
                p = nullptr;
                --size;
                return value;
            }
            last_p = last_p->next;
            p = p->next;
        }
    }

    bool containsKey(K key) {
        Node<K, V> *p = head->next;
        while (p != nullptr) {
            if (p->data.key == key) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    bool containsValue(V value) {
        Node<K, V> *p = head->next;
        while (p != nullptr) {
            if (p->data.value == value) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    Collection<K> *keys() {
        Collection<K> *collection = new Collection<K>(size);
        Node<K, V> *p = head->next;
        while (p != nullptr) {
            collection->add(p->data.key);
            p = p->next;
        }
        return collection;
    }

    Collection<V> *values() {
        Collection<V> *collection = new Collection<V>(size);
        Node<K, V> *p = head->next;
        while (p != nullptr) {
            collection->add(p->data.value);
            p = p->next;
        }
        return collection;
    }
};