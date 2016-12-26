// OOP244 Milestone 3 and 4 
// File ScmApp.cpp
// Version 1.0
// Date 8 August 2016
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

using namespace sict;
using namespace std;

ScmApp::ScmApp() {
	for (int i = 0; i < MAX_NO_RECS; i++) {
		courseList_[i] = nullptr;
	}

	noOfCourses_ = 0;
}

ScmApp::ScmApp(const char* filename) {
	for (int i = 0; i < MAX_NO_RECS; i++) {
		courseList_[i] = nullptr;
	}

	noOfCourses_ = 0;

	strncpy(filename_, filename, 256);
}

ScmApp::ScmApp(const ScmApp& src) {
	for (int i = 0; i < MAX_NO_RECS; i++) {
		courseList_[i] = nullptr;
	}

	*this = src;
}

ScmApp& ScmApp::operator=(const ScmApp& src) {
	if (this != &src) {
		noOfCourses_ = src.noOfCourses_;
		//delete [] courseList_;
		for (int i = 0; i < MAX_NO_RECS; i++) {
			courseList_[i] = nullptr;
		}
		if (src.courseList_[0]) {
			for (int i = 0; i < src.noOfCourses_; i++) {
				courseList_[i] = new Course[i];
			}
			for (int i = 0; i < src.noOfCourses_; i++) {
				courseList_[i] = src.courseList_[i];
			}
		}
	}
	return *this;
}

void ScmApp::pause() const {
			
		do {
			cout << "Press Enter to continue...";
		} while (getchar() != '\n');
	
}

int ScmApp::menu() {
	
	int answer = 0;
	//cout << endl;
	cout << "Seneca Course Management Tool" << endl;
	cout << "1- List courses." << endl;
	cout << "2- Display the details of a course." << endl;
	cout << "3- Add a course." << endl;
	cout << "4- Change the study load of a course." << endl;
	cout << "5- Load Courses from a file." << endl;
	cout << "6- Save Courses to a file." << endl;
	cout << "0- Exit Program" << endl;
	cout << '>';
	cin >> answer;
	cin.ignore(2000, '\n');

	cout << endl;
	if (answer == 1 || answer == 2 || answer == 3 || answer == 4 || answer == 5 || answer == 6 || answer == 0) {
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
	for (int i = 0; i < noOfCourses_; i++) {
	
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

int ScmApp::searchACourse(const char* courseCode) const {
	for (int i = 0; i < noOfCourses_; i++) {
		if (strcmp(courseList_[i]->getCourseCode(), courseCode) == 0) {
			return i;
		}
	}
	return -1;
}

void ScmApp::changeStudyLoad(const char* courseCode) {
	cin.ignore(2000, '\n');
	int answer;
	if (searchACourse(courseCode) != -1) {
		int i = searchACourse(courseCode);
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
	
	int coursetype = 0;
	
	cout << "Please enter the course type (1-ICT or 2-GenED): ";
	cin >> coursetype;
	cin.ignore(2000, '\n');
	
	if (coursetype == 1) {
		
		courseList_[noOfCourses_] = new ICTCourse;
		courseList_[noOfCourses_]->read(cin);
	}
	else {
		
		courseList_[noOfCourses_] = new GenEdCourse;
		courseList_[noOfCourses_]->read(cin);
	}
	noOfCourses_ = noOfCourses_ + 1;
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
			if (searchACourse(course) != -1) {
				cout << endl;
				cout << "Course Code: " << courseList_[searchACourse(course)]->getCourseCode() << endl;
				cout << "Course Title: " << courseList_[searchACourse(course)]->getCourseTitle() << endl;
				cout << "Credits: " << courseList_[searchACourse(course)]->getCredits() << endl;
				cout << "Study Load: " << courseList_[searchACourse(course)]->getStudyLoad() << endl;
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
		else if (x == 5) {
			loadRecs();
		}
		else if (x == 6) {
			saveRecs();
		}
		else if (x == 0) {
			cout << "Goodbye!!" << endl;
		}
		else if (x == -1) {
			cout << "===Invalid Selection, try again. ===" << endl;
		}

		return x;
}

void ScmApp::loadRecs() {
	int readIndex = 0;
	char ch[256];

	std::fstream myfile;
	myfile.open(filename_, std::ios::in);

	if (!myfile.is_open()) {
		cout << "file reading failed" << endl;
		myfile.clear();
		myfile.close();
	}
	else {
		
		for (int i = 0; i < noOfCourses_; i++) {
			delete [] courseList_[i];
			courseList_[i] = nullptr;
			noOfCourses_ = 0;
		}
		
		
		while (myfile.getline(ch, 256, ',')) {
			
				if (strcmp(ch, TYPE_ICT) == 0) {
					courseList_[noOfCourses_] = new ICTCourse;
					courseList_[noOfCourses_]->load(myfile);
					noOfCourses_ = noOfCourses_ + 1;
				}

				if (strcmp(ch, TYPE_GEN) == 0) {
					courseList_[noOfCourses_] = new GenEdCourse;
					courseList_[noOfCourses_]->load(myfile);
					noOfCourses_ = noOfCourses_ + 1;

				}
		}
	}
	
	myfile.clear();
	myfile.close();
}

void ScmApp::saveRecs() {
	std::fstream newfile("output.txt", std::ios::out);
	for (int i = 0; i < noOfCourses_; i++) {
		courseList_[i]->store(newfile);
	}
	newfile.close();
}

