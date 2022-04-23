#include <iostream>
#include <string>
#include "fileutility.h"
#include "arrayutility.h"
#include <cstdlib>

using namespace std;

/** 
 * Tests all the functions in 'fileutility.cpp' and 'arrayutility.cpp'.
 * Accepts the paths of the input and output files as a command line argument.
 */
int main(int argc, char** argv) {

	int *originalArray = NULL;
	int size;

	if(argc<3) {
		cout<<"Usage: bin/assignment1 <input-file> <output-file>"<<endl;
		exit(1);
	}
		
	string inputfile(argv[1]);
	string outputfile(argv[2]);

	cout<<"Loading array size and array elements from the input file: "<<inputfile<<endl;
	load(inputfile, originalArray,  size);

	cout<<"Array size is: "<<size<<endl;

	cout<<"Array elements are below:"<<endl; 
	show(originalArray, size);


	int *sortedCopy = sortCopy(originalArray, size);
	
	cout<<"Sorted copy of the array:"<<endl;
	show(sortedCopy, size);
	
	cout<<"Unsorted original array: "<<endl;
	show(originalArray, size);
	
	sortOriginal(originalArray, size);

	cout<<"Sorted original array: "<<endl;
	show(originalArray, size);

	cout<<"Saving sorted original array into the output file: "<<outputfile<<endl;
	save(originalArray, size, outputfile);


    if(sortedCopy !=NULL) {
		cout<<"Freeing memory from the array copy"<<endl;
		delete [] sortedCopy;
	}

	if(originalArray != NULL){
		cout<<"Freeing memory from the original array"<<endl;
		delete [] originalArray;
	}

	return 0;
}
