#include "Course.h"
#include "General.h"

using namespace sict;

Course::Course() {
	courseCode_[0] = '\0';
	courseTitle_ = nullptr;
	credits_ = 0;
	studyLoad_ = 0;
}

Course::Course(const char* code, const char* title, int credits, int studyLoad) {
	strncpy(courseCode_, code, MAX_COURSECODE_LEN + 1);
	
	courseTitle_ = new char[strlen(title) + 1];
	strcpy(courseTitle_, title);

	credits_ = credits;
	studyLoad_ = studyLoad;
}

Course::Course(const Course& src) {
	courseTitle_ = nullptr;
	*this = src;
}

Course& Course::operator=(const Course& src) {
	if (this != &src) {
		credits_ = src.credits_;
		studyLoad_ = src.studyLoad_;
		strncpy(courseCode_, src.courseCode_, MAX_COURSECODE_LEN);
		delete [] courseTitle_;
		if (src.courseTitle_ != nullptr) {
			courseTitle_ = new char[strlen(src.courseTitle_) + 1];
			strcpy(courseTitle_, src.courseTitle_);
		}
		else
			courseTitle_ = nullptr;
	}
	return *this;
}

Course::~Course() {
	delete [] courseTitle_;
}

void Course::setCourseCode(const char* src) {
	strncpy(courseCode_, src, MAX_COURSECODE_LEN + 1 );
	
}

void Course::setCourseTitle(char* src) {
	//std::cout << src;
	//courseTitle_ = src;
	courseTitle_ = new char[strlen(src) + 1];
	strcpy(courseTitle_, src);
	//courseTitle_[strlen(src)] = '\0';
	//std::cout << courseTitle_;
}
void Course::setCredits(int src) {
	credits_ = src;
}

void Course::setStudyLoad(int src) {
	studyLoad_ = src;
}

const char* Course::getCourseCode() const {
	return courseCode_;
}

const char* Course::getCourseTitle() const {
	return courseTitle_;
}

int Course::getCredits() const {
	return credits_;
}
int Course::getStudyLoad() const {
	return studyLoad_;
}

bool Course::isEmpty() const {
	if (courseCode_[0] == '\0' && courseTitle_ == nullptr && credits_ == 0 && studyLoad_ == 0) {
		return true;
	}
	else
		return false;
}

bool Course::operator==(const char* src) {
	if (courseCode_ == src) {
		return true;
	}
	else
		return false;

}

int Course::operator+=(int src) {
	if (src > 0) {
		studyLoad_ += src;
		return studyLoad_;
	}
	else if (src < 0) {
		studyLoad_ -= src;
		return studyLoad_;
	}
}

void Course::display(std::ostream& os) const {
	os << courseCode_ << ' ' << courseTitle_ << ' ' << credits_ << ' ' << studyLoad_ << std::endl;
}
	
namespace sict {

	std::ostream& operator<<(std::ostream& os, const Course& src) {
		src.display(os);
		return os;
	}

};




