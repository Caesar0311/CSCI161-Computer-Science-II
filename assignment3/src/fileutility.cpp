#include "fileutility.h"
#include <fstream>

/**
 * @file: fileutility.cpp
 * @author: Your name goes here
 * Student Number: Your student number goes here
 */
 
/**
 * Loads data from a file referred by parameter 'filename'  into a linked list pointed by the parameter 'list'.
 * Adds the data at the front of the linked list if 'isAtFront' is true.
 * Adds the data at the end of the linked list otherwise.
 */
void load(std::string filename, ListNode*& list, bool isAtFront){
	std::ifstream file;
	
	//open file
	file.open(filename.c_str());
	if(!file.is_open())
		return ;
	
	int data;
	ListNode *node,*tail;
	
	node=list;
	if(node!=NULL){
		//get tail node of the linked list
		while(node->next!=NULL)
			node=node->next;
		
		tail=node;
	}
	
	//loop to read data from file
	while(file>>data){
		node=new ListNode();
		node->data=data;
		node->next=NULL;
		
		if(list==NULL){
			list=node;			
			tail=node;
			continue;
		}
		
		if(isAtFront){
			//insert to front
			node->next=list;
			list=node;
		}else{
			//insert to tail
			tail->next=node;
			tail=node;
		}		
	}	
	
	file.close();
}

/**
 * Saves the data from a list into a file.
 */
void save(ListNode *list, std::string filename){
	std::ofstream file;
	
	//open file
	file.open(filename.c_str());
	if(!file.is_open())
		return ;

	ListNode *node=list;
	
	if(node!=NULL){
		//write the front node to file
		file<<node->data;
		node=node->next;
	}
	
	//loop to write the remain nodes to file
	while(node!=NULL){
		file<<" "<<node->data;
		
		node=node->next;
	}	
	file<<std::endl;
	
	file.close();	
}
