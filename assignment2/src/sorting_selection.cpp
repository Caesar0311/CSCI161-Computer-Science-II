/**
 * @file: sorting_selection.cpp
 *
 * @author: Your Name goes here
 * Student Number: Your Student Number goes here
 *
 */

void sort(int* array, const int size){
	//loop to select sort
	for(int i=0;i<size-1;i++){
		
		int minIdx = i;
		//loop to get the minimum element index
		for(int j=i+1;j<size;j++){
			if(array[j]<array[minIdx])
				minIdx = j;			
		}
		
		if(minIdx != i){
			//swap with element in i
			int tmp = array[i];
			array[i] = array[minIdx];
			array[minIdx] = tmp;
		}
	}	
}
