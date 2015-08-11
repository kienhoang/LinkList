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
	Student(std::string name="", int code=0,int id=0,Student* next=0);
	~Student();
	void setName(std::string name);
	std::string getName();
	void setCode(int code);
	int getCode();
	void setNext(Student* next);
	Student* getNext();
	void setID(int id);
	int getID();
};

namespace stdnt {

	int FindByID(int id, Student *first, Student * &p);
	int FindByCode(int code, Student *first, Student * &p);
	int Add(std::string name, int code, int &id, Student * &p, Student * &first);
	int AddStudent(std::string name, int code, int &id, Student * &p, Student * &first);
	int DeleteByID(Student * &first, int id);
	int DeleteByCode(Student * &first, int code);
	int FindByNameCount(std::string name, Student *first);
	int FindByName(std::string name, Student *first, Student * &fn);
	void RefactorID(Student* first);
	void Release(Student* &first);
}


