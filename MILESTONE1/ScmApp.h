#ifndef SCMAPP_H
#define SCMAPP_H
#include "Course.h"
#include "General.h"

namespace sict {

	class ScmApp {
		Course* courseList_[MAX_NO_RECS];
		int noOfCourses;
		//void pause() const;
		//int menu();
		//void listCourses() const;
		int searchAcourse(const char* courseCode) const;
		void changeStudyLoad(const char* courseCode);
		void addACourse();
	public:
		int run();
		ScmApp();
		ScmApp(const ScmApp&);
		ScmApp& operator=(const ScmApp&);
		void pause() const;
		int menu();
		void listCourses() const;
	};

}

#endif
