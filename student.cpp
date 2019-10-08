#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student(){ // Default Constructor

};

Student::~Student() { // Destructor

};

//Constructor Using Parameters
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourseOne, int daysToCompleteCourseTwo, int daysToCompleteCourseThree, degree degreeType) {
	Student::studentID = studentID;
	Student::firstName = firstName;
	Student::lastName = lastName;
	Student::emailAddress = emailAddress;
	Student::age = age;
	Student::numOfDaysToCompleteCourse[0] = daysToCompleteCourseOne;
	Student::numOfDaysToCompleteCourse[1] = daysToCompleteCourseTwo;
	Student::numOfDaysToCompleteCourse[2] = daysToCompleteCourseThree;
	Student::degreeType = degreeType;
};

//ACCESSORS

string Student::GetStudentID() {
	return Student::studentID;
};

string Student::GetFirstName() {
	return Student::firstName;
};

string Student::GetLastName() {
	return Student::lastName;
};

string Student::GetEmailAddress() {
	return Student::emailAddress;
};

int Student::GetAge() {
	return Student::age;
};

int* Student::GetNumOfDaysToCompleteCourse() { //FIXME
	return Student::numOfDaysToCompleteCourse;
};

degree Student::GetDegreeProgram() { //Leaving empty for other classes to override.
	return NONE;
};

//SETTERS

void Student::SetStudentID(std::string studentID) {
	Student::studentID = studentID;
};

void Student::SetFirstName(std::string firstName) {
	Student::firstName = firstName;
};

void Student::SetLastName(std::string lastName) {
	Student::lastName = lastName;
};

void Student::SetEmailAddress(std::string emailAddress) {
	Student::emailAddress = emailAddress;
};

void Student::SetAge(int age) {
	Student::age = age;
};

void Student::SetNumOfDaysToCompleteCourse(int daysToCompleteCourseOne, int daysToCompleteCourseTwo, int daysToCompleteCourseThree) {
	Student::numOfDaysToCompleteCourse[0] = daysToCompleteCourseOne;
	Student::numOfDaysToCompleteCourse[1] = daysToCompleteCourseTwo;
	Student::numOfDaysToCompleteCourse[2] = daysToCompleteCourseThree;
};

void Student::print() { //Prints specific data for students.
	cout << "   " << "First Name: " << GetFirstName() << "   " << "Last Name: " << GetLastName() << "   "
		<< "Age: " << GetAge() << "   " << "Days in Course: " << *GetNumOfDaysToCompleteCourse() << "   "
		<< "Degree Program: ";
	if (GetDegreeProgram() == SOFTWARE) {
		cout << "Software" << endl;
	}
	else if (GetDegreeProgram() == SECURITY) {
		cout << "Security" << endl;
	}
	else if (GetDegreeProgram() == NETWORKING) {
		cout << "NETWORKING" << endl;
	}
	return;
}