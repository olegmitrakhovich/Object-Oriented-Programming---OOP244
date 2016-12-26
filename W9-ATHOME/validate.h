// OOP244 WorkShop 9: Templates at home
// File validate.h
// Version 1.0
// Date 2 Aug 2016
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
#include <string.h>
#include "Car.h"

namespace sict{
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
	
	
	
	template<>
	bool validate<char>(const char& min, const char& max, const char* obj, const int num , bool* bools) {
		
		int test = 0;
		for (int i = 0; i < num; i++) {
			if (obj[i] >= min && obj[i] <= max) {
				bools[i] = true;
			}else if (obj[i] >= min + 32 && obj[i] <= max + 32) {
				bools[i] = true;
			}
			else {
				bools[i] = false;
				test++;
			}
		}

		if (test != 0) {
			return false;
		}
		
		return true;

	};
	

		template<>
		bool validate(const Car& min, const Car& max, const Car* obj, const int num, bool* bools) {
			
			int test = 0;
			for (int i = 0; i < num; i++) {
				if ((strlen(obj[i]) < 6) || !(obj[i] >= min && max >= obj[i])) {
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


