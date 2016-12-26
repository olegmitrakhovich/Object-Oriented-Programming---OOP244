// OOP244 Workshop 3: Dynamic Memory at Home
// File	w3_in_lab.cpp
// Version 1.0
// Date	30 May 2016
// Author   Oleg Mitrakhovich
// Description
// This file is used to demonstrate dynamic memory in 
// C++ and to process an array of objects of compound 
// type where the user specifies the number of 
// elements in the array at run-time.
/////////////////////////////////////////////////////////////////////////////////////
// Revision History
//
// Name              Date         Reason
//Oleg Mitrakhovich  1 June 2016  added a global Function findLow() and its definition
///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Weather.h"
using namespace std;
using namespace sict;

double findLow(const char* date, const Weather* data, int dataSize);

double findLow(const char* date, const Weather* data, int dataSize) {
	
	for (int i = 0; i < dataSize; i++) {
		if (strcmp(data[i].Date(), date) == 0) {
			return data[i].Low();
		};
	};

	return 0.0;
};



int main() {
	int i; //  loop counter
	int n; //the count of days worth of weather
		   // initialize the weather pointer here
	Weather* cpa = nullptr;

	cout << "Weather Data" << endl
		<< "=====================" << endl
		<< "Days of Weather: ";
	cin >> n;
	cin.ignore();

	// allocate dynamic memory here
	cpa = new Weather[n];


	for (i = 0; i < n; i++) {
		char date_description[7];
		double high;
		double low;
		cout << "Enter date: ";
		cin >> date_description;
		cout << "Enter high: ";
		cin >> high;
		cout << "Enter low : ";
		cin >> low;
		cpa[i].set(date_description, high, low);

		// ... add code to accept the user input
		// for the weather array

	}
	cout << endl
		<< "Weather report:" << endl
		<< "Date        high  low" << endl
		<< "======================" << endl;

	for (i = 0; i < n; i++) {
		cpa[i].display();
	}

	char query[7];
	cout << endl << "Enter the date you are looking for: ";
	//accept user input for the date to find
	//(in this example stored in char query[7])
	// and display the found low temprature.

	cin >> query;
	double low = findLow(query, cpa, n);
	cout << "Low temperature: " << low << endl;


	// deallocate dynamic memory here
	delete [] cpa;
	cpa = nullptr;
	return 0;
}
