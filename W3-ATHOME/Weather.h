// OOP244 Workshop 3 at Home Portion
// File weather.h
// Version 1.0
// Date 30 May 2016
// Author Oleg Mitrakhovich
// Description
// Header file for workshop 3
//
//
// Revision History
////////////////////////////////////////////////////////////////////////
// Name               Date        Reason
// Oleg Mitrakhovich  1 June 2016 added extra function Date(), Low()
////////////////////////////////////////////////////////////////////////
#ifndef WEATHER_H
#define WEATHER_H

namespace sict {

	class Weather {
		char date[7];
		double high;
		double low;
	public:
		void set(const char* _date, double h, double l);
		void display() const;
		const char* Date() const;
		double Low() const;
	};

}
#endif
