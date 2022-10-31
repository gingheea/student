// ProjectSTUDENT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Group group;
	CreateGroup(group);
	InitGroup(group);
	cout << "Ne sortovanuy: " << endl << endl;
	PrintGroup(group);
	sort_course(group.group);
	cout << "__________________________________________________________"<<endl;
	cout << "Sortovanuy: " << endl << endl;
	PrintGroup(group);
	cout << "__________________________________________________________" << endl;
	arg_marks(group.group);
	cout << endl << endl;
	cout << "Naystarh(uy)(i) student(u): ";
	Print(group.group[max_year_student(group.group)]);
	for(int i=0;i< Group::group_size;i++)
	{
		if(group.group[i]->year == group.group[max_year_student(group.group)]->year)
		{
			Print(group.group[i]);
			cout << endl << endl;
		}
	}
	cout << endl << endl;
	cout << "Naymolodsh(uy)(i) student(u): ";
	Print(group.group[min_year_student(group.group)]);
	cout << endl << endl;
	for (int i = 0; i < Group::group_size; i++)
	{
		if (group.group[i]->year == group.group[min_year_student(group.group)]->year)
		{
			Print(group.group[i]);
			cout << endl << endl;
		}
	}
	cout << "__________________________________________________________" << endl;
	the_best_student(group.group);
	cout << endl << endl;
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
