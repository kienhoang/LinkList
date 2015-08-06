#pragma once

int FindByID(int id, Student *first, Student * &p);
int FindByCode(int code, Student *first, Student * &p);
int Add(std::string name, int code, int &i, Student * &p, Student * &first);
int AddStudent(std::string name, int code, int &i, Student * &p, Student * &first);
int DeleteByID(Student * &first, int id);
int DeleteByCode(Student * &first, int code);
void RefactorID(Student* first);

void wait();
void Menu_console(int &c);
void MenuDelete_console(int &c);
void Input_console(std::string &name, int &code, int id);
void PrintList_console(Student* first);
void DelStudentByID_console(Student * &first);
void DelStudentByCode_console(Student * &first);
void AddStudent_console(std::string name, int code, int &i, Student * &p, Student * &first);
void DeleteStudent_console(Student * &first, int &i);