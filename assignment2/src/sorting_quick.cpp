/**
 * @file: sorting_quick.cpp
 *
 * @author: Your Name goes here
 * Student Number: Your Student Number goes here
 *
 */

void quickSort(int array[],int start,int end){
	if(start>=end)
		return;
	
	int i = start; 
	int j = end; 
	int key = array[start];//get the first element
	
	//loop to compare
	while(i<j){
		
		//loop to find the first element smaller than key from right to left
		while(i<j && array[j]>=key)
			j--;
		
		if(i<j){
			array[i] = array[j];
			i++;
		}
		
		//loop to find the first element smaller than key from left to right
		while(i<j && array[i]<key)
			i++;

		if(i<j){
			array[j] = array[i];
			j--;
		}
	}
	//set the key to partify the elements
	array[i] = key;
	
	quickSort(array, start, i-1);
	quickSort(array, i+1, end);
}

void sort(int* array, const int size){
	quickSort(array,0,size-1);
}
