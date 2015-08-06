#include <iostream>
#include "Student.h"

int AddStudent(std::string name, int code, int &i, Student * &p , Student * &first) {
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
int DeleteStudent(Student * &first, int id) {
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
	std::cout << "===========MENU==============" << std::endl << std::endl;
	std::cout << "  1. Add a student to list" << std::endl;
	std::cout << "  2. View list" << std::endl;
	std::cout << "  3. Delete a Student By ID (Be Carefully)" << std::endl;
	std::cout << "  0. Exit" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
	std::cin >> c;
	std::cin.ignore(1);
}
void Input_console(std::string &name, int &code, int id) {
	std::cout << "Input information for the " << id;
	if (id < 10 || id > 20) {
		switch (id%10)
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
void DelStudent_console(Student * &first) {
	int id;
	std::cout << "Enter Student ID to Delete: ";
	std::cin >> id;
	std::cin.ignore(1);
	if (DeleteStudent(first, id) == -1) {
		std::cout << "You have entered an invalid ID" << std::endl;
		wait();
	}
}

int main() {
	std::string name="";
	int code = 0 , i = 1 ,c = 0;
	Student *first = 0, *p = 0;
	bool t = true;
	while (t)
	{
		Menu_console(c);
		switch (c)
		{
		case 1:
			Input_console(name, code, i);
			AddStudent(name, code, i, p , first);
			break;
		case 2:
			if (first == 0) {
				std::cout << "<List is empty>" << std::endl;
			}
			else {
				PrintList_console(first);
			}
			wait();
			break;
		case 3:
			if (first != 0) {
				DelStudent_console(first);
				i--;
			}
			if (first != 0) { 
				RefactorID(first);
			}
			break;
		case 0:
			t = false;
			break;
		default:
			std::cout << "You have entered an invalid option. Please choice again." << std::endl;
			wait();
			break;
		}
	}
	return 0;
}