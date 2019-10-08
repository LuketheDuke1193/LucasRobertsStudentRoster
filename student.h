#pragma once
#include <iostream>
#include <string>
#include "degree.h"

class Student {
public:
	//Accessors Declaration
	std::string GetStudentID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmailAddress();
	int GetAge();
	int *GetNumOfDaysToCompleteCourse();
	virtual degree GetDegreeProgram();

	//Mutators Declaration
	void SetStudentID(std::string studentID);
	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetEmailAddress(std::string emailAddress);
	void SetAge(int age);
	void SetNumOfDaysToCompleteCourse(int daysToCompleteCourseOne, int daysToCompleteCourseTwo, int daysToCompleteCourseThree);

	//Constructor, Default Constructor and Destructor
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToCompleteCourseOne, int daysToCompleteCourseTwo, int daysToCompleteCourseThree, degree degreeType);
	Student();
	~Student();
	virtual void print(); //Outputs out specific student's data to command line.



private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int numOfDaysToCompleteCourse[3] = { 0, 0, 0 };
	degree degreeType;
};
