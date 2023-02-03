#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(int argc, char* argv[])
{
	string Input;
	getline(cin, Input);
	char Unknown = 0;
	int Count = 0;
	int Temp = 0;
	int Front = 0;//系数
	int Times = 1;//乘10的次数
	int Divice = 0;//解的数
	int Flag = 0;//等号检查器
	int IsUnknownSingle = 0;
	for (int i = Input.size() - 1; i >= 0; i--)
	{
		if (i != (Input.size() - 1) && Input[i + 1] == '=')
		{
		    Flag = 1;
		}
		if (Input[i] > 61)//不为数字或者加减号、等号
		{
			Unknown = Input[i];
			i -= 1;
			if (i == -1 || Input[i] == '=' || Input[i] == '+' || Input[i] == '-')
			{
				if (i == -1)
				{
					Front += 1;
					break;
				}
				else if (Input[i] == '-')
				{
					if (Flag == 0)
					{
						Front += 1;
						continue;
					}
					else
					{
						Front -= 1;
						continue;
					}
				}
				else
				{
					if (Flag == 0)
					{
						Front -= 1;
						continue;
					}
					else
					{
						Front += 1;
						continue;
					}
				}
			}
			for (int j = i; j >= 0 && Input[j] != '+' && Input[j] != '-' && Input[j] != '='; j--)
			{
				Temp += (Input[j] - 48) * Times;
				Times *= 10;
				Count++;
			}
			i -= Count;
			if (Flag == 1)
			{
				if (i >= 0 && Input[i] == '-')
				{
					Temp = ~Temp + 1;
					Front += Temp;
					Temp = 0;
				}
				else
				{
					Front += Temp;
					Temp = 0;
				}
				Times = 1;
				Count = 0;
			}
			else
			{
				if (Input[i] != '-')
				{
					Temp = ~Temp + 1;
					Front += Temp;
					Temp = 0;
				}
				else
				{
					Front += Temp;
					Temp = 0;
				}
				Times = 1;
				Count = 0;
			}
		}
		else if (Input[i] >= '0' && Input[i] <= '9')
		{
			for (int j = i; j >= 0 && Input[j] != '+' && Input[j] != '-' && Input[j] != '='; j--)
			{
				if (j == -1)
				{
					break;
				}
				Temp += (Input[j] - 48) * Times;
				Times *= 10;
				Count++;
			}
			i -= Count;
			if (Flag == 0)
			{
				if (Input[i] == '-')
				{
					Temp = ~Temp + 1;
					Divice += Temp;
					Temp = 0;
				}
				else
				{
					Divice += Temp;
					Temp = 0;
				}
				Times = 1;
				Count = 0;
			}
			else
			{
				if (i >= 0 && Input[i] != '-')
				{
					Temp = ~Temp + 1;
					Divice += Temp;
					Temp = 0;
				}
				else if (i >= 0 && Input[i] == '-')
				{
					Divice += Temp;
					Temp = 0;
				}
				else
				{
					Temp = ~Temp + 1;
					Divice += Temp;
					Temp = 0;
				}
				Times = 1;
				Count = 0;
			}
		}
	}
	float Result = static_cast<float> (Divice) / static_cast<float>(Front);
	if (Front < 0 && Divice == 0)
	{
		Result = -Result;
	}
	cout << Unknown << '=' << setiosflags(ios::fixed) << setprecision(3) << Result << endl;
	return 0;
}