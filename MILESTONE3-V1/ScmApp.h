// OOP244 Milestone 2
// File Course.cpp
// Version 1.0
// Date 28 July 2016
// Author Oleg Mitrakhovich
// Description
// header file for ScmApp class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#ifndef SCMAPP_H
#define SCMAPP_H
#include <iostream>
#include <fstream>
#include "Course.h"
#include "General.h"

namespace sict {

	class ScmApp {
		Course* courseList_[MAX_NO_RECS];
		int noOfCourses_;
		char filename_[256];
		std::fstream datafile_;
		//int noOfCourses;
		void pause() const;
		int menu();
		void listCourses() const;
		int searchACourse(const char*) const;
		void changeStudyLoad(const char*);
		void addACourse();
		void loadRecs();
		void saveRecs();
	public:
		//friend class ScmAppTester;
		int run();
		ScmApp();
		ScmApp(const char*);
		ScmApp(const ScmApp&);
		ScmApp& operator=(const ScmApp&);
	};

}

#endif
