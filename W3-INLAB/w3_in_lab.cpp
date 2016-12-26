// OOP244 Workshop ??: ??????????
// File w3_in_lab.cpp
// Version 1.0
// Date 1 June 2016
// Author Fardad S.
// Description
// Partial file for workshop 3 for the student complete.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name              Date        Reason
// Oleg Mitrakhovich 30 May 2016 To complete workshop 3
///////////////////////////////////////////////////////////
#include <iostream>
#include "Weather.h"
using namespace std;
using namespace sict;
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

	// deallocate dynamic memory here
	delete [] cpa;
	cpa = nullptr;
	return 0;
}
