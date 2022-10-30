// ProjectSTUDENT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Student
{
	static const int DAT_SIZE = 5;
	static const int MARKS_SIZE = 5;
	static const int STR_SIZE = 256;
	static const char* name_dat[DAT_SIZE];
	static const char* lastName_dat[DAT_SIZE];
	static const char* bat_dat[DAT_SIZE];
	static const int year_dat[DAT_SIZE];
	static const int course_dat[DAT_SIZE];
	static const int num_group_dat[DAT_SIZE];
	char* name = nullptr;
	char* lastName = nullptr;
	char* bat = nullptr;
	int year;
	int course;
	int num_group;
	int marks[MARKS_SIZE]{};
};
const char* Student::name_dat[DAT_SIZE]{"Ivan","Sergiy","Dmutro","Sasha","Yura"};
const char* Student::lastName_dat[DAT_SIZE]{ "Sternenko","Kostenko","Dmutrenko","Yuliychenko","Yurenko" };
const char* Student::bat_dat[DAT_SIZE]{ "Ivanovuch","Sergiyovuch","Dmutrovuch","Oleksandrovuch","Yuriyevuch" };
const int Student::year_dat[DAT_SIZE]{1995,1996,1997,1998,1999};
const int Student::course_dat[DAT_SIZE]{ 1,2,3,4,5 };
const int Student::num_group_dat[DAT_SIZE]{ 12,23,31,11,4 };
struct Group
{
	Student** group = nullptr;
	int gruop_size = 0;
};
int main()
{
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
