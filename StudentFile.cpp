#include "StudentFile.h"

bool StudentFile::CreateFile()
{
	std::string name;
	std::cout << "Input file name: ";
	std::getline(std::cin, name);
	f.open(name, std::ios::out);
	if (f.fail()) {
		return false;
	}
	else {
		return true;
	}
}
bool StudentFile::OpenFile(){
	std::string name;
	std::cout << "Input file name: ";
	std::getline(std::cin, name);
	f.open(name, std::ios::in);
	if (f.fail()) {
		return false;
	}
	else {
		return true;
	}
}
bool StudentFile::WriteFile(Student * first){
	if (first != 0) {
		Student *p = first;
		bool t = true;
		while (t)
		{
			if (p->getNext() != 0) {
				f << p->getCode() << std::endl;
				if (p->getName().compare("") == 0) {
					f << "<empty name>" << std::endl;
				}
				else {
					f << p->getName() << std::endl;
				}
				p = p->getNext();
			}
			else {
				f << p->getCode() << std::endl;
				if (p->getName().compare("") == 0) {
					f << "<empty name>" << std::endl;
				}
				else {
					f << p->getName() << std::endl;
				}
				t = false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
bool StudentFile::ReadFile(int & code, std::string & name){
	std::string scode;
	if (std::getline(f, scode)) {
		code = StringToInt(scode);
		std::getline(f, name);
		if (name == "<empty name>") {
			name = "";
		}
		return true;
	}
	else {
		return false;
	}
}
void StudentFile::ImportFromFile(Student * &first,Student * &p, int &id) {
	stdnt::Release(first);
	id = 1;
	p = 0;
	int code = 0;
	std::string name = "";
	while (ReadFile(code, name)) {
		stdnt::AddStudent(name, code, id, p, first);
	}
}
void StudentFile::CloseFile(){
	f.close();
}
