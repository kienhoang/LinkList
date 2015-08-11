#include "StudentConsole.h"
#include "StringProcess.h"

void wait() {
	std::cout << "Press Enter to continue. . .";
	getchar();
}
void printStudent(Student *p) {
	std::cout << "ID=" << p->getID() << " | Code=" << p->getCode() << " | Name='";
	if (p->getName().compare("") == 0) {
		std::cout << "<Empty Name>" << std::endl;
	}
	else {
		std::cout << p->getName() << std::endl;
	}
}
void printStudent(Student p) {
	std::cout << "ID=" << p.getID() << " | Code=" << p.getCode() << " | Name=";
	if (p.getName().compare("") == 0) {
		std::cout << "<Empty Name>" << std::endl;
	}
	else {
		std::cout << "'" << p.getName() << "'" << std::endl;
	}
}
void Menu_console(int &c) {
	std::cout << "============MENU==============" << std::endl << std::endl;
	std::cout << "  1. Add a student to list" << std::endl;
	std::cout << "  2. View student list" << std::endl;
	std::cout << "  3. Find Student ->" << std::endl;
	std::cout << "  4. Edit Student Infomation ->" << std::endl;
	std::cout << "  5. Delete a Student ->" << std::endl;
	std::cout << "  6. Save List to file" << std::endl;
	std::cout << "  7. Import Data from file" << std::endl;
	std::cout << "  0. Exit" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
	std::cin >> c;
	std::cin.ignore(1);
}
void MenuDelete_console(int &c) {
	std::cout << "====== Delete a student ======" << std::endl << std::endl;
	std::cout << "  1. Delete By Name" << std::endl;
	std::cout << "  2. Delete By Code" << std::endl;
	std::cout << "  3. Delete By ID (be carefully)" << std::endl;
	std::cout << "  0. Back to main Menu" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
	std::cin >> c;
	std::cin.ignore(1);
}
void MenuEdit_console(int &c) {
	std::cout << "===Edit Student Infomation====" << std::endl << std::endl;
	std::cout << "  1. Edit Name By ID" << std::endl;
	std::cout << "  2. Edit Name By Code" << std::endl;
	std::cout << "  0. Back to main Menu" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
	std::cin >> c;
	std::cin.ignore(1);
}
void MenuFind_console(int &c) {
	std::cout << "=========Find Student=========" << std::endl << std::endl;
	std::cout << "  1. Find By Name" << std::endl;
	std::cout << "  2. Find By Code" << std::endl;
	std::cout << "  3. Find By ID" << std::endl;
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
	NameProcess(name);
	std::cout << "     Code: ";
	std::cin >> code;
	std::cin.ignore(1);
}
void PrintList_console(Student* first) {
	if (first != 0) {
		Student *p = first;
		bool t = true;
		std::cout << "=========Student List=========" << std::endl;
		while (t)
		{
			if (p->getNext() != 0) {
				std::cout << p->getID() << " | " << p->getCode() << " | ";
				if (p->getName().compare("") == 0) {
					std::cout << "<empty name>" << std::endl;
				}
				else {
					std::cout << p->getName() << std::endl;
				}
				p = p->getNext();
			}
			else {
				std::cout << p->getID() << " | " << p->getCode() << " | ";
				if (p->getName().compare("") == 0) {
					std::cout << "<empty name>" << std::endl;
				}
				else {
					std::cout << p->getName() << std::endl;
				}
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
void DelStudentByCode_console(Student * &first) {
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
void DelStudentByName_console(Student * &first) {
	std::string name;
	std::cout << "Enter Name of Student to delete: ";
	std::getline(std::cin, name);
	NameProcess(name);
	Student * fn = 0;
	int n = FindByName(name, first, fn);
	if (n != 0) {
		std::cout << "Result of " << name << " :" << std::endl;
		for (int i = 0; i < n; i++) {
			printStudent(fn[i]);
		}
		std::cout << "Which ID of Student that you want to delete (0 to cancel): ";
		int c = 0;
		std::cin >> c;
		std::cin.ignore(1);
		bool t = false;
		if (c != 0) {
			for (int i = 0; i < n; i++) {
				if (c == fn[i].getID()) {
					t = true;
				}
			}
			if (t) {
				DeleteByID(first, c);
				delete[] fn;
			}
			else {
				std::cout << "Error: Invalid ID" << std::endl;
				wait();
			}
		}
		else {
			std::cout << "Cancel." << std::endl;
		}
	}
	else {
		std::cout << "Error: Invalid Student's Name." << std::endl;
		wait();
	}
}
void AddStudent_console(std::string name, int code, int &id, Student * &p, Student * &first) {
	Input_console(name, code, id);
	if (AddStudent(name, code, id, p, first) == -1) {
		std::cout << "Error: You have enter a Student existed code" << std::endl;
		wait();
	}
	else {
		std::cout << "Success." << std::endl;
	}
}
void FindName_console(Student * first) {
	std::string name;
	std::cout << "Enter Name of Student to search: ";
	std::getline(std::cin, name);
	NameProcess(name);
	Student * fn = 0;
	int n = FindByName(name, first, fn);
	if (n != 0) {
		std::cout << "Result of " << name << " :" << std::endl;
		for (int i = 0; i < n; i++) {
			printStudent(fn[i]);
		}
		delete[] fn;
		wait();
	}
	else {
		std::cout << "Not found Student name: " << name << std::endl;
		wait();
	}
}
void FindID_console(Student *first) {
	int id = 0;
	Student *p = 0;
	std::cout << "Input ID of Student to search: ";
	std::cin >> id;
	std::cin.ignore(1);
	if (FindByID(id, first, p) == 0) {
		std::cout << "Result of ID=" << id << " :" << std::endl;
		printStudent(p);
		wait();
	}
	else {
		std::cout << "Error: ID not found." << std::endl;
		wait();
	}
}
void FindCode_console(Student *first) {
	int code = 0;
	Student *p = 0;
	std::cout << "Input Code of Student to search: ";
	std::cin >> code;
	std::cin.ignore(1);
	if (FindByCode(code, first, p) == 0) {
		std::cout << "Result of Code=" << code << " :" << std::endl;
		printStudent(p);
		wait();
	}
	else {
		std::cout << "Error: Code not found." << std::endl;
		wait();
	}
}
void EditNameByID_console(Student * first)
{
	int id = 0;
	std::string name = "";
	Student *p = 0;
	std::cout << "Enter Student' ID for Edit name: ";
	std::cin >> id;
	std::cin.ignore(1);
	if (FindByID(id, first, p) == 0) {
		std::cout << "Enter New Name of 'ID=" << p->getID() << " | Name='";
		if (p->getName().compare("") == 0) {
			std::cout << "<empty name>";
		}
		else {
			std::cout << p->getName();
		}
		std::cout << "` | Code=" << p->getCode() << "' : ";
		std::getline(std::cin, name);
		NameProcess(name);
		p->setName(name);
		std::cout << "Done." << std::endl;
	}
	else {
		std::cout << "ID not found." << std::endl;
		wait();
	}
}
void DeleteStudent_console(Student * &first, int &id) {
	if (first != 0) {
		int c2;
		MenuDelete_console(c2);
		switch (c2)
		{
		case 1:
			DelStudentByName_console(first);
			id--;
			if (first != 0) {
				RefactorID(first);
			}
			break;
		case 2:
			DelStudentByCode_console(first);
			id--;
			if (first != 0) {
				RefactorID(first);
			}
			break;
		case 3:
			DelStudentByID_console(first);
			id--;
			if (first != 0) {
				RefactorID(first);
			}
		case 0:
			break;
		default:
			std::cout << "Error: You have entered an invalid option. Please choice again." << std::endl;
			wait();
			break;
		}
	}
	else {
		std::cout << "Error: You do not have any Student to delete." << std::endl;
		wait();
	}
}
void Edit_console(Student *first) {
	if (first != 0) {
		int c = 0;
		MenuEdit_console(c);
		switch (c)
		{
		case 1:
			EditNameByID_console(first);
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
		std::cout << "Error: You do not have any Student to edit." << std::endl;
		wait();
	}
}
void Find_console(Student *first) {
	if (first != 0) {
		int c;
		MenuFind_console(c);
		switch (c)
		{
		case 1:
			FindName_console(first);
			break;
		case 2:
			FindCode_console(first);
			break;
		case 3:
			FindID_console(first);
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
		std::cout << "Error: You do not have any Student to find." << std::endl;
		wait();
	}
}
