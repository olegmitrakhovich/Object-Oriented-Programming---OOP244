// OOP244 Workshop 7
// File hero.h
// Version 1.0
// Date 12 July 2016
// Author Oleg Mitrakhovich
// Description
// base class called hero and all of its prototype functions
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#ifndef HERO_H
#define HERO_H
#include <iostream>

class Hero {
	char name[21];
	double strength;
public:
	Hero();
	Hero(const char*, double);
	bool isEmpty() const;
	double getStrength() const;
	void display(std::ostream&) const;
	void operator-=(double str);
	void operator+=(double strength);
};
bool operator<(const Hero&, const Hero&);
#endif
