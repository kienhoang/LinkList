#include <iostream>
#include "Student.h"

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

int main() {
	std::string name;
	int code;
	Input_console(name, code,1);
	std::cout << "Name: " << name << "\nCode: " << code;
	getchar();
	return 0;
}