/**
 * @file: simpleset.cpp
 * @author: Your name goes here
 * Student Number: Your student number goes here
 */

#include "simpleset.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
 * Default constructor
 */
SimpleSet::SimpleSet(){
}

/*
 * Regular constructor
 */
SimpleSet::SimpleSet(int max_size):DynamicArray(max_size){
}

/*
 * Copy constructor
 */
SimpleSet::SimpleSet(const SimpleSet& set):DynamicArray(set){
}

/*
 * Move constructor.
 */
SimpleSet::SimpleSet(SimpleSet&& set):DynamicArray(set){
}

/*
 * Destructor
 */
SimpleSet::~SimpleSet(){
}

/*
 * Inserts an element into the set only if there is no other element with the same value.
 * Increases the max_size to the twice of its current value if the number of elements in 
 * the set exceeds the current max_size.
 */
//Check whether there is an exisiting element in the set with the same value.
//Insert the new element at the end of set if there is no other element in the set with
//the same value.
//Incease the max_size to the twice of its current value if the number of elements in the
//set exceeds the current max_size. 
//Reallocate memory for increased max_size. 
//Copy the old elements to the newly allocated memory locations. 
//Add the new element at the end of the old elements in the newly allocated memory.
//Free previously allocated memory. 
//Assign the address of the newly allocated memory to the appropriate pointer of the set.
void SimpleSet::insert(int element){
	int index=this->search(element);
	
	//if not find the element in this
	if(index==-1)
		DynamicArray::insert(element);	
}

/*
 * Copy assignment of the set.
 */
SimpleSet& SimpleSet::operator = (const SimpleSet&set){
	delete [] this->elements;	
	
	this->elements=new int[set.capacity];
	this->capacity=set.capacity;
	this->size=set.size;
	
	//loop to copy elements from set to this 
	for(int i=0;i<size;i++)
		this->elements[i]=set[i];
	
	return *this;	
}

/*
 * Move assignment.
 */
SimpleSet& SimpleSet::operator = (SimpleSet&&set){
	delete [] this->elements;	
	
	this->elements=new int[set.capacity];
	this->capacity=set.capacity;
	this->size=set.size;
	
	//loop to copy elements from set to this 
	for(int i=0;i<size;i++)
		this->elements[i]=set[i];
	
	return *this;	
}

/*
 * Overloading + operator to perfomr set union operation.
 */
SimpleSet SimpleSet::operator + (const SimpleSet&set) const{
	SimpleSet set1;
	//loop to insert elements in this to set1
	for(int i=0;i<this->size;i++)
		set1.insert(this->elements[i]);
	
	//loop to insert elements in set to set1
	for(int i=0;i<set.size;i++)
		set1.insert(set.elements[i]);
	
	return set1;
}

/*
 * Overloading - operator to perform set difference operation
 */
SimpleSet SimpleSet::operator - (const SimpleSet & set) const{
	SimpleSet set1;
	
	//loop to insert elements in this but not in set to set1
	for(int i=0;i<this->size;i++){
		int element=this->elements[i];
		
		bool find=false;
		for(int j=0;j<set.size;j++){
			if(element==set.elements[j]){
				find=true;
				break;
			}
		}
		
		if(!find)
			set1.insert(element);
	}
	return set1;
}

/*
 * Overloading * operator to perform set intersection operation.
 */
SimpleSet SimpleSet::operator * (const SimpleSet&set) const{
	SimpleSet set1;
	
	//loop to insert elements in this and also in set to set1
	for(int i=0;i<this->size;i++){
		int element=this->elements[i];
		
		bool find=false;
		for(int j=0;j<set.size;j++){
			if(element==set.elements[j]){
				find=true;
				break;
			}
		}
		
		if(find)
			set1.insert(this->elements[i]);
	}
	return set1;	
}

/*
 * Extracts an element from the input stream and inserts the element
 * into the set only if there is no other element in the set with 
 * same value. If an element with the same value already exists
 * returns from the function without insering the element.
 * If the set already contains the maximum number of elements, this 
 * function should through an exception.
 */
std::istream& operator >> (std::istream&ist, SimpleSet&set) throw (std::string){		
	int data;	
	if(ist>>data){
		//if the set is full, throw an exception
		if(set.getCapacity()==set.getSize())
			throw "the set already contains the maximum number of elements";
		
		set.insert(data);
	}
	return ist;
}

/*
 * Inserts all elements of the set into the output stream.
 * Separate the elements by a space during this insertion.
 */
std::ostream& operator << (std::ostream&ost, const SimpleSet&set){
	//loop to write elements in darray to ost
	for(int i=0;i<set.getSize();i++)
		ost<<set[i]<<" ";
	
	return ost;	
}
