#include "Student.h"

Student::Student(std::string name, int code,int id)
{
	name_ = name;
	code_ = code;
	id_ = id;
	next_ = 0;
}

void Student::setName(std::string name)
{	
	name_ = name;
}

std::string Student::getName()
{
	return name_;
}

void Student::setCode(int code)
{
	code_ = code;
}

int Student::getCode()
{
	return code_;
}

void Student::setNext(Student * next)
{
	next_ = next;
}

Student * Student::getNext()
{
	return next_;
}

void Student::setID(int id)
{
	id_ = id;
}

int Student::getID()
{
	return id_;
}

Student::~Student()
{
}

