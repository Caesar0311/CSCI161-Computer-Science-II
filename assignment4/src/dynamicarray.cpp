/**
 * @file: dynamicarray.cpp
 * @author: Your name goes here
 * Student Number: Your student number goes here
 */

#include "dynamicarray.h"
#include <fstream>

using namespace std;

DynamicArray::DynamicArray(){
	elements=new int[DEFAULT_CAPACITY];
	
	this->capacity=DEFAULT_CAPACITY;
	this->size=0;
}

/*
* Regular constructor
*/
DynamicArray::DynamicArray(const int max_size){
	elements=new int[max_size];
	
	this->capacity=max_size;
	this->size=0;
}

/*
* Copy constructor
*/
DynamicArray::DynamicArray(const DynamicArray&darray){
	this->capacity=darray.getCapacity();
	elements=new int[capacity];
	
	this->size=darray.getSize();
	
	//loop to copy elements
	for(int i=0;i<size;i++)
		elements[i]=darray.elements[i];	
}

/*
 * Move constructor.
 */
DynamicArray::DynamicArray(DynamicArray&&darray){
	this->elements=new int[darray.capacity];
	this->capacity=darray.capacity;
	this->size=darray.size;
	
	//loop to copy elements
	for(int i=0;i<size;i++)
		this->elements[i]=darray.elements[i];
}

/*
 * Destructor
 */
DynamicArray::~DynamicArray(){
	delete [] elements;
}

/*
 * Returns true if the array does not contain any element.
 */
bool DynamicArray::empty(){
	return this->size==0;
}

/*
 * Returns the number of elements that have been inserted into the array.
 */
int DynamicArray::getSize() const{
	return this->size;
}

/*
 * Returns maxumum number of elements that this array can hold.
 */
int DynamicArray::getCapacity() const{
	return this->capacity;
}

/*
 * Inserts an element into the array.
 */
//Check whether the array is full or not.
//If array is full, create a new array with double capacity.
//	Copy the elements from the old array to the new array.
//	Release memory from the old array.
//	Assign new array pointer to the old array pointer.
//Insert the new element at the end of the array and increment the size.
void DynamicArray::insert(int element){
	//check if the dynamic array is full
	if(this->size==this->capacity){
		this->capacity=this->capacity*2;	
		int *arr=new int[this->capacity];
		
		int i;		
		//loop to copy elements from this to arr
		for(i=0;i<this->size;i++)
			arr[i]=this->elements[i];
		arr[i]=element;		
		
		delete [] elements;
		elements=arr;			
	}else
		elements[size]=element;

	this->size++;
}

/*
 * Searches the element in the dynamic array.
 * Returns the index of the element if found.
 * Returns -1 otherwise
 */
int DynamicArray::search(int element){
	int index=-1;
	
	for(int i=0;i<this->size;i++){
		
		//if find the element
		if(elements[i]==element){
			index=i;
			break;
		}
	}
	return index;
}

/*
 * Erases the element from the array if it exists. 
 */
//Search the element to be erased.
//If found move all other elements on the right of this element 1 position left.
//Decrease the size.
void DynamicArray::erase(int element){
	for(int i=0;i<this->size;i++){
		
		//if find the element, erase it
		if(elements[i]==element){
			this->size--;
			
			for(int j=i;j<this->size;j++)
				elements[j]=elements[j+1];
			
			break;
		}
	}
}

/*
 * Removes all the elements from the array.
 */
//Remove all the elements from the array but keep the memory allocated to the array intact.
void DynamicArray::clear(){
	this->size=0;
}

/*
 * Copy assignment of the array.
 */
DynamicArray& DynamicArray::operator = (const DynamicArray&darray){
	//delete elements
	delete [] this->elements;	
	
	this->elements=new int[darray.capacity];
	this->capacity=darray.capacity;
	this->size=darray.size;
	
	//loop to copy elements from darray to this
	for(int i=0;i<size;i++)
		this->elements[i]=darray.elements[i];
	
	return *this;
}

/*
 * Move assignment.
 */
DynamicArray& DynamicArray::operator = (DynamicArray&&darray){
	//delete elements
	delete [] this->elements;	
	
	this->elements=new int[darray.capacity];
	this->capacity=darray.capacity;
	this->size=darray.size;
	
	//loop to copy elements from darray to this
	for(int i=0;i<size;i++)
		this->elements[i]=darray.elements[i];
	
	return *this;
}

/*
 * Prefix incerment operation. Increments each element by 1.
 * Returns its own reference  after the increment.
 */
DynamicArray& DynamicArray::operator ++ (){
	//loop to increment each element in this
	for(int i=0;i<size;i++)
		++this->elements[i];
	
	return *this;
}

/*
 * Postfix increment operation,
 * Return a DynamicArray with the current state of the elements.
 * Increments each of its own element by 1.
 */
