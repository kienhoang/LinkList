#include <iostream>
#include "Student.h"

void Menu_console(int &c) {
	std::cout << "===========MENU==============" << std::endl << std::endl;
	std::cout << "  1. Add a student to list" << std::endl;
	std::cout << "  2. View list" << std::endl;
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
void AddStudent(std::string name, int code, int &i, Student * &p) {
	Student *n = 0;
	n = new Student(name, code, i);
	p->setNext(n);
	p = n;
	i++;
}

int main() {
	std::string name="";
	int code = 0 , i = 1 ,c = 0;
	Student *first = 0, *p = 0, *n = 0;
	Input_console(name, code, i);
	first = new Student(name, code, i);
	i++;
	p = first;
	bool t = true;
	while (t)
	{
		Menu_console(c);
		switch (c)
		{
		case 1:
			Input_console(name, code, i);
			AddStudent(name, code, i, p);
			break;
		case 2:
			PrintList_console(first);
			break;
		case 0:
			t = false;
			break;
		default:
			std::cout << "You have entered an invalid option. Please choice again." << std::endl;
			break;
		}
	}
	return 0;
}