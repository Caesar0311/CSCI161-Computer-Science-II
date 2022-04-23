#ifndef __SIMPLESET_HEADER__
#define __SIMPLESET_HEADER__

#include "dynamicarray.h"

class SimpleSet: public DynamicArray {
	private:

	public:
		/*
		 * Default constructor
		 */
		SimpleSet();

		/*
		 * Regular constructor
		 */
		SimpleSet(int max_size);

		/*
		 * Copy constructor
		 */
		SimpleSet(const SimpleSet&);


		/*
		 * Move constructor.
		 */
		SimpleSet(SimpleSet&&);

		/*
		 * Destructor
		 */
		~SimpleSet();

		/*
		 * Inserts an element into the set only if there is no other element with the same value.
		 * Increases the max_size to the twice of its current value if the number of elements in 
		 * the set exceeds the current max_size.
		 */
		void insert(int element);
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


		/*
		 * Copy assignment of the set.
		 */
		SimpleSet& operator = (const SimpleSet&);


		/*
		 * Move assignment.
		 */
		SimpleSet& operator = (SimpleSet&&);


		/*
		 * Overloading + operator to perfomr set union operation.
		 */
		SimpleSet operator + (const SimpleSet&) const;


		/*
		 * Overloading - operator to perform set difference operation
		 */
		SimpleSet operator - (const SimpleSet&) const;


		/*
		 * Overloading * operator to perform set intersection operation.
		 */
		SimpleSet operator * (const SimpleSet&) const;

		
		/*
		 * Extracts an element from the input stream and inserts the element
		 * into the set only if there is no other element in the set with 
		 * same value. If an element with the same value already exists
		 * returns from the function without insering the element.
		 * If the set already contains the maximum number of elements, this 
		 * function should through an exception.
		 */
		friend std::istream& operator >> (std::istream&, SimpleSet&) throw (std::string);



		/*
		 * Inserts all elements of the set into the output stream.
		 * Separate the elements by a space during this insertion.
		 */
		friend std::ostream& operator << (std::ostream&, const SimpleSet&);
};


#endif
