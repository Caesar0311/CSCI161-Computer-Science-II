#ifndef __FILEUTILITY_HEADER__
#define __FILEUTILITY_HEADER__



#include "dynamicarray.h"


/**
 * Loads data from a file referred by parameter 'filename' into 
 * a dynamic array pointed by the parameter 'darray'.
 */
void  load(std::string filename, DynamicArray& darray);
//Open the file in read only mode
//Read each data item from the file and add the data item into the dynamic array 
//calling 'input>>darray' overloaded operator from 'dynamicarray.cpp'
//assuming 'input' refers to your input file stream.



/**
 * Saves the data from a dynamic array into a file.
 */
void save(const DynamicArray& darray, std::string filename);
//Open the file in write only mode.
//Save the data items from the dynamic array into the file calling
//'darray>>output', overloaded operator function from 'dynamicarray.cpp',
//assuming 'output' refers to  your output file stream..


#endif
