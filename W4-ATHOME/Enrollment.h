// OOP244 Workshop 4: Constructors
// File Enrollment.h
// Version 1.0
// Date 9/June/2016
// Author Oleg Mitrakhovich
// Description
// Contains the enrollment class and all the functions needed. 
//
//
// Revision History
////////////////////////////////////////////////////////////////////////////////////////////
// Name                 Date         Reason
//Oleg Mitrakhovich    9/June/2016   Added two function prototypes enroll() and withdraw()
////////////////////////////////////////////////////////////////////////////////////////////
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
		void withdraw();
		int enrol(const Enrollment* enrollments, int size);
	};

}
#endif
