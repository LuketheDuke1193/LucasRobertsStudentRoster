#include <string>
#include "student.h"
#include "degree.h"
#pragma once
class SecurityStudent : public Student
{
public:
	SecurityStudent();
	~SecurityStudent();
	using Student::Student;
	degree GetDegreeProgram() override;

private:
	degree degreeType = SECURITY;
};