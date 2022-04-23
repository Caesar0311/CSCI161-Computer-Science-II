#ifndef __FILEUTILITY_HEADER__
#define __FILEUTILITY_HEADER__

using namespace std;

/**
 * Loads data from a file and returns the pointer that points the data through 'array' reference of pointer parameter..
 * Returns the size of the data through 'size' reference parameter.
 * Accepts file path as the input parameter.
 */
void load (string filename, int*& array, int &size);
//Open the file specified by 'filename'in read only mode.
//The first number in the file represents the data size.
//The rest of the numbers in the file are data.
//The first number is not included in the data.
//Each line in the file has one number.
//Read the data size from the file and allocate memory dynamically based on the read size.
//Assign the address of the allocated memory to the passed 'array' reference of pointer parameter.
//Read all the data elements into the array one after another.
//Close the file when all data elements have been read and placed into the array.



/**
 * Saves the size and the data elements of an array into a file.
 * Accepts the data array, its size, and the output file path as the input parameters.
 */
void save(int *data, int size, string filename);
//Open the file in write only mode.
//Write the size of the array into the first line of the file.
//Write each element of the array one after another in separate lines.
//Close the file when all elements have written into it.

#endif
