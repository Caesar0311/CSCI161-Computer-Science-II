/**
 * @file: sorting_bubble.cpp
 *
 * @author: Your Name goes here
 * Student Number: Your Student Number goes here
 *
 */

void sort(int* array, const int size){
	//loop to bubble sort
	for(int i=0;i<size-1;i++){
		
		for(int j=size-1;j>i;j--){
			//compare and swap the value
			if(array[j]<array[j-1]){
				int tmp=array[j];
				array[j]=array[j-1];
				array[j-1]=tmp;
             }
         }
     }	
}
