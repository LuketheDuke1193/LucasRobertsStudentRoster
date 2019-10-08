#include <string>
#include "student.h"
#include "degree.h"
#pragma once

class NetworkStudent : public Student {
public:
	NetworkStudent();
	~NetworkStudent();
	using Student::Student;
	degree GetDegreeProgram() override;

private:
	degree degreeType = NETWORKING;
};