DynamicArray DynamicArray::operator ++ (int dummy){
	//loop to increment each element in this
	for(int i=0;i<size;i++)
		this->elements[i]++;
	
	return *this;
}

/*
 * Prefix decrement operation, Decrements each element by 1.
 * Returns its own reference after the decrement.
 */
DynamicArray& DynamicArray::operator -- (){
	//loop to decrement each element in this
	for(int i=0;i<size;i++)
		--this->elements[i];
	
	return *this;
}

/*
 * Postfix decrement operation, 
 * Returns a DynamicArray with the current state of the elements.
 * Decrements each of its own element by 1.
 */
DynamicArray DynamicArray::operator -- (int dummy){
	//loop to decrement each element in this
	for(int i=0;i<size;i++)
		--this->elements[i];
	
	return *this;
}

/*
 * Returns  a new DynamicArray object where each element is the summation
 * of the corresponding elements of the two operating DynamicArray objects.
 * Adds nothing if the second oparand does not have the correspong element
 * of the first operand, i.e., the second operand has less number of elemnts
 * compared to the first oparand.
 * Ignores the extra elements if the second operand has more elements than
 * the first operand.
 */
DynamicArray DynamicArray::operator + (const DynamicArray&darray) const{
	int len=this->size;
	if(this->size>darray.size)
		len=darray.size;
	
	DynamicArray darr(this->capacity);
	int i;
	//loop to add the corresponding elements in this and darray
	for(i=0;i<len;i++)
		darr.elements[i]=elements[i]+darray.elements[i];
	
	if(this->size>darray.size){
		for(int j=i;j<this->size;j++)
			darr.elements[j]=elements[i];
	}
	
	darr.size=this->size;
	return darr;
}

/*
 * Returns  a new DynamicArray object where each element is the differnce
 * between the corresponding elements of the two operating DynamicArray objects.
 * Subracts nothing if the second oparand does not have the correspong element
 * of the first operand, i.e., the second operand has less number of elemnts
 * compared to the first oparand.
 * Ignores the extra elements if the second operand has more elements than
 * the first operand.
 */
DynamicArray DynamicArray::operator - (const DynamicArray&darray) const{
	int len=this->size;
	if(this->size>darray.size)
		len=darray.size;
	
	DynamicArray darr(this->capacity);
	int i;
	//loop to subtract the corresponding elements in this and darray
	for(i=0;i<len;i++)
		darr.elements[i]=elements[i]-darray.elements[i];
	
	if(this->size>darray.size){
		for(int j=i;j<this->size;j++)
			darr.elements[j]=elements[j];
	}
	
	darr.size=this->size;
	return darr;	
}

/*
 * Returns  a new DynamicArray object where each element is the multiplication
 * of the corresponding elements of the two operating DynamicArray objects.
 * Multiplies nothing if the second oparand does not have the correspong element
 * of the first operand, i.e., the second operand has less number of elemnts
 * compared to the first oparand.
 * Ignores the extra elements if the second operand has more elements than
	 * the first operand.
 */
DynamicArray DynamicArray::operator * (const DynamicArray&darray) const{
	int len=this->size;
	if(this->size>darray.size)
		len=darray.size;
	
	DynamicArray darr(this->capacity);
	int i;
	//loop to multiply the corresponding elements in this and darray
	for(i=0;i<len;i++)
		darr.elements[i]=elements[i]*darray.elements[i];
	
	if(this->size>darray.size){
		for(int j=i;j<this->size;j++)
			darr.elements[j]=elements[i];
	}
	
	darr.size=this->size;
	return darr;		
}

/*
 * Returns nth element of the dynamic array.
 * Prints error message if the n is out of bound of array index.
 */
int DynamicArray::operator [] (int n) const{
	//check if n is out of bound
	if(n<0||n>=this->size){
		cout<<"Index out of bound!"<<endl;
		return -1;
	}
	
	return this->elements[n];
}

/*
 * Extracts an element from the input stream and add it into the dynamic array.
 * If the dynamic array already contains the maximum number of elements that it can
 * hold, this function should print an error message to the user.
 */
std::istream& operator >> (std::istream& ist, DynamicArray&darray){
	int data;
	if(ist>>data){		
		//check if darray is full
		if(darray.getCapacity()==darray.getSize()){
			cout<<"the dynamic array already contains the maximum number of elements that it can hold"<<endl;
			return ist;
		}
		
		darray.insert(data);
	}
		
	return ist;
}

/*
 * Inserts all elements of the dynamic array into the output stream.
 * Separate the elements by a space during this insertion.
 */
std::ostream& operator << (std::ostream& ost, const DynamicArray&darray){
	//loop to write elements in darray to ost
	for(int i=0;i<darray.getSize();i++)
		ost<<darray[i]<<" ";
	
	return ost;
}
