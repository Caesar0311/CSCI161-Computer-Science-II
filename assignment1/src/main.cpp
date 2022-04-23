#include <iostream>
#include "fileutility.h"
#include "arrayutility.h"


int main(int argc, char** args) {
    if(argc != 3) {
        cout << "Usage: bin/assignment1 <input-file> <output-file>\n";
        return 0;
    }
    char* inputFile = args[1];
    char* outputFile = args[2];
    int *arr = nullptr;
    int size = 0;
    load(inputFile, arr, size);
    cout << "Array size: " << size << endl;
    cout << "Array elements: \n";
    show(arr,size);
    int min = 0,max = 0;
    float avg = 0.0;
    getStatistics(arr,size,min,max,avg);
    cout << "Minimum: " << min << ", ";
    cout << "Maximum: " << max << ", ";
    cout << "Average: " << avg << endl;
    int* sorted = sortCopy(arr, size);
    cout << "Sorted Copy of the array:\n";
    show(sorted,size);
    cout << "Original unsorted array:\n";
    show(arr,size);
    cout << "Original unsorted array:\n";
    show(sorted,size);
    save(sorted, size, outputFile);
    cout << "Saving sorted array into file: " << outputFile << endl;
    delete[] arr;
    delete[] sorted;
    return 0;
}