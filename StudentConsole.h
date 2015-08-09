#pragma once
#include <string>
#include <iostream>
#include "Student.h"

using namespace stdnt;

void wait();
void printStudent(Student *p);
void printStudent(Student p);
void Menu_console(int &c);
void MenuDelete_console(int &c);
void MenuEdit_console(int &c);
void MenuFind_console(int &c);
void Input_console(std::string &name, int &code, int id);
void PrintList_console(Student* first);
void DelStudentByID_console(Student * &first);
void DelStudentByCode_console(Student * &first);
void DelStudentByName_console(Student * &first);
void AddStudent_console(std::string name, int code, int &id, Student * &p, Student * &first);
void FindName_console(Student* first);
void FindID_console(Student *first);
void FindCode_console(Student *first);
void EditNameByID_console(Student *first);
void DeleteStudent_console(Student * &first, int &id);
void Edit_console(Student *first);
void Find_console(Student *first);