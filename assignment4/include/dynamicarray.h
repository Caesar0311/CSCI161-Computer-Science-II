#ifndef __DYNAMIC_ARRAY_HEADER__
#define __DYNAMIC_ARRAY_HEADER__

#include <iostream>

const int DEFAULT_CAPACITY = 10;

class DynamicArray {
	protected:
		int capacity;  	//Defines the maximum number of elements that this DynamicArray can hold 
		int size;	//Keeps track of the current number of elements inserted in this DynamicArray
		int* elements;	//Pointer to the array where the elements are inserted.

	public:
		/*
		 * Default constructor
		 */
		DynamicArray();

		/*
		 * Regular constructor
		 */
		DynamicArray(const int max_size);

		/*
		 * Copy constructor
		 */
		DynamicArray(const DynamicArray&);


		/*
		 * Move constructor.
		 */
		DynamicArray(DynamicArray&&);

		/*
		 * Destructor
		 */
		virtual ~DynamicArray();

		/*
		 * Returns true if the array does not contain any element.
		 */
		bool empty();

		/*
		 * Returns the number of elements that have been inserted into the array.
		 */
		int getSize() const;

		/*
		 * Returns maxumum number of elements that this array can hold.
		 */
		int getCapacity() const;



		/*
		 * Inserts an element into the array.
		 */
		virtual	void insert(int element);
		//Check whether the array is full or not.
		//If array is full, create a new array with double capacity.
		//	Copy the elements from the old array to the new array.
		//	Release memory from the old array.
		//	Assign new array pointer to the old array pointer.
		//Insert the new element at the end of the array and increment the size.



		/*
		 * Searches the element in the dynamic array.
		 * Returns the index of the element if found.
		 * Returns -1 otherwise
		 */
		int search(int element);



		/*
		 * Erases the element from the array if it exists. 
		 */
		void erase(int element);
		//Search the element to be erased.
		//If found move all other elements on the right of this element 1 position left.
		//Decrease the size.



		/*
		 * Removes all the elements from the array.
		 */
		void clear();
		//Remove all the elements from the array but keep the memory allocated to the array intact.



		/*
		 * Copy assignment of the array.
		 */
		DynamicArray& operator = (const DynamicArray&);


		/*
		 * Move assignment.
		 */
		DynamicArray& operator = (DynamicArray&&);


		/*
		 * Prefix incerment operation. Increments each element by 1.
		 * Returns its own reference  after the increment.
		 */
		DynamicArray& operator ++ ();


		/*
		 * Postfix increment operation,
		 * Return a DynamicArray with the current state of the elements.
		 * Increments each of its own element by 1.
		 */
		DynamicArray operator ++ (int dummy);


		/*
		 * Prefix decrement operation, Decrements each element by 1.
		 * Returns its own reference after the decrement.
		 */
		DynamicArray& operator -- ();


		/*
		 * Postfix decrement operation, 
		 * Returns a DynamicArray with the current state of the elements.
		 * Decrements each of its own element by 1.
		 */
		DynamicArray operator -- (int dummy);

		
		/*
		 * Returns  a new DynamicArray object where each element is the summation
		 * of the corresponding elements of the two operating DynamicArray objects.
		 * Adds nothing if the second oparand does not have the correspong element
		 * of the first operand, i.e., the second operand has less number of elemnts
		 * compared to the first oparand.
		 * Ignores the extra elements if the second operand has more elements than
		 * the first operand.
		 */
		virtual DynamicArray operator + (const DynamicArray&) const;

		
		
		
		/*
		 * Returns  a new DynamicArray object where each element is the differnce
		 * between the corresponding elements of the two operating DynamicArray objects.
		 * Subracts nothing if the second oparand does not have the correspong element
		 * of the first operand, i.e., the second operand has less number of elemnts
		 * compared to the first oparand.
		 * Ignores the extra elements if the second operand has more elements than
		 * the first operand.
		 */
		virtual DynamicArray operator - (const DynamicArray&) const;


		/*
		 * Returns  a new DynamicArray object where each element is the multiplication
		 * of the corresponding elements of the two operating DynamicArray objects.
		 * Multiplies nothing if the second oparand does not have the correspong element
		 * of the first operand, i.e., the second operand has less number of elemnts
		 * compared to the first oparand.
		 * Ignores the extra elements if the second operand has more elements than
 		 * the first operand.
		 */
		virtual DynamicArray operator * (const DynamicArray&) const;



		/*
		 * Returns nth element of the dynamic array.
		 * Prints error message if the n is out of bound of array index.
		 */
		int operator [] (int) const;
		

		/*
		 * Extracts an element from the input stream and add it into the dynamic array.
		 * If the dynamic array already contains the maximum number of elements that it can
		 * hold, this function should print an error message to the user.
		 */
		friend std::istream& operator >> (std::istream&, DynamicArray&);


		/*
		 * Inserts all elements of the dynamic array into the output stream.
		 * Separate the elements by a space during this insertion.
		 */
		friend std::ostream& operator << (std::ostream&, const DynamicArray&);
};


#endif
