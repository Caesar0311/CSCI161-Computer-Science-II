#ifndef __LINKEDLIST_HEADER__
#define __LINKEDLIST_HEADER__

#include "listnode.h"


/**
 * Shows all the data from a list pointed by the parameter 'list'.
 */
void show(ListNode *list);
//Go through the list and display all the data elements space separated.



/**
 * Inserts a data element at the front of the list.
 */
void insertAtFront(ListNode*& list, const int data);



/**
 * Inserts a  data element at the end of the list.
 */
void insertAtEnd(ListNode*& list, const int data);



/**
 * Inserts a data element into the list after another data element.
 * Returns 'true' if after found and insertion takes place.
 * Return 'false', otherwise.
 */
bool insertAfter(ListNode* list, const int data, const int after);



/**
 * Inserts a data element into the list before another data element.
 * Returns 'true' if before found and insertion happens.
 * Returns 'false' otherwise.
 */
bool insertBefore(ListNode*& list, const int data, const int before);



/**
 * Searches a data element in the list.
 * Returns the address of the first list node whose data value is equal to 'data' parameter.
 * Returns NULL, when no such list node exists.
 */
ListNode* search(ListNode *list, const int data);



/**
 * Removes a list node from the front of the list.
 * Returns the data value of the removed list node.
 * Returns -1, when no list node has been removed.
 */
int removeFromFront(ListNode*& list);



/**
 * Removes a list node from the end of the list.
 * Returns the data value of the removed node.
 * Returns -1, when no list node has been removed.
 */
int removeFromEnd(ListNode*& list);



/**
 * Removes the first list node whose data value is equal to 'data' parameter.
 * Returns the data value of the removed node.
 * Returns -1, when no list node has been removed.
 */
int remove(ListNode*& list, int data);


/**
 * Remove all elements from the linked list.
 */
void removeAll(ListNode*& list);


#endif

