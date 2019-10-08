// c867PerformanceAssessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iomanip>
#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"


Roster::Roster() {

}

Roster::~Roster() {

}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToCompleteCourseOne, int daysToCompleteCourseTwo, int daysToCompleteCourseThree, degree degreeType) {
	int i = 0;
	while (classRosterArray[i] != nullptr) {
		i++;
	}
	if (degreeType == SOFTWARE) {
		classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourseOne, daysToCompleteCourseTwo, daysToCompleteCourseThree, degreeType);
	}
	else if (degreeType == SECURITY) {
		classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourseOne, daysToCompleteCourseTwo, daysToCompleteCourseThree, degreeType);
	}
	else if (degreeType == NETWORKING) {
		classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourseOne, daysToCompleteCourseTwo, daysToCompleteCourseThree, degreeType);
	}
};
	

void Roster::remove(string studentID) {
	cout << "Removing student from roster..." << endl;
	int i;
	int foundAt = 6;
	for (i = 0; i < 5; i++) { //Iterates through classRosterArray
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetStudentID() == studentID) { //Checks if student matches student ID.
				foundAt = i; //Says
				cout << "Found student...attempting to delete." << endl;
				classRosterArray[i] = nullptr;
			}
		}
	}
	if (foundAt != 6) {
		cout << "SUCCESS!" << endl;
		return;
	}
	else {
		cout << "No student was found matching that Student ID." << endl;
		return;
	}
}

void Roster::printAll() {
	cout << "Displaying all students on roster..." << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printDaysInCourse(string studentID) { //FIXME: How is this going to work?
	int i;
	double sum = 0.0;
	double avg = 0.0;
	for (i = 0; i < 5; i++) { //Iterates through classRosterArray.
		if (classRosterArray[i]->GetStudentID() == studentID) { //Checks to see if the studentID at the current Roster element matches the studentID parameter.
			int sum = (classRosterArray[i]->GetNumOfDaysToCompleteCourse()[0]) + (classRosterArray[i]->GetNumOfDaysToCompleteCourse()[1]) + (classRosterArray[i]->GetNumOfDaysToCompleteCourse()[2]); //If it does, it finds the sum...
			double avg = sum / 3; //Then calcs the avg.
			cout << "This student with Student ID # " << classRosterArray[i]->GetStudentID() <<  " has " << avg << " days on average to complete each course." << endl;
		}
	}
	
}

void Roster::printInvalidEmails() {
	cout << endl;
	cout << "Displaying Invalid Emails..." << endl;
	vector<string> invalidEmails;
	for (int i = 0; i < 5; i++) { //Iterates through classRosterArray
		if (classRosterArray[i] != nullptr) { // checks to see if array index is empty or not.
			string tempEmail = classRosterArray[i]->GetEmailAddress(); //sets array index email address to tempEmail
			bool spacePass = true;
			bool atPass = false;
			bool periodPass = false;
			for (int j = 0; j < tempEmail.length(); j++) { //iterates through temp email
				if (tempEmail[j] == ' ') {
					spacePass = false;
				}
				else if (tempEmail[j] == '@') {
					atPass = true;
				}
				else if (tempEmail[j] == '.') {
					periodPass = true;
				}
			}
			if (spacePass == false || atPass == false || periodPass == false) {
				invalidEmails.push_back(tempEmail);
			}
		}
	}

	for (int k = 0; k < invalidEmails.size(); k++) {
		cout << invalidEmails[k] << endl;
	}

}

void Roster::printByDegreeProgram(int degreeProgram) {
	cout << "Printing by degree program..." << endl;
	int i;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << "DONE" << endl;
}

int main() {
	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Lucas,Roberts,lrob349@wgu.edu,26,30,19,24,SOFTWARE" };

	cout << "WGU C867 Scripting and Programming Applications - C++" << endl;
	cout << "Lucas Roberts, BSCS - Student ID: #001085316" << endl;

	Roster classRoster;
	
	cout << sizeof(studentData) << endl;
	cout << "Populating roster with student data..." << endl;
	degree studDegree = NONE;
	string arrayTemp[9];
	int i;
	int k = 0;
	for (i = 0; i < 5; i++) { //Iterates through "rows" of studentData.
		string arrayTemp[9];
		for (int j = 0; j < 8; j++){ //Iterates through student data row [i] and places each split string into an array.
			std::string dataOutputSplit;
			istringstream ss(studentData[i]);
			while (getline(ss, dataOutputSplit, ',')) {
				arrayTemp[j] = dataOutputSplit;
				j++;
			}
		}

		if (arrayTemp[8] == "NETWORK"){
			
			studDegree = NETWORKING;
		}
		else if (arrayTemp[8] == "SECURITY") {
			
			studDegree = SECURITY;
		}
		if (arrayTemp[8] == "SOFTWARE") {
			
			studDegree = SOFTWARE;
		}

		string tempID = arrayTemp[0];
		string tempFirstName = arrayTemp[1];
		string tempLastName = arrayTemp[2];
		string tempEmailAddress = arrayTemp[3];
		int tempAge = std::stoi(arrayTemp[4]);
		int tempDaysOne = std::stoi(arrayTemp[5]);
		int tempDaysTwo = std::stoi(arrayTemp[6]);
		int tempDaysThree = std::stoi(arrayTemp[7]);
		
		classRoster.add(tempID, tempFirstName, tempLastName, tempEmailAddress, tempAge, tempDaysOne, tempDaysTwo, tempDaysThree, studDegree);
		cout << i << endl;
		}

	cout << "lvl before printall." << endl;

	int classRosterArraySize = sizeof(classRoster);
	cout << classRosterArraySize << endl;
	classRoster.printAll();
	classRoster.printInvalidEmails();
	cout << endl;
	cout << "Displaying students' average days per course left..." << endl;
	for (int i = 0; i < 5; i++) {
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	classRoster.~Roster();
	return 0;
	}

