/**
 * @file: sorting_insertion.cpp
 *
 * @author: Your Name goes here
 * Student Number: Your Student Number goes here
 *
 */

void sort(int* array, const int size){
	//loop to insert sort
	for(int i=0;i<size-1;i++){
		
		//loop to swap value until inserted
		for(int j=i+1;j>0;j--){
			if(array[j] < array[j-1]){
				int tmp = array[j-1];
				array[j-1] = array[j];
				array[j] = tmp;
			}else
				break;
			
		}
	}	
}
