/**
 * @file: main.cpp
 * @author: Humayun Kabir
 */


#include <iostream>
#include <string>
#include "keyvalue.h"
#include "collection.h"
#include "map.h"
#include "arraymap.cpp"
#include "linkedmap.cpp"

using namespace std;

int main() {

    /*
     * Data to test Map<string, string>
     */
    string countries[5] = {"United States of America", "United Kingdom", "Canada", "Australia", "Mexico"};
    string capitals[5] = {"Washington", "London", "Ottawa", "Canberra", "Mexico City"};

    string brazil("Brazil");
    string brazil_capital("Brasilia");

    /*
     * Data to test Map<int, string>
     */
    int month_numbers[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    string month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                              "October", "November", "December"};

    /*
     * Data to test Map<string, double>
     */
    string letter_grades[11] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
    double grade_points[11] = {4.33, 4.00, 3.67, 3.33, 3.00, 2.67, 2.33, 2.00, 1.67, 1.00, 0.00};


    /*
     * Testing ArrayMap<string, string> using Map<string, string> ADT reference
     */
    cout << "Testing ArrayMap<string, string> using Map<string, string> ADT reference." << endl;
    Map<string, string> *mapRef1 = new ArrayMap<string, string>(10);


    for (int i = 0; i < 5; i++) {
        mapRef1->put(countries[i], capitals[i]);
    }

    for (int i = 0; i < 5; i++) {
        cout << "The capital of " << countries[i] << " is " << mapRef1->get(countries[i]) << "." << endl;
    }

    cout << "Before adding " << brazil << " and its capital " << brazil_capital << " into the map" << endl;
    cout << "Contains Key: " << brazil << " : " << (mapRef1->containsKey(brazil) ? "true" : "false") << endl;
    cout << "Contains Value: " << brazil_capital << " : " << (mapRef1->containsValue(brazil_capital) ? "true" : "false")
         << endl;

    mapRef1->put(brazil, brazil_capital);
    cout << "Adding adding " << brazil << " and its capital " << brazil_capital << " into the map" << endl;

    cout << "Contains Key: " << brazil << " : " << (mapRef1->containsKey(brazil) ? "true" : "false") << endl;
    cout << "Contains Value: " << brazil_capital << " : " << (mapRef1->containsValue(brazil_capital) ? "true" : "false")
         << endl;

    mapRef1->remove(brazil);
    cout << "After removing " << brazil << " and its capital " << brazil_capital << " from the map" << endl;

    cout << "Contains Key: " << brazil << " : " << (mapRef1->containsKey(brazil) ? "true" : "false") << endl;
    cout << "Contains Value: " << brazil_capital << " : " << (mapRef1->containsValue(brazil_capital) ? "true" : "false")
         << endl;

    Collection<string> *keys = mapRef1->keys();
    int keySize = keys->getSize();
    cout << "Keys size: " << keySize << endl;
    cout << "Keys in the map are: " << endl;
    for (int i = 0; i < keySize - 1; i++) {
        cout << keys->get(i) << ", ";
    }
    cout << keys->get(keySize - 1) << endl;

    Collection<string> *values = mapRef1->values();
    int valueSize = values->getSize();
    cout << "Values size: " << valueSize << endl;
    cout << "Values in the map are: " << endl;
    for (int i = 0; i < valueSize - 1; i++) {
        cout << values->get(i) << ", ";
    }
    cout << values->get(valueSize - 1) << endl;

    delete keys;
    delete values;
    delete mapRef1;

	/*
	 * Testing LinkedMap<string, string>  using Map<string, string> ADT reference
	 */
	cout<<"Testing LinkedMap<string, string> using Map<string, string> ADT reference."<<endl;
	Map<string, string>* mapRef2 = new LinkedMap<string, string>();

	for(int i=0; i<5; i++) {
		mapRef2->put(countries[i], capitals[i]);
	}

	for (int i=0; i<5; i++) {
		cout<<"The capital of "<< countries[i]<<" is "<<mapRef2->get(countries[i])<<"."<<endl;
	}


	cout<<"Before adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2->containsValue(brazil_capital)? "true":"false")<<endl;

	mapRef2->put(brazil, brazil_capital);
	cout<<"Adding adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;

	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2->containsValue(brazil_capital)? "true": "false")<<endl;

	mapRef2->remove(brazil);
	cout<<"After removing "<<brazil<<" and its capital "<<brazil_capital<<" from the map"<<endl;

	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2->containsValue(brazil_capital)? "true": "false")<<endl;

	Collection<string>* linkedMapKeys = mapRef2->keys();
	int linkedMapKeySize = linkedMapKeys->getSize();
	cout<<"Keys size: "<<linkedMapKeySize<<endl;
	cout<<"Keys in the map are: "<<endl;
	for(int i=0; i<linkedMapKeySize-1; i++) {
		cout<<linkedMapKeys->get(i)<<", ";
	}
	cout<<linkedMapKeys->get(linkedMapKeySize-1)<<endl;

	Collection<string>* linkedMapValues = mapRef2->values();
	int linkedMapValueSize = linkedMapValues->getSize();
	cout<<"Values size: "<<linkedMapValueSize<<endl;
	cout<<"Values in the map are: "<<endl;
	for(int i=0; i<linkedMapValueSize-1; i++) {
		cout<<linkedMapValues->get(i)<<", ";
	}
	cout<<linkedMapValues->get(linkedMapValueSize-1)<<endl;

	delete linkedMapKeys;
	delete linkedMapValues;
	delete mapRef2;


	/*
	 * Testing ArrayMap<int, string> using Map<int, string> ADT reference
	 */
	cout<<"\nTesting ArrayMap<int, string> unsing Map<int, string> ADT refeerence"<<endl;
	Map<int, string>* mapRef3 = new ArrayMap<int, string>(12);

	for(int i = 0; i<12; i++){
	       mapRef3->put(month_numbers[i], month_names[i]);
	}
	for( int i=0; i<12; i++) {
		if(mapRef3->containsKey(month_numbers[i])){
			cout<<"<"<<month_numbers[i]<<":"<<mapRef3->get(month_numbers[i])<<"> ";
		}
	}
	cout<<endl;
	delete mapRef3;

	/*
	 * Testing LinkedMap<int, string> usning Map<int, string> ADT reference
	 */
	cout<<"\nTesting LinkedMap<int, string> using Map<int, string> ADT reference"<<endl;
	Map<int, string>* mapRef4 = new LinkedMap<int, string>();
	for(int i = 0; i<12; i++){
	       mapRef4->put(month_numbers[i], month_names[i]);
	}
	for( int i=0; i<12; i++) {
		if(mapRef4->containsKey(month_numbers[i])){
			cout<<"<"<<month_numbers[i]<<":"<<mapRef4->get(month_numbers[i])<<"> ";
		}
	}
	cout<<endl;
	delete mapRef4;


	/*
	 * Testing ArrayMap<string, double> using Map<string, double> ADT reference
	 */
	cout<<"\nTesting ArrayMap<string, double> using Map<string, double> ADT reference"<<endl;
	Map<string, double>* mapRef5 = new ArrayMap<string, double>(11);
	for(int i=0; i<11; i++) {
		mapRef5->put(letter_grades[i], grade_points[i]);
	}

	for(int i=0; i<11; i++) {
		if(mapRef5->containsKey(letter_grades[i])) {
			cout<<"<"<<letter_grades[i]<<":"<<mapRef5->get(letter_grades[i])<<"> ";
		}
	}
	cout<<endl;
	delete mapRef5;

	/*
	 * Testing LinkedMap<string, double> using Map<string, double> ADT reference
	 */
	cout<<"\nTesting LinekdMap<string, double> using Map<string, double> ADT reference"<<endl;
	Map<string, double>* mapRef6 = new LinkedMap<string, double>();
	for(int i=0; i<11; i++) {
		mapRef6->put(letter_grades[i], grade_points[i]);
	}

	for(int i=0; i<11; i++) {
		if(mapRef6->containsKey(letter_grades[i])) {
			cout<<"<"<<letter_grades[i]<<":"<<mapRef6->get(letter_grades[i])<<"> ";
		}
	}
	cout<<endl;
	delete mapRef6;


    return 0;
}
