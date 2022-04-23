/**
 * @file: fileutility.cpp
 * @author: your name goes here
 * Student Number: Your student number goes here
 */
 
#include "fileutility.h"
#include <fstream>

/**
 * Loads data from a file referred by parameter 'filename' into 
 * a dynamic array pointed by the parameter 'darray'.
 */
//Open the file in read only mode
//Read each data item from the file and add the data item into the dynamic array 
//calling 'input>>darray' overloaded operator from 'dynamicarray.cpp'
//assuming 'input' refers to your input file stream.
void  load(std::string filename, DynamicArray& darray){
	std::ifstream file;
	
	//open file
	file.open(filename.c_str());
	if(!file.is_open())
		return ;
	
	//loop to read elements from file to darray
	while(!file.eof())
		file>>darray;

	file.close();
}

/**
 * Saves the data from a dynamic array into a file.
 */
//Open the file in write only mode.
//Save the data items from the dynamic array into the file calling
//'darray>>output', overloaded operator function from 'dynamicarray.cpp',
//assuming 'output' refers to  your output file stream..
void save(const DynamicArray& darray, std::string filename){
	std::ofstream file;
	
	//open file
	file.open(filename.c_str());
	if(!file.is_open())
		return ;
	
	//write elements in the darray to the file
	file<<darray;
	
	file.close();	
}
