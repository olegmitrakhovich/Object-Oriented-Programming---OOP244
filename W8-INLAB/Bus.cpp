// OOP244 Workshop 8: Virtual Functions
// File Bus.cpp
// Version 1.0
// Date 23/July/2016
// Author Oleg Mitrakhovich
// Description
// function definitions for Bus.h file
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
