#include <iostream>
#include "2021013445_13_01_Student.hpp"
#include <string>
using namespace std;
Students:: Students(string StuName, unsigned int StuIDnum, float StuGrade)
{
	Name = StuName;
	IDnum = StuIDnum;
	Grade = StuGrade;
}
Students& Students::operator=(const Students& Student)
{
	Name = Student.Name;
	IDnum = Student.IDnum;
	Grade = Student.Grade;
	return *this;
}
istream& operator>>(istream& Input, Students& Student)
{
	Input >> Student.Name >> Student.IDnum >> Student.Grade;
	return Input;
}
ostream& operator<<(ostream& Output, const Students& Student)
{
	Output << Student.Name << ',' << Student.IDnum << ',' << Student.Grade << '\n';
	return Output;
}
bool Students::operator>(const Students& Student)const
{
	if (Grade > Student.Grade)
	{
		return true;
	}
	else if (Grade == Student.Grade && IDnum < Student.IDnum)
	{
		return true;
	}
	else
	{
		return false;
	}
}