// OOP244 Workshop 7 at home
// File SuperHero.h
// Version 1.0
// Date 12 July 2016
// Author Oleg Mitrakhovich
// Description
// SuperHero class and all of its prototypes
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#include "hero.h"

class SuperHero : public Hero {
	double multi_;
public:
	SuperHero();
	SuperHero(const char*, double, double);
	SuperHero(const SuperHero&);
	double getStrength();
	void operator*=(SuperHero&);
	void display(std::ostream&) const;

};
