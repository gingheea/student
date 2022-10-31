// ProjectSTUDENT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;
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
	static const int group_size = 5;
};
void Create(Student*& student)
{
	if (student == nullptr)
	{
		student = new Student;
	}

	if (student->name != nullptr)
	{
		delete[] student->name;
	}
	if (student->lastName != nullptr)
	{
		delete[] student->lastName;
	}
	if (student->bat != nullptr)
	{
		delete[] student->bat;
	}
	student->name = new char[Student::STR_SIZE] {};
	student->lastName = new char[Student::STR_SIZE] {};
	student->bat = new char[Student::STR_SIZE] {};
}

void Init(Student* student)
{
	if (student == nullptr)
	{
		return;
	}

	strcpy_s(student->name, Student::STR_SIZE, Student::name_dat[rand() % 5]);
	strcpy_s(student->lastName, Student::STR_SIZE, Student::lastName_dat[rand() % 5]);
	strcpy_s(student->bat, Student::STR_SIZE, Student::bat_dat[rand() % 5]);
	student->year =Student::year_dat[rand()%5];
	student->course = Student::course_dat[rand() % 5];
	student->num_group = Student::num_group_dat[rand() % 5];
	for (int i = 0; i < Student::MARKS_SIZE; i++)
	{
		student->marks[i] = rand()%12+3;
	}
}

void Print(Student* student)
{
	if (student == nullptr)
	{
		return;
	}
	cout << "------------------------------------" << endl;
	cout << student->lastName << "  " << student->name <<"  " << student->bat << endl;
	cout << " Birthday:  " << student->year << endl;
	cout << " Course:  " << student->course << endl;
	cout << " Nomer grypu:  " << student->num_group << endl;
	cout << " Marks = ";
	for (int i = 0; i < Student::MARKS_SIZE; i++)
	{
		cout << student->marks[i] << " ; ";
	}
	cout << endl;
	cout << "------------------------------------" << endl;
}
void CreateGroup(Group& group)
{
	

	group.group = new Student * [group.group_size] {};

	for (int i = 0; i < group.group_size; i++)
	{
		Create(group.group[i]);
	}
}

void InitGroup(const Group& group)
{
	for (int i = 0; i < group.group_size; i++)
	{
		Init(group.group[i]);
	}
}

void PrintGroup(const Group& group)
{
	for (int i = 0; i < group.group_size; i++)
	{
		Print(group.group[i]);
	}

}
void arg_marks(Student** student)
{
	
	double arg1 = 0;
	double arg2 = 0;
	double arg3 = 0;
	double arg4 = 0;
	double arg5 = 0;

	for(int i=0;i< Group::group_size;i++)
	{
		if (student[i]->num_group == Student::num_group_dat[0])
		{

			for (int j = 0; j < Student::MARKS_SIZE; j++)
			{
				arg1 = arg1+ student[i]->marks[j];
			}
		}
	}
	arg1 = arg1 / Student::MARKS_SIZE;
	if(arg1==0)
	{
		cout << "Nemaye studentiv z grypu 12";
		cout << endl << endl;
	}
	else
	{
		cout << "Seredniy bal grypu 12: " << arg1;
		cout << endl << endl;
	}


	for (int i = 0; i < Group::group_size; i++)
	{
		if (student[i]->num_group == Student::num_group_dat[1])
		{

			for (int j = 0; j < Student::MARKS_SIZE; j++)
			{
				arg2 = arg2 + student[i]->marks[j];
			}
		}
	}
	arg2 = arg2 / Student::MARKS_SIZE;
	if(arg2==0)
	{
		cout << "Nemaye studentiv z grypu 23";
		cout << endl << endl;
	}
	else
	{
		cout << "Seredniy bal grypu 23: " << arg2;
		cout << endl << endl;
	}
	for (int i = 0; i < Group::group_size; i++)
	{
		if (student[i]->num_group == Student::num_group_dat[2])
		{

			for (int j = 0; j < Student::MARKS_SIZE; j++)
			{
				arg3 = arg3 + student[i]->marks[j];
			}
		}
	}
	arg3= arg3 / Student::MARKS_SIZE;
	if (arg3 == 0)
	{
		cout << "Nemaye studentiv zgrypu 31";
		cout << endl << endl;
	}
	else
	{
		cout << "Seredniy bal grypu 31: " << arg3;
		cout << endl << endl;
	}

	for (int i = 0; i < Group::group_size; i++)
	{
		if (student[i]->num_group == Student::num_group_dat[3])
		{

			for (int j = 0; j < Student::MARKS_SIZE; j++)
			{
				arg4 = arg4 + student[i]->marks[j];
			}
		}
	}
	arg4 = arg4 / Student::MARKS_SIZE;
	if(arg4==0)
	{
		cout << "Nemaye studentiv grypu 11";
		cout << endl << endl;
	}
	else
	{
		cout << "Seredniy bal grypu 11: " << arg4;
		cout << endl << endl;
	}

	for (int i = 0; i < Group::group_size; i++)
	{
		if (student[i]->num_group == Student::num_group_dat[4])
		{

			for (int j = 0; j < Student::MARKS_SIZE; j++)
			{
				arg5 = arg5 + student[i]->marks[j];
			}
		}
	}
	arg5 = arg5 / Student::MARKS_SIZE;
	if(arg5==0)
	{
		cout << "Nemaye studentiv z grypu 4";
		cout << endl << endl;
	}
	else
	{
		cout << "Seredniy bal grypu 4: " << arg5;
		cout << endl << endl;
	}
}
void sort_course(Student**& student)
{
	int j = 0;
	Student* tmp = 0;
	for (int i = 0; i < Group::group_size; i++)
	{
		j = i;
		for (int k = i; k < Group::group_size; k++)
		{

			if (student[j]->course > student[k]->course)
			{
				j = k;
			}
			else if (student[j]->course == student[k]->course)
			{


				if (student[j]->lastName[0] > student[k]->lastName[0])
				{
					j = k;
				}


			}

		}
		tmp = student[i];
		student[i] = student[j];
		student[j] = tmp;
	}
}
int max_year_student(Student** student)
{
	int max = student[0]->year;
	int coursor = 0;
	int i = 0;
	for (i = 1; i < Group::group_size; i++)
	{
		if (max>student[i]->year)
		{
			max = student[i]->year;
			coursor = i;
		}
	}
	return coursor;
}
int min_year_student(Student** student)
{
	int min = student[0]->year;
	int coursor = 0;
	int i = 0;
	for (i = 1; i < Group::group_size; i++)
	{
		if (min < student[i]->year)
		{
			min = student[i]->year;
			coursor = i;
		}
	}
	return coursor;
}
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
