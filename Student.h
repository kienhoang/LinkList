#pragma once
#include <string>
class Student
{
private:
	std::string name_;
	int code_;
	Student* next_;
	int id_;
public:
	Student(std::string name="", int code=0,int id=0);
	void setName(std::string name);
	std::string getName();
	void setCode(int code);
	int getCode();
	void setNext(Student* next);
	Student* getNext();
	void setID(int id);
	int getID();
	~Student();
};

