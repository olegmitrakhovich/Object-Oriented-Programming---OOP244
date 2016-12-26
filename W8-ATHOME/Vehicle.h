// OOP244 Workshop 8: Virtual Functions at home
// File Vehicle.h
// Version 1.0
// Date 24/july/2016
// Author Oleg Mitrakhovich
// Description
// Vehicle class header file.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

class Vehicle {
	double speed;
public:
	double getSpeed() const;
	void   setSpeed(double);
	virtual void accelerate() = 0;
	virtual void brake() = 0;
	virtual void display(std::ostream&) const = 0;
	Vehicle();
	Vehicle(double);
	virtual void set(std::istream&) = 0;
};
std::istream& operator>>(std::istream&, Vehicle&);
std::ostream& operator<<(std::ostream&, Vehicle&);
void move(Vehicle&);
void show(const Vehicle&);

#endif
