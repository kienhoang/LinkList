#include "Student.h"

Student::Student(std::string name, int code,int id,Student* next)
{
	name_ = name;
	code_ = code;
	id_ = id;
	next_ = next;
}
Student::~Student() {
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
Student *Student::getNext()
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

int stdnt::FindByID(int id, Student *first, Student * &p) {
	bool IsFound = true;
	p = first;
	while (p->getID() != id) {
		if (p->getNext() != 0) {
			p = p->getNext();
		}
		else {
			IsFound = false;
			break;
		}
	}
	if (IsFound) {
		return 0;
	}
	else {
		return -1;
	}
}
int stdnt::FindByCode(int code, Student *first, Student * &p) {
	bool IsFound = true;
	p = first;
	while (p->getCode() != code) {
		if (p->getNext() != 0) {
			p = p->getNext();
		}
		else {
			IsFound = false;
			break;
		}
	}
	if (IsFound) {
		return 0;
	}
	else {
		return -1;
	}
}
int stdnt::Add(std::string name, int code, int &id, Student * &p, Student * &first) {
	if (id == 1) {
		first = new Student(name, code, id);
		p = first;
		id++;
		return 0;
	}
	else {
		Student *n = 0;
		n = new Student(name, code, id);
		if (n != 0) {
			p->setNext(n);
			p = n;
			id++;
			return 0;
		}
		else {
			return -1;
		}
	}
}
int stdnt::AddStudent(std::string name, int code, int &id, Student * &p, Student * &first) {
	Student *n = 0;
	if (first != 0) {
		if (FindByCode(code, first, n) == 0) {
			return -1;
		}
		else {
			return Add(name, code, id, p, first);
		}
	}
	else {
		return Add(name, code, id, p, first);
	}
}
int stdnt::DeleteByID(Student * &first, int id) {
	Student *p = 0;
	if (id == 1) {
		p = first;
		first = first->getNext();
		delete p;
		return 0;
	}
	else {
		if (FindByID(id, first, p) == 0) {
			if (p->getNext() == 0) {
				Student *n = p;
				delete n;
				FindByID(id - 1, first, p);
				p->setNext(0);
				return 0;
			}
			else {
				FindByID(id - 1, first, p);
				Student *n = p->getNext();
				p->setNext(p->getNext()->getNext());
				delete n;
				return 0;
			}
		}
		else {
			return -1;
		}
	}
}
int stdnt::DeleteByCode(Student * &first, int code) {
	Student *p = 0;
	if (FindByCode(code, first, p) == 0) {
		return DeleteByID(first, p->getID());
	}
	else {
		return -1;
	}
}
int stdnt::FindByNameCount(std::string name, Student * first)
{
	int count = 0;
	bool t = true;
	Student *p = first;
	while (t)
	{
		if (p->getNext() != 0) {
			if (name.compare(p->getName())==0) {
				count++;
			}
			p = p->getNext();
		}
		else {
			if (name.compare(p->getName()) == 0) {
				count++;
			}
			t = false;
		}
	}
	return count;
}
int stdnt::FindByName(std::string name, Student * first, Student* &fn)
{ 
	int i = 0, n = FindByNameCount(name, first);
	Student* p = first;
	if (n != 0) {
		fn = new Student[n];
		bool t = true;
		while (t)
		{
			if (p->getNext()!=0) {
				if (name.compare(p->getName()) == 0) {
					fn[i].setCode(p->getCode()) ;
					fn[i].setID(p->getID());
					fn[i].setName(p->getName());
					i++;
				}
				p = p->getNext();
			}
			else {
				if (name.compare(p->getName()) == 0) {
					fn[i].setCode(p->getCode());
					fn[i].setID(p->getID());
					fn[i].setName(p->getName());
				}
				t = false;
			}
		}
	}
	return n;
}
void stdnt::RefactorID(Student* first) {
	bool t = true;
	int i = 1;
	Student *p = first;
	while (t) {
		if (p->getNext() != 0) {
			p->setID(i);
			p = p->getNext();
			i++;
		}
		else {
			p->setID(i);
			t = false;
		}
	}
}
void stdnt::Release(Student * &first)
{
	if (first != 0) {
		bool t = true;
		Student *n = 0;
		while (t)
		{
			if (first->getNext() != 0) {
				n = first;
				first = first->getNext();
				delete n;
			}
			else {
				delete first;
				t = false;
			}
		}
		first = 0;
	}
}
