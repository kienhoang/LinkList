#include <iostream>
#include "Student.h"

using namespace stdnt;

int main() {
	std::string name="";
	int code = 0;
	int i = 1;
	Student *first = 0, *p = 0;
	bool t1 = true;
	while (t1)
	{
		int c1;
		Menu_console(c1);
		switch (c1)
		{
		case 1:
			Input_console(name, code, i);
			AddStudent_console(name, code, i, p, first);
			break;
		case 2:
			PrintList_console(first);
			break;
		case 3:
			DeleteStudent_console(first, i);
			break;
		case 0:
			Release(first);
			t1 = false;
			break;
		default:
			std::cout << "Error: You have entered an invalid option. Please choice again." << std::endl;
			wait();
			break;
		}
	}
	return 0;
}