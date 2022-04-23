/**
 * @file: sorting_merge.cpp
 *
 * @author: Your Name goes here
 * Student Number: Your Student Number goes here
 *
 */

void mergeArray(int array[],int start,int middle,int end,int tmpArr[]){     
	//left part
	int i = start;
	int m = middle;
	
	//right part
	int j = middle+1;
	int n = end;
	
	int k = 0; 
	//loop to compare and copy to template array
	while(i<=m && j<=n){
		
		//compare
		if(array[i] <= array[j]){
			tmpArr[k] = array[i];
			k++;
			i++;
		}else{
			tmpArr[k] = array[j];
			k++;
			j++;
		}
	}
	
	//copy the remain elements in left part
	while(i<=m){
		tmpArr[k] = array[i];
		k++;
		i++;
	}     
	//copy the remain elements in right part
	while(j<=n){
		tmpArr[k] = array[j];
		k++;
		j++; 
	}

	//loop to copy template array to current array
	for(int x=0;x<k;x++)
		array[start + x] = tmpArr[x];	
}

void mergeSort(int array[],int start,int end,int tmpArr[]){
	if(start < end){
		int middle = (start + end)/2;
		
		//left part sort
		mergeSort(array,start,middle,tmpArr);
		//right part sort
		mergeSort(array,middle+1,end,tmpArr);
		
		//merge the left part and right part 
		mergeArray(array,start,middle,end,tmpArr);
	}
}

void sort(int* array, const int size){
	int *tmpArr=new int[size];
	
	//merge sort
	mergeSort(array,0,size-1,tmpArr);
	
	delete tmpArr;
}
