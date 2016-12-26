// OOP244 Milestone 2
// File ScmApp.cpp
// Version 1.0
// Date 28 July 2016
// Author Oleg Mitrakhovich
// Description
// function defintions for ScmApp class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#include "ScmApp.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace sict;
using namespace std;

ScmApp::ScmApp() {
	for (int i = 0; i < MAX_NO_RECS; i++) {
		courseList_[i] = nullptr;
	}

	noOfCourses = 0;
}

ScmApp::ScmApp(const ScmApp& src) {
	for (int i = 0; i < MAX_NO_RECS; i++) {
		courseList_[i] = nullptr;
	}

	*this = src;
}

ScmApp& ScmApp::operator=(const ScmApp& src) {
	if (this != &src) {
		noOfCourses = src.noOfCourses;
		//delete [] courseList_;
		for (int i = 0; i < MAX_NO_RECS; i++) {
			courseList_[i] = nullptr;
		}
		if (src.courseList_[0]) {
			for (int i = 0; i < src.noOfCourses; i++) {
				courseList_[i] = new Course[i];
			}
			for (int i = 0; i < src.noOfCourses; i++) {
				courseList_[i] = src.courseList_[i];
			}
		}
	}
	return *this;
}

void ScmApp::pause() const {
	int exit = 0;
	cin.ignore(2000, '\n');
		do {
			cout << "Press Enter to continue...";
			if (cin.get() != '\n') {
				exit = 0;
			}
			else {
				exit = 1;
			}

		} while (exit == 0);
	
}

int ScmApp::menu() {
	
	int answer = 0;
	//cout << endl;
	cout << "Seneca Course Management Tool" << endl;
	cout << "1- List courses." << endl;
	cout << "2- Display the details of a course." << endl;
	cout << "3- Add a course." << endl;
	cout << "4- Change the study load of a course." << endl;
	cout << "0- Exit Program" << endl;
	cout << '>';
	cin >> answer;
	cout << endl;
	if (answer == 1 || answer == 2 || answer == 3 || answer == 4 || answer == 0) {
		return answer;
		
	}
	else {
		return -1;
		
	}
}


void ScmApp::listCourses() const {
	//cout << endl;
	cout << " Row " << "|" << " Code " << "|" << "               Course Title              " << "|" << " Credits " << "|" << " Study Load " << "|" << " System " << "|" << " Lang. Req. " << "|" << endl;
	cout << setw(6) << setfill('-') << right << "|";
	cout << setw(7) << setfill('-') << right << "|";
	cout << setw(42) << setfill('-') << right << "|";
	cout << setw(10) << setfill('-') << right << "|";
	cout << setw(13) << setfill('-') << right << "|";
	cout << setw(9) << setfill('-') << right << "|";
	cout << setw(13) << setfill('-') << right << "|" << endl;
	cout << setfill(' '); 
	for (int i = 0; i < noOfCourses; i++) {
	
		if ((i % DISPLAY_LINES == 0) && (i != 0)) {
			pause();
		}

		cout << right << setw(4) << i;
		cout << right << " ";
		cout << "|";
		cout << (*courseList_[i]);
	}
	cout << setw(100) << setfill('-') << right << "-" << endl;
	cout << setfill(' ');
	cout << endl;
	
}

int ScmApp::searchAcourse(const char* courseCode) const {
	for (int i = 0; i < noOfCourses; i++) {
		if (strcmp(courseList_[i]->getCourseCode(), courseCode) == 0) {
			return i;
		}
	}
	return -1;
}

void ScmApp::changeStudyLoad(const char* courseCode) {
	cin.ignore(2000, '\n');
	int answer;
	if (searchAcourse(courseCode) != -1) {
		int i = searchAcourse(courseCode);
		cout << "Please enter the amount of the study load: ";
		cin >> answer;
		//courseList_[i]->setStudyLoad(courseList_[i]->getStudyLoad() + answer);	
	        (*courseList_[i]) += answer;
		cout << endl;
		cout << endl;
	}
	else {
		cout << "Not Found!" << endl;
	}
}

void ScmApp::addACourse() {
	
	char coursecode[MAX_COURSECODE_LEN + 1];
	char coursetitle[45];
	int credits = 0;
	int studyload = 0;
	int coursetype = 0;
	int langLevel = 0;
	char system[7];

	cout << "Please enter the course type (1-ICT or 2-GenED): ";
	cin >> coursetype;
	cin.ignore(2000, '\n');

		cout << "Course Code: ";
	cin >> coursecode;

	cin.ignore(2000, '\n');
		cout << "Course Title: ";
	cin.getline(coursetitle, 45, '\n');

		cout << "Course Credit: ";
	cin >> credits;

	cin.ignore(2000, '\n');
		cout << "Study Load: ";
	cin >> studyload;
	if (coursetype == 1) {
		cin.ignore(2000, '\n');
		cout << "System: ";
		cin.getline(system, 7, '\n');
		courseList_[noOfCourses] = new ICTCourse(coursecode, coursetitle, credits, studyload, system);
	}
	else {
		cin.ignore(2000, '\n');
		cout << "Language Requirement: ";
		cin >> langLevel;
		courseList_[noOfCourses] = new GenEdCourse(coursecode, coursetitle, credits, studyload, langLevel);
	}
	noOfCourses = noOfCourses + 1;
	cout << endl;
}

int ScmApp::run() {
	char course[MAX_COURSECODE_LEN + 1];
	int x = menu();
	
	if (x == 1) {
			listCourses();		
		}
		else if (x == 2) {
			cout << "Please enter the course code: ";
			cin >> course;
			if (searchAcourse(course) != -1) {
				cout << endl;
				cout << "Course Code: " << courseList_[searchAcourse(course)]->getCourseCode() << endl;
				cout << "Course Title: " << courseList_[searchAcourse(course)]->getCourseTitle() << endl;
				cout << "Credits: " << courseList_[searchAcourse(course)]->getCredits() << endl;
				cout << "Study Load: " << courseList_[searchAcourse(course)]->getStudyLoad() << endl;
				cout << endl;
				
			}
			else {
				cout << "Not Found!" << endl;
				
			}
		}
		else if (x == 3) {
			addACourse();
			
		}
		else if (x == 4) {
			cout << endl;
			cout << "Please enter the course code : ";
			cin >> course;
			changeStudyLoad(course);	
		}
		else if (x == 0) {
			cout << "Goodbye!!" << endl;
		}
		else if (x == -1) {
			cout << "===Invalid Selection, try again. ===" << endl;
		}

		return x;
}

