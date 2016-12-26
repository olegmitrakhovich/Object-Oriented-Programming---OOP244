// OOP244 Milestone 3 and 4
// File Streamble.h
// Version 1.0
// Date 8 August 2016
// Author Oleg Mitrakhovich
// Description
// function prototype for streamble class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#ifndef STREAMBLE_H
#define STREAMBLE_H
#include <fstream>

namespace sict {

	class Streamable {
	public:
		virtual std::fstream& store(std::fstream&, bool addNewLine = true) const = 0;
		virtual std::fstream& load(std::fstream&) = 0;
		virtual std::ostream& display(std::ostream&) const = 0;
		virtual std::istream& read(std::istream&) = 0;

	};

}
#endif
