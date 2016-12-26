// OOP244 Workshop 8: Virtual Functions
// File Truck.cpp
// Version 1.0
// Date 23/July/2016
// Author Oleg Mitrakhovich
// Description
// function definitions for Truck class
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#include "Truck.h"

Truck::Truck() {
	setSpeed(0.0);
	tow = false;
}

Truck::Truck(double sp, bool tow_ = false) {
	setSpeed(sp);
	tow = tow_;
}

void Truck::accelerate() {
	double speed = getSpeed();
	speed += 50;
	setSpeed(speed);
}

void Truck::brake() {
	double speed = getSpeed();
	speed -= 20;
	setSpeed(speed);
}

void Truck::display(std::ostream& os) const {
	os << "This truck is going " << getSpeed() << " after acceleration and braking, and " << 
		((tow) ? "it can be used to tow." : "it cannot be used to tow.") << std::endl;
}

