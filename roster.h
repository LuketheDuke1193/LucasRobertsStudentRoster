#include <iostream>
#include <string>
#include <array>
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#pragma once
class Roster {
public:
	Roster();
	~Roster();

	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToCompleteCourseOne, int daysToCompleteCourseTwo, int daysToCompleteCourseThree, degree degreeType);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	Student *classRosterArray[5] = {
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
	};
private:
	

};
