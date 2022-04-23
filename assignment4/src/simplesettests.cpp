/**
 * @file: simplesettests.cpp
 * @author: Humayun Kabir
 */


#include <iostream>
#include <fstream>
#include <string>
#include "fileutility.h"
#include "simpleset.h"
#include "tests.h"


using namespace std;


SimpleSet createSimpleSet() {
	SimpleSet theSet(5);
	for(int i=1; i<=5; i++) {
		theSet.insert(i*10);
	}

	return theSet;
}

void test(int argc, char** argv) {

	if(argc<4) {
		cout<<"Usage: "<<argv[0]<<" <prime-input-file> <fibonacci-input-file> <output-file>"<<endl;
		exit(-1);
	}
	
	string primeInputFile(argv[1]);
	string fibonacciInputFile(argv[2]);
	string outputFile(argv[3]);

	/*
	 * Testing Regular constructor
	 */
	cout<<"Testing regular constructor and insert function....."<<endl;
	SimpleSet firstSet(5);

	cout<<"Capacity: "<< firstSet.getCapacity() << ", size: " << firstSet.getSize() << endl;
	
	int element = 0;
	for(int i=1; i<6; i++) {
		element = i*10;
		firstSet.insert(element);
		cout<<"............. simple set size: "<<firstSet.getSize()<<", after an inserting: " << element << endl;
	}

	/*
	 * Testing insertion << operator
	 */
	cout<<"Testing insertion << operator"<<endl;
	cout<<firstSet<<endl;
	
		
	cout<<"Testing insertion of a duplicate element: "<<element<<" into a simple set"<<endl;
	firstSet.insert(element);
	cout<<firstSet<<endl;

	/*
	 * Testing inseration of a new element
	 */
	element = 60;
	cout<<"Testing inserting another element "<<element<<" into simple set  when it is full"<<endl;
	firstSet.insert(60);
	cout<<firstSet<<endl;

	/*
	 * Testing Copy constructor
	 */
	cout<<"Testing copy constructor............................"<<endl;
	SimpleSet secondSet(firstSet);
	cout<<secondSet<<endl;

	/*
	 * Testing copy assignment
	 */
	SimpleSet thirdSet;
	cout<<"Testing copy assignment..........................."<<endl;
	thirdSet = firstSet;
	cout<<thirdSet<<endl;

	/*
	 * Testing Move constructor
	 */
	cout<<"Testing move constructor........................."<<endl;
	SimpleSet fourthSet = createSimpleSet();
	cout<<fourthSet<<endl;

	/*
	 * Testing Move assignment
	 */
	SimpleSet fifthSet;
	cout<<"Testing move assignment........................."<<endl;
	fifthSet = createSimpleSet();
	cout<<"Capacity: "<< fifthSet.getCapacity() << ", size: " << fifthSet.getSize() << endl;
	cout<<fifthSet<<endl;	

	/*
	 * Testing erase function
	 */
	element = 30;
	cout<<"Testing erase function..........................."<<endl;
	fifthSet.erase(element);
	cout<<"Size " << fifthSet.getSize()<<" after erasing "<<element<< endl;
	cout<<fifthSet<<endl;
	cout<<"Testing erasing a non-existing element "<<element<<endl;
	fifthSet.erase(element);
	cout<<"Size: " << fifthSet.getSize()<<" after erasing a non-exisitng element "<< element << endl;
	cout<<fifthSet<<endl;

	/*
	 * Testing clear function
	 */
	cout<<"Testing clear function.........................."<<endl;
	fifthSet.clear();
	cout<<"Capacity: "<< fifthSet.getCapacity() << ", size: " << fifthSet.getSize() << endl;
	cout<<fifthSet<<endl;

	/*
	 * Testing extraction >> operator
	 */
	cout<<"Testing extraction >> operator ................................"<<endl;
	ifstream primeStream(primeInputFile);
	SimpleSet primeSet(10);
	if(!primeStream) {
		cout<<"Caanot open prime input file!"<<endl;
	}
	else {
		while(primeStream>>primeSet && !primeStream.eof());
		primeStream.close();
	}
	
	cout<<".......prime set: ";
	cout<<primeSet<<endl;
	
	ifstream fibonacciStream(fibonacciInputFile);
	SimpleSet fibonacciSet(10);
	if(!fibonacciStream) {
		cout<<"Connot open fibonacci input file"<<endl;
	}
	else {
		while(fibonacciStream>>fibonacciSet && ! fibonacciStream.eof());
		fibonacciStream.close();
	}

	cout<<"......fobonacci set: ";
	cout<<fibonacciSet<<endl;


	/*
	 * Testing set union operator
	 */
	cout<<"Testing set union using + operator......................................."<<endl;
	SimpleSet primeUnionFibo = primeSet + fibonacciSet;
	cout<<"Prime UNION Fibonacci: "<<primeUnionFibo<<endl;


	/*
	 * Testing set difference operator
	 */
	cout<<"Testing set difference using - operator......................................."<<endl;
	SimpleSet primeDiffFibo = primeSet - fibonacciSet;
	cout<<"Prime DIFERENCE Fibonacci: "<<primeDiffFibo<<endl;

	/*
	 * Testing set intersection operator
	 */
	cout<<"Testing set intersection using * operator......................................."<<endl;
	SimpleSet primeInterFibo = primeSet * fibonacciSet;
	cout<<"Prime INTERSECTION Fibonacci: "<<primeInterFibo<<endl;

	/*
	 * Testing index operator
	 */
	cout<<"Testing index [] operator ....................................................."<<endl;
	cout<<"primeSet[5]: "<<primeSet[5]<<endl;
	cout<<"primeSet[11]: "<<primeSet[11]<<endl;

	/*
	 * Testing post increment operator
	 */
	cout<<"Testing post increment operator.............................................."<<endl;
	cout<<"... prime set before increment "<<primeSet<<endl;
	primeSet++;
	cout<<"... prime set after increment "<<primeSet<<endl;

	/*
	 * Testing pre increment operator
	 */
	cout<<"Testing pre increment operator.............................................."<<endl;
	cout<<"... prime set before increment "<<primeSet<<endl;
	++primeSet;
	cout<<"... prime set after increment "<<primeSet<<endl;

	/*
	 * Testing post decrement operator
	 */
	cout<<"Testing post deccrement operator.............................................."<<endl;
	cout<<"... prime set before deccrement "<<primeSet<<endl;
	primeSet--;
	cout<<"... prime set after deccrement "<<primeSet<<endl;

	/*
	 * Testing pre decrement operator
	 */
	cout<<"Testing pre deccrement operator.............................................."<<endl;
	cout<<"... prime set before deccrement "<<primeSet<<endl;
	--primeSet;
	cout<<"... prime set after deccrement "<<primeSet<<endl;

	/*
	 * Testing load() function
	 */
	cout<<"Testing load() function"<<endl;
	SimpleSet secondPrimeSet;
	load(primeInputFile, secondPrimeSet);
	cout<<secondPrimeSet<<endl;

	/*
	 * Testing save() function
	 */
	cout<<"Tesitng save() function"<<endl;
	save(secondPrimeSet, outputFile);


}
