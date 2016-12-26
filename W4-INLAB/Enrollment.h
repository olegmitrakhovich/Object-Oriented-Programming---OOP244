// OOP244 Workshop 4: Constructors
// File Enrollment.h
// Version 1.0
// Date June 8/2016
// Author Oleg Mitrakhovich
// Description
// Header file for Workshop 4
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
//
///////////////////////////////////////////////////////////

#ifndef ENROLLMENT_H
#define ENROLLMENT_H

namespace sict {

	class Enrollment {
		char name_[31];
		char code_[11];
		int year_;
		int semester_;
		int slot_;
		bool enrolled_;
	public:
		bool isEnrolled() const;
		bool isValid() const;
		void setEmpty();
		void display(bool nameOnly = false) const;
		void set(const char* name, const char* code, int year, int semester, int time, bool enrolled = false);
		bool hasConflict(const Enrollment &other) const;
		Enrollment();
		Enrollment(const char* name, const char* code, int year, int semester, int time);
	};

}
#endif
