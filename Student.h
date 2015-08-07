#pragma once
#include <string>
#include <iostream>
#include "StringProcess.h"

class Student
{
private:
	std::string name_;
	int code_;
	Student* next_;
	int id_;
public:
	Student(std::string name="", int code=0,int id=0);
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
class FindName {
private: 
	int id_;
	int code_;
public:
	void setID(int id);
	int getID();
	void setCode(int code);
	int getCode();
};
namespace stdnt {

	int FindByID(int id, Student *first, Student * &p);
	int FindByCode(int code, Student *first, Student * &p);
	int Add(std::string name, int code, int &i, Student * &p, Student * &first);
	int AddStudent(std::string name, int code, int &i, Student * &p, Student * &first);
	int DeleteByID(Student * &first, int id);
	int DeleteByCode(Student * &first, int code);
	int FindByNameCount(std::string name, Student *first);
	int FindByName(std::string name, Student *first, FindName * &fn);
	void RefactorID(Student* first);
	void Release(Student* &first);

	void wait();
	void Menu_console(int &c);
	void MenuDelete_console(int &c);
	void Input_console(std::string &name, int &code, int id);
	void PrintList_console(Student* first);
	void DelStudentByID_console(Student * &first);
	void DelStudentByCode_console(Student * &first);
	void AddStudent_console(std::string name, int code, int &i, Student * &p, Student * &first);
	void DeleteStudent_console(Student * &first, int &i);
	void FindName_console(Student* first);
}

