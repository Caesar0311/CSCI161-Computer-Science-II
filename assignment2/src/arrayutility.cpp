/**
 * @file: arrayutility.cpp
 *
 * @author: Your Name goes here
 * Student Number: Your Student Number goes here
 *
 */

#include "sorting.h"
#include <iostream>

using namespace std;

void show(const int *array, int size){
	//loop to output the elements in array
	for(int i=0;i<size;i++)
		cout<<array[i]<<" ";
	
	cout<<endl;
}

void sortOriginal(int *array, int size){
	//call sort function
	sort(array,size);
}

int* sortCopy(const int *array, int size){
	int *array1=new int[size];
	
	//loop to copy elements in array to array1
	for(int i=0;i<size;i++)
		array1[i]=array[i];
	
	//sort array1
	sort(array1,size);
	
	return array1;
}
