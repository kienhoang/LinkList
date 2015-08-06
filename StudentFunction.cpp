#include "Student.h"
#include "StudentFunction.h"
#include<iostream>

int FindByID(int id, Student *first, Student * &p) {
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
int FindByCode(int code, Student *first, Student * &p) {
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
int Add(std::string name, int code, int &i, Student * &p, Student * &first) {
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
int AddStudent(std::string name, int code, int &i, Student * &p, Student * &first) {
	Student *n = 0;
	if (first != 0) {
		if (FindByCode(code, first, n) == 0) {
			return -1;
		}
		else {
			Add(name, code, i, p, first);
			return 0;
		}
	}
	else {
		Add(name, code, i, p, first);
		return 0;
	}
}
int DeleteByID(Student * &first, int id) {
	Student *p = 0;
	if (id == 1) {
		p = first;
		first = first->getNext();
		delete p;
		return 0;
	}
	else {
		int t = FindByID(id, first, p);
		if (t == 0) {
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
int DeleteByCode(Student * &first, int code) {
	Student *p = 0;
	FindByCode(code, first, p);
	return DeleteByID(first, p->getID());
}
void RefactorID(Student* first) {
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

void wait() {
	std::cout << "Press Enter to continue. . ." << std::endl;
	getchar();
}
void Menu_console(int &c) {
	std::cout << "============MENU==============" << std::endl << std::endl;
	std::cout << "  1. Add a student to list" << std::endl;
	std::cout << "  2. View student list" << std::endl;
	std::cout << "  3. Delete a Student ->" << std::endl;
	std::cout << "  0. Exit" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
	std::cin >> c;
	std::cin.ignore(1);
}
void MenuDelete_console(int &c) {
	std::cout << "====== Delete a student ======" << std::endl << std::endl;
	std::cout << "  1. Delete By Code" << std::endl;
	std::cout << "  2. Delete By ID (be carefully)" << std::endl;
	std::cout << "  0. Back to main Menu" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
	std::cin >> c;
	std::cin.ignore(1);
}
void Input_console(std::string &name, int &code, int id) {
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
	std::cout << "     Code: ";
	std::cin >> code;
	std::cin.ignore(1);
}
void PrintList_console(Student* first) {
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
void DelStudentByID_console(Student * &first) {
	int id;
	std::cout << "Enter Student ID to Delete: ";
	std::cin >> id;
	std::cin.ignore(1);
	if (DeleteByID(first, id) == -1) {
		std::cout << "You have entered an invalid ID" << std::endl;
		wait();
	}
}
void DelStudentByCode_console(Student * &first) {
	int code;
	std::cout << "Enter Student Code to Delete: ";
	std::cin >> code;
	std::cin.ignore(1);
	if (DeleteByCode(first, code) == -1) {
		std::cout << "You have entered an invalid ID" << std::endl;
		wait();
	}
}
void AddStudent_console(std::string name, int code, int &i, Student * &p, Student * &first) {
	if (AddStudent(name, code, i, p, first) == -1) {
		std::cout << "Error: You have enter a Student existed code" << std::endl;
		wait();
	}
	else {
		std::cout << "Success." << std::endl;
	}
}
void DeleteStudent_console(Student * &first, int &i) {
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