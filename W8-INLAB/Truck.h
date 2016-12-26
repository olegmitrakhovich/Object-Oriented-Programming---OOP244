// OOP244 Workshop 8: Virtual Functions
// File Truck.h
// Version 1.0
// Date 23/July/2016
// Author Oleg Mitrakhovich
// Description
// Truck class defined.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

class Truck : public Vehicle {
	bool tow;
public:
	Truck();
	Truck(double, bool);
	void accelerate();
	void brake();
	void display(std::ostream&) const;
};

#endif
