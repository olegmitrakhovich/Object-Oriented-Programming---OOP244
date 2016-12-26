// OOP244 WorkShop 9: Templates
// File validate.h
// Version 1.0
// Date 30 July 2016
// Author Oleg Mitrakhovich
// Description
// validate function for workshop 9
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#ifndef VALIDATE_H
#define VALIDATE_H

namespace sict {

	
	template<typename T> 
	bool validate(const T& min, const T& max, const T* obj, const int num, bool* bools) {
		int test = 0;
		for (int i = 0; i < num; i++) {
			if (!(obj[i] >= min && max >= obj[i])) {
				bools[i] = false;
				test++;
			}
			else {
				bools[i] = true;
			}
		}

		if (test != 0) {
			return false;
		}

		return true;

	};

	
}
#endif
