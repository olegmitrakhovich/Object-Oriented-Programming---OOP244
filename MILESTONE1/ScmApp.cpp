#include "ScmApp.h"
#include <iostream>
#include <iomanip>

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
	//std::cin.ignore();
		do {
			std::cout << "Press Enter to continue..." << std::endl;
			if (std::cin.get() != '\n') {
				exit = 0;
			}
			else {
				exit = 1;
			}

		} while (exit = 0);
	
}

int ScmApp::menu() {
	//std::cin.ignore(2000, '\n');
	int answer = 0;
	std::cout << "Seneca Course Management tool" << std::endl;
	std::cout << "1- List Courses." << std::endl;
	std::cout << "2- Display the details of a course." << std::endl;
	std::cout << "3- Add a course." << std::endl;
	std::cout << "4- Change the study load of a course." << std::endl;
	std::cout << "0- Exit program" << std::endl;
	std::cout << '>';
	std::cin >> answer;
	if (answer == 1 || answer == 2 || answer == 3 || answer == 4 || answer == 0) {
		return answer;
	}
	else {
		return -1;
	}
}


void ScmApp::listCourses() const {
	cout << " Row " << "|" << " Code " << "|" << " Course Title " << "|" << " Credits " << "|" << " Study Load " << "|" << " System " << "|" << " Lang. Req. " << "|" << endl;
	cout << "-----|" << "------|" << "--------------|" << "---------|" << "------------|" << "--------|" << "------------|" << endl;
	for (int i = 0; i < noOfCourses; i++) {
		cout << right << setw(4) << i;
		cout << " " << "|" << " ";
		cout << courseList_[i]->getCourseCode();
		cout << " " << "|" << " ";
		cout << courseList_[i]->getCourseTitle();
		cout << " " << "|" << " ";
		cout << courseList_[i]->getCredits();
		cout << " " << "|" << " ";
		cout << courseList_[i]->getStudyLoad();
		cout << " " << "|" << " " << endl;
		if (i == 10) {
			pause();
		}
	}
	cout << "-------------------------------------------------------------------------" << endl;
}

int ScmApp::searchAcourse(const char* courseCode) const {
	for (int i = 0; i < noOfCourses; i++) {
		if (courseList_[i]->getCourseCode() == courseCode) {
			return i;
		}
	}
	return -1;
}

void ScmApp::changeStudyLoad(const char* courseCode) {
	cin.ignore(2000, '\n');
	int answer;
	if (searchAcourse(courseCode) != -1) {
		cout << "Please enter the amount of the study load: ";
		cin >> answer;
		courseList_[searchAcourse(courseCode)] += answer;
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
	courseList_[noOfCourses] = new Course;
	cout << "Please Enter Course Code: ";
	cin >> coursecode;
	courseList_[noOfCourses]->setCourseCode(coursecode);
	cin.ignore(2000, '\n');
	cout << "Please Enter Course Title: ";
	cin >> coursetitle;
	//cout << coursetitle;
	courseList_[noOfCourses]->setCourseTitle(coursetitle);
	cin.ignore(2000, '\n');
	cout << "Please Enter the amount of credits: ";
	cin >> credits;
	courseList_[noOfCourses]->setCredits(credits);
	cin.ignore(2000, '\n');
	cout << "Please Enter Study load: ";
	cin >> studyload;
	courseList_[noOfCourses]->setStudyLoad(studyload);
	cin.ignore(2000, '\n');
	noOfCourses = noOfCourses + 1;
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
				cout << courseList_[searchAcourse(course)]->getCourseCode();
				cout << courseList_[searchAcourse(course)]->getCourseTitle();
				cout << courseList_[searchAcourse(course)]->getCredits();
				cout << courseList_[searchAcourse(course)]->getStudyLoad();
				
			}
			else {
				cout << "Not Found!" << endl;
				
			}
		}
		else if (x == 3) {
			addACourse();
			
		}
		else if (x == 4) {
			cout << "Please enter the course code: ";
			cin >> course;
			changeStudyLoad(course);	
		}
		else if (x == 0) {
			cout << "GoodBye!!" << endl;
		}
		else if (x == -1) {
			cout << "===Invalid Selection, try again. ===" << endl;
		}

		return 0;
}