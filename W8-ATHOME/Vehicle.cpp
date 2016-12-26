// OOP244 Workshop 8: Virtual Functions at home
// File Vehicle.cpp
// Version 1.0
// Date 24/july/2016
// Author Oleg Mitrakhovich
// Description
// Vehicle class function definitions.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#include "Vehicle.h"
#include <iostream>

using namespace std;

double Vehicle::getSpeed() const {
	return speed;
}

void Vehicle::setSpeed(double src) {
	if (src > 0.0) {
		speed = src;
	}
	else {
		speed = 0.0;
	}
}


void show(const Vehicle& obj) {
	obj.display(std::cout);
}

void move(Vehicle& obj) {
	obj.accelerate();
	obj.brake();
}

Vehicle::Vehicle() {	
	
	speed = 0.0;
			
}

Vehicle::Vehicle(double num) {
	if (num > 0.0) {
		speed = num;
	}
	else {
		speed = 0.0;
	}
}

std::istream& operator>>(std::istream& is, Vehicle& obj) {
		obj.set(is);
		move(obj);
	return is;
}

std::ostream& operator<<(std::ostream& os, Vehicle& obj) {
	obj.display(os);
	return os;
}
