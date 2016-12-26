// OOP244 Workshop 8: Virtual Functions at home
// File Bus.h
// Version 1.0
// Date 24/july/2016
// Author Oleg Mitrakhovich
// Description
// bus class header file
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#ifndef BUS_H
#define BUS_H
#include "Vehicle.h"

class Bus : public Vehicle {
	int pass;
public:
	Bus();
	Bus(double, int);
	void accelerate();
	void brake();
	void display(std::ostream&) const;
	void set(std::istream&);
};

#endif
