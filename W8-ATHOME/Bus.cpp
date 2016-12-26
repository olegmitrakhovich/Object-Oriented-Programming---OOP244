// OOP244 Workshop 8: Virtual Functions at home
// File Bus.cpp
// Version 1.0
// Date 24/july/2016
// Author Oleg Mitrakhovich
// Description
// function definitions for bus class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#include "Bus.h"
#include <iostream>

using namespace std;

Bus::Bus() {
	setSpeed(0.0);
	pass = 0;
}

Bus::Bus(double sp, int p) {
	setSpeed(sp);
	pass = p;
}

void Bus::accelerate() {
	double speed = getSpeed() + 20;
	setSpeed(speed);
}

void Bus::brake() {
	double speed = getSpeed() - 10;
	setSpeed(speed);
}

void Bus::display(std::ostream& os) const {
	os << "This bus has total capacity of " << pass << " passengers and has a speed of " << getSpeed() << " after acceleration and braking." << endl;
}

void Bus::set(std::istream& in) {
	cout << "Bus => total capacity: ";
	in >> pass;
	cout << "Bus => speed: ";
	double speed = 0;
	in >> speed;
	setSpeed(speed);	
}
