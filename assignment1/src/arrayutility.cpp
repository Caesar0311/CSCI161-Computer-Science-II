#include "arrayutility.h"
#include <iostream>

using namespace std;

void show(const int *array, int size) {
    cout << "[";
    for(int i = 0; i < size; i++) {
        cout << array[i];
        if(i < size-1) cout << ", ";
    }
    cout << "]" << endl;
}

void getStatistics(const int *array, int size, int &minRef, int &maxRef, float &avgRef) {
    if(size < 1) return;
    minRef = maxRef = array[0];
    float sum = array[0];
    for(int i =1 ; i < size; i++) {
        sum += array[i];
        if(array[i] < minRef) minRef = array[i];
        if(array[i] > maxRef) maxRef = array[i];
    }
    avgRef = sum / size;
}

void sortOriginal(int *array, int size) {
    for(int i = 0,temp; i < size-1; i++) {
        for(int j = 0; j < size-1-i;j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int *sortCopy(const int *array, int size) {
    int* result = new int[size];
    for(int i = 0; i  <size;i++) result[i]=array[i];
    sortOriginal(result,size);
    return result;
}
