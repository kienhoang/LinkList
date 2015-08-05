#pragma once
#include <string>
class Student
{
private:
	std::string name_;
	int code_;
	Student* next_;
	int id;
public:
	Student(std::string name="", int code=0);
	void setName(std::string name);
	std::string getName();
	void setCode(int code);
	int getCode();
	void setNext(Student* next);
	Student* getNext();
	~Student();
};

