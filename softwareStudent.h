#include <string>
#include "student.h"
#include "degree.h"
#pragma once
class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	~SoftwareStudent();
	using Student::Student;
	degree GetDegreeProgram() override;

private:
	degree degreeType = SOFTWARE;
};