#ifndef _2021013445_13_01_STUDENT_HPP_
#define _2021013445_13_01_STUDENT_HPP_
#include <iostream>
#include <string>
using namespace std;
class Students
{
public:
	Students(string StuName = "Unknown", unsigned int StuIDnum = 0, float StuGrade = 0.0);
	Students& operator=(const Students& Student);
	friend istream& operator>>(istream& Input, Students& Student);
	friend ostream& operator<<(ostream& Output, const Students& Student);
	bool operator>(const Students& Student)const;
private:
	string Name;
	unsigned int IDnum;
	float Grade;
};
#endif