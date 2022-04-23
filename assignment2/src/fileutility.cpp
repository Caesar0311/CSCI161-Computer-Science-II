/**
 * @file: fileutility.cpp
 *
 * @author: Your Name goes here
 * Student Number: Your Student Number goes here
 *
 */

#include <fstream>

using namespace std;

void load (string filename, int*& array, int &size){
	ifstream file(filename.c_str());
	//read size
	file>>size;
	
	array=new int[size];
	
	//loop to read to array
	for(int i=0;i<size;i++)
		file>>array[i];
	
	file.close();
}

void save(int *data, int size, string filename){
	ofstream ofile(filename.c_str());
	//write size
	ofile<<size<<endl;
	
	//loop to write data to file
	for(int i=0;i<size;i++)
		ofile<<data[i]<<endl;
	
	ofile.close();	
}
