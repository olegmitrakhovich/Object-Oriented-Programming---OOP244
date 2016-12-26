// OOP244 Workshop 7 at home
// File Hero.cpp
// Version 1.0
// Date 12 July 2016
// Author Oleg Mitrakhovich
// Description
// function definitions for the hero class
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#include "hero.h"
#include <cstring>

Hero::Hero() {
		setEmpty();
}

Hero::Hero(const char* name_, double str) {
	if (name_ != nullptr  && str > 0) {
		strcpy(name, name_);
		strength = str;
	}
	else if (str <= 0) {
		setEmpty();
	}
}

bool Hero::isEmpty() const {
	if (name[0] == '\0' && strength == 0) {
		return true;
	}
	else {
		return false;
	}
}

double Hero::getStrength() const {
	if (isEmpty()) {
		return 0.0;
	}
	else {
		return strength;
	}
}

void Hero::display(std::ostream& os) const {
	if (!isEmpty()) {
		os << " " <<  name << " - " << strength << std::endl;
	}
}

bool operator<(const Hero& hero1, const Hero& hero2) {
	if (hero1.getStrength() < hero2.getStrength()) {
		return true;
	}
	else {
		return false;
	}

}

void Hero::operator-=(double str) {
	if (strength > str) {
		strength -= str;
	}
	else if (strength < str) {
		strength = 0.0;
	}
}

void Hero::operator+=(double str) {
	strength += str;

}

void Hero::setEmpty() {
	strength = 0;
	name[0] = '\0';
}
