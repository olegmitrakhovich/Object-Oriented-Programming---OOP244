// OOP244 Workshop 7 at home
// File SuperHero.cpp
// Version 1.0
// Date 12 July 2016
// Author Oleg Mitrakhovich
// Description
// function definitions for the SuperHero class
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#include "SuperHero.h"

SuperHero::SuperHero() : Hero() {
	        
}

SuperHero::SuperHero(const char* ptr, double herostr, double multi) : Hero(ptr, herostr) {
	multi_ = multi;
}

SuperHero::SuperHero(const SuperHero& src) : Hero(src){
	multi_ = src.multi_;
	
}

double SuperHero::getStrength() {
	return Hero::getStrength() * multi_;
}

void SuperHero::operator*=(SuperHero& hero) {
	if (getStrength() < hero.getStrength()) {
		hero += getStrength();
		setEmpty();
	}
	else if (getStrength() > hero.getStrength()) {
		*this += hero.getStrength();
		 hero.setEmpty();
	}
}


void SuperHero::display(std::ostream& os) const {
	if (!isEmpty()) {
		os << "living superhero!";
		Hero::display(os);
	}
	else if (isEmpty()) {
		os << "deceased superhero!" << std::endl;
	}
}
