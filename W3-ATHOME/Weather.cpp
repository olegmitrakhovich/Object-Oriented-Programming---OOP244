// OOP244 Workshop 3 Dynamic Memory at Home portion
// File weather.cpp
// Version 1.0
// Date 30 May 2016
// Author Oleg Mitrakhovich
// Description
// CPP file for workshop 3, defintions of all the class functions
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name              Date         Reason
//Oleg Mitrakhovich  1 June 2016  added extra function defintions 
///////////////////////////////////////////////////////////
#include "Weather.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace sict;

void Weather::set(const char* _date, double h, double l) {
	strncpy(date, _date, 7);
	high = h;
	low = l;
};

const char* Weather::Date() const {
	return date;
};

double Weather::Low() const {
	return low;
};

using namespace std;

void Weather::display() const {

	    cout.fill('_');
		cout << fixed << left << setw(10) << date;
		cout << fixed << right << setw(6) << setprecision(1) << high;
		cout << fixed << right << setw(6) << setprecision(1) << low;
		cout << endl;

};

