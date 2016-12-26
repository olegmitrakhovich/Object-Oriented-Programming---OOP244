// OOP244 Workshop 3
// File weather.h
// Version 1.0
// Date 30 May 2016
// Author Oleg Mitrakhovich
// Description
// Header file for workshop 3
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#ifndef WEATHER_H
#define WEATHER_H

namespace sict {

	class Weather {
		char date[7];
		double high;
		double low;
	public:
		void set(const char*, double, double);
		void display() const;
	};

}
#endif
