#include "Student.h"

Student::Student(std::string name, int code,int id)
{
	name_ = name;
	code_ = code;
	id_ = id;
	next_ = 0;
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

void FindName::setID(int id) {
	id_ = id;
}
int FindName::getID() {
	return id_;
}
void FindName::setCode(int code) {
	code_ = code;
}
int FindName::getCode() {
	return code_;
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
int stdnt::Add(std::string name, int code, int &i, Student * &p, Student * &first) {
	if (i == 1) {
		first = new Student(name, code, i);
		p = first;
		i++;
		return 0;
	}
	else {
		Student *n = 0;
		n = new Student(name, code, i);
		if (n != 0) {
			p->setNext(n);
			p = n;
			i++;
			return 0;
		}
		else {
			std::cout << "Cannot access Memory. Check Your Memory" << std::endl;
			return -1;
		}
	}
}
int stdnt::AddStudent(std::string name, int code, int &i, Student * &p, Student * &first) {
	Student *n = 0;
	if (first != 0) {
		if (FindByCode(code, first, n) == 0) {
			return -1;
		}
		else {
			return Add(name, code, i, p, first);
		}
	}
	else {
		return Add(name, code, i, p, first);
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
int stdnt::FindByName(std::string name, Student * first, FindName* &fn)
{ 
	int i = 0, n = FindByNameCount(name, first);
	Student* p = first;
	if (n != 0) {
		fn = new FindName[n];
		bool t = true;
		while (t)
		{
			if (p->getNext()!=0) {
				if (name.compare(p->getName()) == 0) {
					fn[i].setCode(p->getCode()) ;
					fn[i].setID(p->getID());
					i++;
				}
				p = p->getNext();
			}
			else {
				fn[i].setCode(p->getCode());
				fn[i].setID(p->getID());
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
	}
}

void stdnt::wait() {
	std::cout << "Press Enter to continue. . ." << std::endl;
	getchar();
}
void stdnt::Menu_console(int &c) {
	std::cout << "============MENU==============" << std::endl << std::endl;
	std::cout << "  1. Add a student to list" << std::endl;
	std::cout << "  2. View student list" << std::endl;
	std::cout << "  3. Delete a Student ->" << std::endl;
	std::cout << "  4. Find Student by Name" << std::endl;
	std::cout << "  0. Exit" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
	std::cin >> c;
	std::cin.ignore(1);
}
void stdnt::MenuDelete_console(int &c) {
	std::cout << "====== Delete a student ======" << std::endl << std::endl;
	std::cout << "  1. Delete By Code" << std::endl;
	std::cout << "  2. Delete By ID (be carefully)" << std::endl;
	std::cout << "  0. Back to main Menu" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
	std::cin >> c;
	std::cin.ignore(1);
}
void stdnt::Input_console(std::string &name, int &code, int id) {
	std::cout << "Input information for the " << id;
	if (id < 10 || id > 20) {
		switch (id % 10)
		{
		case 1:
			std::cout << "st";
			break;
		case 2:
			std::cout << "nd";
			break;
		case 3:
			std::cout << "rd";
			break;
		default:
			std::cout << "th";
			break;
		}
	}
	else {
		std::cout << "th";
	}
	std::cout << " student:\n";
	std::cout << "     Name: ";
	std::getline(std::cin, name);
	NameProcess(name);
	std::cout << "     Code: ";
	std::cin >> code;
	std::cin.ignore(1);
}
void stdnt::PrintList_console(Student* first) {
	if (first != 0) {
		Student *p = first;
		bool t = true;
		while (t)
		{
			if (p->getNext() != 0) {
				std::cout << p->getID() << " " << p->getCode() << " " << p->getName() << std::endl;
				p = p->getNext();
			}
			else {
				std::cout << p->getID() << " " << p->getCode() << " " << p->getName() << std::endl;
				t = false;
			}
		}
	}
	else {
		std::cout << "<List is empty>" << std::endl;
	}
	wait();
}
void stdnt::DelStudentByID_console(Student * &first) {
	int id;
	Student *n = 0;
	std::cout << "Enter Student ID to Delete: ";
	std::cin >> id;
	std::cin.ignore(1);
	std::string tmp_name;
	int tmp_code;
	if (FindByID(id, first, n) == 0) {
		tmp_name = n->getName();
		tmp_code = n->getCode();
	}
	if (DeleteByID(first, id) == -1) {
		std::cout << "You have entered an invalid ID" << std::endl;
		wait();
	}
	else {
		std::cout << "Deleted: Name='" << tmp_name << "' Code=" << tmp_code << std::endl;
		std::cout << "Done." << std::endl;
	}
}
void stdnt::DelStudentByCode_console(Student * &first) {
	int code;
	std::cout << "Enter Student Code to Delete: ";
	std::cin >> code;
	std::cin.ignore(1);
	Student *n = 0;
	std::string tmp_name;
	int tmp_code;
	if (FindByCode(code, first, n) == 0) {
		tmp_name = n->getName();
		tmp_code = n->getCode();
	}
	if (DeleteByCode(first, code) == -1) {
		std::cout << "You have entered an invalid Code" << std::endl;
		wait();
	}
	else {
		std::cout << "Deleted: Name='" << tmp_name << "' Code=" << tmp_code << std::endl;
		std::cout << "Done." << std::endl;
	}
}
void stdnt::AddStudent_console(std::string name, int code, int &i, Student * &p, Student * &first) {
	Input_console(name, code, i);
	if (AddStudent(name, code, i, p, first) == -1) {
		std::cout << "Error: You have enter a Student existed code" << std::endl;
		wait();
	}
	else {
		std::cout << "Success." << std::endl;
	}
}
void stdnt::DeleteStudent_console(Student * &first, int &i) {
	if (first != 0) {
		int c2;
		MenuDelete_console(c2);
		switch (c2)
		{
		case 1:
			DelStudentByCode_console(first);
			i--;
			if (first != 0) {
				RefactorID(first);
			}
			break;
		case 2:
			DelStudentByID_console(first);
			i--;
			if (first != 0) {
				RefactorID(first);
			}
			break;
		case 0:
			break;
		default:
			std::cout << "Error: You have entered an invalid option. Please choice again." << std::endl;
			wait();
			break;
		}
	}
	else {
		std::cout << "Error: You do not have a Student to delete." << std::endl;
		wait();
	}
}
void stdnt::FindName_console(Student * first)
{
	if (first != 0) {
		std::string name;
		std::cout << "Enter Name of Student to search: ";
		std::getline(std::cin, name);
		NameProcess(name);
		FindName * fn;
		int n = FindByName(name, first, fn);
		if (n != 0) {
			std::cout << "Result of " << name << " :" << std::endl;
			for (int i = 0; i < n; i++) {
				std::cout << "ID=" << fn[i].getID() << " Code=" << fn[i].getCode() << std::endl;
			}
		}
		else {
			std::cout << "Not found Student name: " << name << std::endl;
			wait();
		}
	}
	else {
		std::cout << "Error: You do not have a Student to delete." << std::endl;
		wait();
	}
}
