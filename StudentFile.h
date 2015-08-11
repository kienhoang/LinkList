#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"
#include "StringProcess.h"

class StudentFile {
private:
	std::fstream f;
public:
	bool CreateFile();
	bool OpenFile();
	bool WriteFile(Student* first);
	bool ReadFile(int & code, std::string & name);
	void ImportFromFile(Student * &first, Student * &p, int &id);
	void CloseFile();
};