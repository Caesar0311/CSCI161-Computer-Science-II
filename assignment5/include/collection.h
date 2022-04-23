/**
 * @file: collection.h
 * @author: Humayun Kabir
 */



#ifndef __COLLECTION_HEADER__
#define __COLLECTION_HEADER__

#include <iostream>
#include <string>

using namespace std;

/**
 * Defination of Collection class.
 * Collection template class can be used to represent a collection of objects of any type T.
 */
template <typename T>
class Collection {
	private:
		static const int DEFAULT_CAPACITY = 10;
		int capacity;
		int size;
		T* elements;
	public:
		/*
		 * Default constructor
		 */
		Collection(): capacity(DEFAULT_CAPACITY), size(0), elements(new T[DEFAULT_CAPACITY]) {}
		
		/*
		 * Regular constructor
		 */
		Collection(int capacity): capacity(capacity), size(0), elements(new T[capacity]) {}
		
		/*
		 * Destructor
		 */
		~Collection() {delete [] elements;}
		
		/*
		 * Copy constructor
		 */
		Collection(const Collection& other): capacity(other.capacity), size(other.size), elements(new T[other.capacity]) {
			for(int i =0; i<size; i++) {
				elements[i] = other.elements[i];
			}
		}

		/*
		 * Move constructor
		 */
		Collection(Collection&& temp): capacity(temp.capacity), size(temp.size), elements(temp.elements) { }

		/*
		 * Copy assignment
		 */
		Collection& operator = (const Collection& other) {
			capacity = other.capacity;
			size = other.size;
			delete [] elements;
			elements = new T[other.capacity];
			for(int i=0; i<size; i++ ) {
				elements[i] = other.elements[i];
			}
			return (*this);
		}

		/*
		 * Move assignment
		 */
		Collection& operator = (Collection&& temp) {
			capacity = temp.capacity;
			size = temp.size;
			delete []  elements;
			elements = temp.elemennts;
			temp.elements = NULL;
			return *this;
		}
		
		/*
		 * Returns the capacity of the collection
		 */
		int getCapacity() { return capacity;}
		
		/*
		 * Returns the current size of the collection
		 */
		int getSize() { return size; }
		
		/*
		 * Adds an element of type T into the collection
		 */
		bool add(T element) {
			if(size<capacity) {
				elements[size++] = element;
				return true;
			}
			else {
				return false;
			}
		}

		/*
		 * Returns the element at the specified index from the collection
		 */
		T get(int index) {
			if(index>=size || index<0) {
				throw string("Out of Index");
			}

			return elements[index];
		}

		/*
		 * Returns the element at the specified index from the collection
		 */
		T operator [] (int index) {
			return get(index);
		}
};

#endif
