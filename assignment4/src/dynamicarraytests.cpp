/**
 * @file: dynamicarraytests.cpp
 * @auhor: Humayun Kabir
 */

#include <iostream>
#include <fstream>
#include <string>
#include "dynamicarray.h"
#include "fileutility.h"
#include "tests.h"


using namespace std;
 

DynamicArray createDynamicArray() {
	DynamicArray theArray(5);
	for(int i=1; i<=5; i++) {
		theArray.insert(i*5);
	}

	return theArray;
}

void test(int argc, char** argv) {

	if(argc < 3) {
		cout<<"Usage: "<<argv[0]<<" <input-file> <output-file>"<<endl;
	       	exit(-1);	
	}

	string inputFile(argv[1]);
	string outputFile(argv[2]);

	/*
	 * Testing default constructor
	 */
	cout<<"Testing default constructor"<<endl;
	DynamicArray defaultArray;
	for(int i=1; i<=DEFAULT_CAPACITY; i++) {
		defaultArray.insert(i);
		cout<<"Capacity: "<< defaultArray.getCapacity() << ", size: " << defaultArray.getSize() << endl;
	}
	/**
	 * Testing << operator (overloaed)
	 */
	cout<<defaultArray<<endl;
	
	/**
	 * Testing insert() after dynamic array is full, i.e., exceeds the capacity
	 */
	int element = 300;
	cout<<"Testing insert() function after the array is full"<<endl;
	defaultArray.insert(element);
	cout<<defaultArray<<endl;


	/*
	 * Testing search() function
	 */
	cout<<"Testing search() function"<<endl;
	cout<<"Index of "<<element<<"  in the dynamic array is: "<< defaultArray.search(element) <<endl;
	element *= 2;
	cout<<"Index of "<<element<<"  in the dynamic array is: "<< defaultArray.search(element) <<endl;



	/*
	 * Testing regular constructor
	 */
	cout<<"Testing regular constrcutor"<<endl;
	DynamicArray firstArray(5);
	for (int i=1; i<=5; i++) {
		firstArray.insert(i*10);
		cout<<"Capacity: "<< firstArray.getCapacity() << ", size: " << firstArray.getSize() << endl;
	}
	cout<<firstArray<<endl;


	/*
	 * Testing copy constructor
	 */
	cout<<"Testing copy constructor"<<endl;
	DynamicArray secondArray(firstArray);
	cout<<secondArray<<endl;

	/*
	 * Testing copy assignment
	 */
	cout<<"Testing copy assignment"<<endl;
	DynamicArray thirdArray;
	thirdArray = firstArray;
	cout<<thirdArray<<endl;

	/*
	 * Testing move constructor
	 */
	cout<<"Testing move constructor"<<endl;
	DynamicArray fourthArray = createDynamicArray();
	cout<<fourthArray<<endl;

	/*
	 * Testing move assignment
	 */
	cout<<"Testing move assignment"<<endl;
	DynamicArray fifthArray;
	fifthArray = createDynamicArray();
	cout<<fifthArray<<endl;

	/*
	 * Testing erase function
	 */
	int eraseMe = 15;
	cout<<"Testing erase() function"<<endl;
	cout<<"Capacity: "<< fifthArray.getCapacity() << ", size: " << fifthArray.getSize()<<" before erasing "<<eraseMe<< endl;
	cout<<fifthArray<<endl;
	fifthArray.erase(eraseMe);
	cout<<"Capacity: "<< fifthArray.getCapacity() << ", size: " << fifthArray.getSize() <<" after erasing "<<eraseMe<< endl;
	cout<<fifthArray<<endl;

	/*
	 * Testing erase of a non-existing element
	 */
	cout<<"Testing erase of a non-existing element " <<eraseMe<<endl;
	fifthArray.erase(eraseMe);
	cout<<"Capacity: "<< fifthArray.getCapacity() << ", size: " << fifthArray.getSize()<< " after erasing a non-exisitng element "<<eraseMe<< endl;
	cout<<fifthArray<<endl;

	/*
	 * Testing clear function
	 */
	cout<<"Testing clear function"<<endl;
	fifthArray.clear();
	cout<<"Capacity: "<< fifthArray.getCapacity() << ", size: " << fifthArray.getSize() << endl;
	cout<<fifthArray<<endl;

	/*
	 * Testing post increment operator
	 */
	cout<<"Testing post increment operator"<<endl;
	firstArray++;
	cout<<firstArray<<endl;

	/*
	 * Testing pre increment operator
	 */
	cout<<"Tesitng pre increment operator"<<endl;
	++firstArray;
	cout<<firstArray<<endl;

	/*
	 * Testing post decrement operator
	 */
	cout<<"Testing post decrement operator"<<endl;
	firstArray--;
	cout<<firstArray<<endl;

	/*
	 * Testing pre decrement operator
	 */
	cout<<"Testing pre decrement operator"<<endl;
	--firstArray;
	cout<<firstArray<<endl;

	/*
	 * Testing array index [i] operator
	 */
	cout<<"Testing array index operator"<<endl;
	cout<<"array[3]: "<<firstArray[3]<<endl;
	cout<<"array[-1]: "<<firstArray[-1]<<endl;
	cout<<"array[5]: "<<firstArray[5]<<endl;

	/*
	 * Testing + operator
	 */
	cout<<"Testing + operator"<<endl;
	DynamicArray sixthArray = firstArray + secondArray;
	cout<<sixthArray<<endl;

	/*
	 * Testing - operator
	 */
	cout<<"Testing - operator"<<endl;
	DynamicArray seventhArray = firstArray - secondArray;
	cout<<seventhArray<<endl;

	/*
	 * Testing * operator
	 */
	cout<<"Testing * operator"<<endl;
	DynamicArray eighthArray = firstArray *  secondArray;
	cout<<eighthArray<<endl;

	/*
	 * Testing >> operator
	 */
	cout<<"Testing >> operator"<<endl;
	ifstream in(inputFile);
	if(!in) {
		cout<<"Cannot open input file: "<<inputFile<<endl;
		return;
	}

	DynamicArray ninethArray(5);

	for(int i=0; i<5; i++) {
		in>>ninethArray;
	}

	cout<<ninethArray<<endl;


	/*
	 * Testing to insert more element into the array when it is full
	 */
	cout<<"Testing to insert more element into the array when it is full"<<endl;
	in>>ninethArray;

	in.close();

	/**
	 * Testing load() function
	 */
	cout<<"Testing load() function"<<endl;
	DynamicArray tenthArray(10);
	load(inputFile, tenthArray);
	cout<<tenthArray<<endl;

	/**
	 * Testing save() function
	 */
	cout<<"Testing save() function"<<endl;
	save(tenthArray, outputFile);

}
