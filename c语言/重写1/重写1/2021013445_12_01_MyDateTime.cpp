#include <iostream>
#include "2021013445_12_01_MyDateTime.hpp"
using namespace std;
MyDateTime::MyDateTime(unsigned int Year, unsigned int Month, unsigned int Date, unsigned int Hour, unsigned int Minute, unsigned int Second)
{
	if (SetDateTime(Year, Month, Date, Hour, Minute, Second))
	{
		this->Year = Year;
		this->Month = Month;
		this->Date = Date;
		this->Hour = Hour;
		this->Minute = Minute;
		this->Second = Second;
	}
	else
	{
		this->Year = 1999;
		this->Month = 1;
		this->Date = 1;
		this->Hour = 0;
		this->Minute = 0;
		this->Second = 0;
	}
}
MyDateTime::MyDateTime(const MyDateTime& Source)
{
	Year = Source.Year;
	Month = Source.Month;
	Date = Source.Date;
	Hour = Source.Hour;
	Minute = Source.Minute;
	Second = Source.Second;
}
bool MyDateTime::SetDateTime(unsigned int Year, unsigned int Month, unsigned int Date, unsigned int Hour, unsigned int Minute, unsigned int Second)
{
	if (Year >= 0 && Year <= 9999)
	{
		if (Month >= 1 && Month <= 12)
		{
			if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
			{
				if (Date >= 1 && Date <= 31)
				{
					if (Hour >= 0 && Hour <= 23 && Minute >= 0 && Minute <= 59 && Second >= 0 && Second <= 59)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else if (Month == 2)
			{
				if ((Year % 400) == 0 || ((Year % 4) == 0 && (Year % 100) != 0))
				{
					if (Date >= 1 && Date <= 29)
					{
						if (Hour >= 0 && Hour <= 23 && Minute >= 0 && Minute <= 59 && Second >= 0 && Second <= 59)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					if (Date >= 1 && Date <= 28)
					{
						if (Hour >= 0 && Hour <= 23 && Minute >= 0 && Minute <= 59 && Second >= 0 && Second <= 59)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
			}
			else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
			{
				if (Date >= 1 && Date <= 30)
				{
					if (Hour >= 0 && Hour <= 23 && Minute >= 0 && Minute <= 59 && Second >= 0 && Second <= 59)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
