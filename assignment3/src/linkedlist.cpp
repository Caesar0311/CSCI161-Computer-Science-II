#include "linkedlist.h"
#include <iostream>

using namespace std;

/**
 * @file: linkedlist.cpp
 * @author: Your name goes here
 * Student Number: Your student number goes here
 */


/**
 * Shows all the data from a list pointed by the parameter 'list'.
 */

//Go through the list and display all the data elements space separated. 
void show(ListNode *list){	
	if(list==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	
	ListNode *node=list;
	//output the front node
	cout<<node->data;	
	node=node->next;
	
	//loop to output the remain nodes
	while(node!=NULL){
		cout<<" "<<node->data;
		
		node=node->next;
	}	
	cout<<endl;	
}

/**
 * Inserts a data element at the front of the list.
 */
void insertAtFront(ListNode*& list, const int data){
	ListNode *node=new ListNode();
	node->data=data;
	
	//insert to front of the linked list
	node->next=list;
	list=node;
}

/**
 * Inserts a  data element at the end of the list.
 */
void insertAtEnd(ListNode*& list, const int data){
	ListNode *node,*tail;
	
	node=list;
	if(node!=NULL){		
		//get the tail node of the linked list
		while(node->next!=NULL)
			node=node->next;
		
		tail=node;		
	}
	
	node=new ListNode();
	node->data=data;
	node->next=NULL;
	
	//insert to the tail of the linked list
	if(list==NULL)
		list=node;
	else{
		tail->next=node;
		tail=node;
	}	
}

/**
 * Inserts a data element into the list after another data element.
 * Returns 'true' if after found and insertion takes place.
 * Return 'false', otherwise.
 */
bool insertAfter(ListNode* list, const int data, const int after){
	ListNode *node=list;
	
	bool find=false;
	//loop to find the 'after'
	while(node!=NULL){
		if(node->data==after){
			ListNode *tmp=new ListNode();
			tmp->data=data;
			
			//insert tmp after the node
			tmp->next=node->next;			
			node->next=tmp;
			find=true;
			break;
		}
		
		node=node->next;
	}
	
	return find;
}

/**
 * Inserts a data element into the list before another data element.
 * Returns 'true' if before found and insertion happens.
 * Returns 'false' otherwise.
 */
bool insertBefore(ListNode*& list, const int data, const int before){
	ListNode *node=list;
	if(list!=NULL&&list->data==before){
		//insert data as front
		ListNode *tmp=new ListNode();
		tmp->data=data;
		
		tmp->next=list;
		list=tmp;		
		return true;
	}
	
	ListNode *last=list;
	bool find=false;
	//loop to find before in the linked list
	while(node!=NULL){
		if(node->data==before){
			ListNode *tmp=new ListNode();
			tmp->data=data;
			
			//insert tmp
			tmp->next=node;
			last->next=tmp;			
			find=true;
			break;
		}
		
		last=node;
		node=node->next;
	}
	
	return find;	
}

/**
 * Searches a data element in the list.
 * Returns the address of the first list node whose data value is equal to 'data' parameter.
 * Returns NULL, when no such list node exists.
 */
ListNode* search(ListNode *list, const int data){
	ListNode *node=list;
	
	//loop to find data in the linked list
	while(node!=NULL){
		if(node->data==data)
			break;
		
		node=node->next;
	}
	
	return node;
}

/**
 * Removes a list node from the front of the list.
 * Returns the data value of the removed list node.
 * Returns -1, when no list node has been removed.
 */
int removeFromFront(ListNode*& list){	
	int data=-1;
	
	if(list!=NULL){	
		ListNode *node=list;
		//remove from the front
		list=list->next;
		
		data=node->data;
		delete node;
	}
	
	return data;
}

/**
 * Removes a list node from the end of the list.
 * Returns the data value of the removed node.
 * Returns -1, when no list node has been removed.
 */
int removeFromEnd(ListNode*& list){	
	int data=-1;
	
	if(list!=NULL){	
		ListNode *node=list;
		ListNode *last=NULL;
		
		//loop to get the tail node
		while(node->next!=NULL){
			last=node;
			node=node->next;
		}
		
		data=node->data;
		
		//remove from end
		if(last==NULL)
			list=NULL;
		else
			last->next=NULL;
		
		delete node;
	}
	return data;
}

/**
 * Removes the first list node whose data value is equal to 'data' parameter.
 * Returns the data value of the removed node.
 * Returns -1, when no list node has been removed.
 */
int remove(ListNode*& list, int data){
	int d=-1;
	ListNode *node=list;
	ListNode *last=NULL;
	
	//loop to find data in the linked list
	while(node!=NULL){
		if(node->data==data){
			//remove node
			if(last==NULL)
				list=list->next;				
			else
				last->next=node->next;			
			delete node;
			
			d=data;
			break;
		}
		
		last=node;
		node=node->next;
	}
	
	return d;
}

/**
 * Remove all elements from the linked list.
 */
void removeAll(ListNode*& list){
	ListNode *node=list;
	ListNode *last=NULL;
	
	//loop to remove all nodes
	while(node!=NULL){
		last=node;
		
		node=node->next;
		delete last;
	}
	
	list=NULL;
}

