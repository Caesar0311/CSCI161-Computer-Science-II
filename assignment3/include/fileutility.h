#ifndef __FILEUTILITY_HEADER__
#define __FILEUTILITY_HEADER_

#include <string>
#include "listnode.h"


/**
 * Loads data from a file referred by parameter 'filename'  into a linked list pointed by the parameter 'list'.
 * Adds the data at the front of the linked list if 'isAtFront' is true.
 * Adds the data at the end of the linked list otherwise.
 */
void  load(std::string filename, ListNode*& list, bool isAtFront);
//Open the file in read only mode
//Read each data item from the file and insert the data item at the end of the list calling 'insertAtEnd()'
//functuon from 'linkedlist.cpp' if 'isAtFront' is false. Insert the data item at the front of the list calling
//'insertAtFront() function from 'linkedlist.cpp' if 'isAtFront' is true. 

/**
 * Saves the data from a list into a file.
 */
void save(ListNode *list, std::string filename);
//Open the file in write only mode.
//Go through the list and write each data item from the list into the file separated by a space.


#endif
