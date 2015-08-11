#include <iostream>
#include "Student.h"
#include "StudentConsole.h"
#include "StudentFile.h"
int main() {
	std::string name="";
	int code = 0;
	int id = 1;
	Student *first = 0, *p = 0;
	bool t1 = true;
	StudentFile file;
	while (t1)
	{
		int c1;
		Menu_console(c1);
		switch (c1)
		{
		case 1:
			AddStudent_console(name, code, id, p, first);
			break;
		case 2:
			PrintList_console(first);
			break;
		case 3:
			Find_console(first);
			break;
		case 4:
			Edit_console(first);
			break;
		case 5:
			DeleteStudent_console(first, id);
			break;
		case  6:
			file.CreateFile();
			file.WriteFile(first);
			file.CloseFile();
			break;
		case 7:
			if (file.OpenFile()) {
				file.ImportFromFile(first, p, id);
				file.CloseFile();
			}
			else {
				std::cout << "Error: Cannot open file!" << std::endl;
			}
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