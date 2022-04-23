/**
 * @file: main.cpp
 * @author: Humayun Kabir
 * Professor, CSCI, VIU
 */

#include <iostream>
#include "listnode.h"
#include "fileutility.h"
#include "linkedlist.h"

using namespace std;

int main(int argc, char** argv) {

	if(argc<3) {
		/*
		 * Input and output file paths missing
		 * Show, error message and return from the function.
		 */
		cerr<<"Usage: lab3 <input-file-path> <output-file-path>"<<endl;
		return -1;
	}

	string inputfile(argv[1]);
	string outputfile(argv[2]);

	/*
	 * Initialize and empty list
	 */
	cout<<"Initilized an empty list"<<endl;
	ListNode* list = NULL;

	/*
	 * Testing removal from  the front of an empty list
	 */
	cout<<"Testing removal from the front of an empty list"<<endl;
	int removedData = removeFromFront(list);
	
	if(removedData == -1) {
		cout<<"Nothing has been removed, the list is empty"<<endl;
	}
	else {
		cout<<"Removed "<<removedData<<" from the front of the list. Below are the rest of the list elements"<<endl;
		show(list);
	}
	
	/*
	 * Testing removal from the end of an empty list.
	 */
	cout<<"Testing removal from the end of an empty list"<<endl;
       	removedData = removeFromEnd(list);
	
	if(removedData == -1) {
		cout<<"Nothing has been removed, the list is empty"<<endl;
	}
	else {
		cout<<"Removed "<<removedData<<" from the end of the list. Below are the rest of the list elements"<<endl;
		show(list);
	}
	
	/*
	 * Testing loading at the front of the list from the file
	 */ 
	cout<<"Testing load elements at the end of the list"<<endl;
	load(inputfile, list, false);
	cout<<"List elements after loading elements from input file: "<<inputfile<<endl;
	show(list);
	
	/*
	 * Testing remove from the front on the non-empty list
	 */
	cout<<"Testing removal from the front from a non-empty list"<<endl;
       	removedData = removeFromFront(list);
	
	if(removedData == -1) {
		cout<<"Nothing has been removed, the list is empty"<<endl;
	}
	else {
		cout<<"Removed "<<removedData<<" from the front of the list. Below are the rest of the list elements"<<endl;
		show(list);
	}
	
	/*
	 * Testing removal from the end of a non-empty list
	 */
	cout<<"Testing removal from the end of a non-empty list"<<endl;
       	removedData = removeFromEnd(list);
	
	if(removedData == -1) {
		cout<<"Nothing has been removed, the list is empty"<<endl;
	}
	else {
		cout<<"Removed "<<removedData<<" from the end of the list. Below are the rest of list elements"<<endl;
		show(list);
	}

	/*
	 * Testing search a non-existing element
	 */ 
	cout<<"Testing search of a non-existing element"<<endl;
	int data = 555;

	ListNode* resultNode = search(list, data);
	if(resultNode != NULL && resultNode->data == data) {
		cout<<"Found "<<resultNode->data<<" in the list"<<endl;
	}
	else {
		cout<<"Didn't find "<<data<<" in the list"<<endl;
	}

	/*
	 * Testing removal of a non-existing element
	 */
	cout<<"Testing removal of a non-existing element"<<endl;
	removedData = remove(list, data);
	if(removedData == data) {
		cout<<"List elements after removing "<<removedData<<" from the list"<<endl;
		show(list);
	}
	else {
		cout<<"Failed to remove "<<data<<" from the list"<<endl;
	}

	/*
	 * Testing search an existing element
	 */
	cout<<"Testing search of an existing element"<<endl;
	data = 55;

	resultNode = search(list, data);
	if(resultNode != NULL && resultNode->data == data) {
		cout<<"Found "<<resultNode->data<<" in the list"<<endl;
	}
	else {
		cout<<"Didn't find "<<data<<" in the list"<<endl;
	}
 
	/*
	 * Testing removal of an  existing element
	 */	
	cout<<"Testing removal of an existing element"<<endl;
	removedData = remove(list, data);
	if(removedData == data) {
		cout<<"List elements after removing "<<removedData<<" from the list"<<endl;
		show(list);
	}
	else {
		cout<<"Failed to remove "<<data<<" from the list"<<endl;
	}

	/*
	 * Testing insertion before a non-existing element
	 */
	cout<<"Testing insertion before a non-existing element"<<endl;
	int before = 600;
	if (insertBefore(list, removedData, before)) {
		cout<<"List elements after inserting "<<removedData<<" before "<<before<<endl;
		show(list);
	}
	else {
		cout<<"Failed to insert "<<removedData<<" before "<<before<<endl;
	}
	
	/*
	 * Testing insertion before an existing element
	 */
	cout<<"Testing insertion before an existing element"<<endl;
	before = 60;
	if (insertBefore(list, removedData, before)) {
		cout<<"List elements after inserting "<<removedData<<" before "<<before<<endl;
		show(list);
	}
	else {
		cout<<"Failed to insert "<<removedData<<" before "<<before<<endl;
	}

	/*
	 * Testing removal of an inserted element
	 */
	cout<<"Testing removal of an inserted element"<<endl;
	removedData = remove(list, data);
	
	if(removedData == data) {
		cout<<"List elements after removing "<<removedData<<" from the list"<<endl;
		show(list);
	}
	else {
		cout<<"Failed to remove "<<data<<" from the list"<<endl;
	}

	/*
	 * Testing insertion after a non-existing data element
	 */
	cout<<"Testing insertion after a non-existing element"<<endl;
	int after = 500;
	if (insertAfter(list, removedData, after)) {
		cout<<"List elements after inserting "<<removedData<<" after "<<after<<endl;
		show(list);
	}
	else {
		cout<<"Failed to insert "<<removedData<<" after "<<after<<endl;
	}

	/*
	 * Testing insertion after an existing data element
	 */
	cout<<"Testing insertion after an exisitng element"<<endl;
	after = 50;
	if (insertAfter(list, removedData, after)) {
		cout<<"List elements after inserting "<<removedData<<" after "<<after<<endl;
		show(list);
	}
	else {
		cout<<"Failed to insert "<<removedData<<" after "<<after<<endl;
	}

	/*
	 * Testing removal of all elements
	 */
	cout<<"Removing all elements from the list...."<<endl;
	removeAll(list);
	cout<<"List after removing all elements"<<endl; 
	show(list);
	

	/*
	 * Testing data elements at the front of the list from file
	 */
	cout<<"Loading list elements at the front of the list from input file: "<<inputfile<<" ......"<<endl;
	load(inputfile, list, true);
	cout<<"List after loading"<<endl;
	show(list);

	/*
	 * Testing save list into an output file
	 */
	cout<<"Saving list into output file: "<<outputfile<<" ....."<<endl;
	save(list, outputfile);

	/*
	 * Removing all elements from the list to release the memory
	 */
	cout<<"Removing all elements from the list...."<<endl;
	removeAll(list);
	
	return 0;
}
