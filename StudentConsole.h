#pragma once
#include <string>
#include <iostream>
#include "Student.h"

using namespace stdnt;

void wait();
void Menu_console(int &c);
void MenuDelete_console(int &c);
void MenuEdit_console(int &c);
void Input_console(std::string &name, int &code, int id);
void PrintList_console(Student* first);
void DelStudentByID_console(Student * &first);
void DelStudentByCode_console(Student * &first);
void AddStudent_console(std::string name, int code, int &i, Student * &p, Student * &first);
void DeleteStudent_console(Student * &first, int &i);
void FindName_console(Student* first);
void EditNameByID_console(Student *first);
void Edit_console(Student *first);