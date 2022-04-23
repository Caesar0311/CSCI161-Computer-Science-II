#include "fileutility.h"
#include <fstream>
#include <iostream>

void load(string filename, int *&array, int &size) {
    ifstream infile(filename);
    if(!infile) {
        cout <<"Failed to open input data file: " << filename << endl;
        exit(1);
    }
    infile >> size;
    array = new int[size];
    for(int i = 0 ; i< size;i++) {
        infile >> array[i];
    }
    infile.close();
}

void save(int *data, int size, string filename) {
    ofstream outfile(filename);
    if(!outfile) {
        cout <<"Failed to open input data file: " << filename << endl;
        exit(1);
    }
    outfile << size << endl;
    for(int i = 0 ; i < size ;i++) {
        outfile<< data[i] << endl;
    }
    outfile.close();
}
