#include <stdio.h>
#include "help.h"
#include <string.h>
int myAtoi(char* string)
{
	char temp = '\0';
	int countspace = 0;
	int count0 = 0;
	int countnumber = 0;
	int returnnumber = 0;
	char max[11] = "2147483647";
	//以下最小值是正数的原因是由于在后续程序中将input的负号去掉处理，事实上应该是-2147483648
	char min[11] = "2147483648";
	//删除空格的操作
	for (int i = 0; i < 200; i++)
	{
		temp = getchar();
		countspace++;
		if (temp != ' ')
		{
			break;
		}
	}
	//检查是不是读到了负号
	if (temp == '-')
	{
		for (int i = 0; i < 200 - countspace; i++)
		{
			temp = getchar();
			if (temp < 48 || temp > 57)
			{
				printf("-");
				for (int j = 0; j <= countnumber; j++)
				{
					printf("%c", string[j]);
				}
				return 0;
			}
			*(string + i) = temp;
			countnumber++;
			if (countnumber > 9)
			{
				printf("-2147483648");
				return 0;
			}
			else if (countnumber == 9)
			{
				//如果string里面的数已经大到超过2^31，则截断
				if (strcmp(string, max) > 0)
				{
					printf("-2147483648");
					return 0;
				}
			}
		}
	}
	//如果不是负号的情况
	else
	{
		//如果是数字或者正号
		if ((temp >= 48 && temp <= 57) || temp == '+')
		{
			//如果是正号或者0需要被舍去
			if (temp == '+' || temp == '0')
			{
				//把数字前的0都删掉
				for (int i = 0; i < 200 - countspace; i++)
				{
					temp = getchar();
					count0++;
					//一直到读到的字符不是0
					if (temp != '0')
					{
						*string = temp;
						countnumber = 1;
						break;
					}
				}
				for (int i = 1; i < 200 - countspace - count0 - 1; i++)
				{
					temp = getchar();
					if (temp < 48 || temp > 57)
					{
						for (int j = 0; j < countnumber; j++)
						{
							printf("%c", string[j]);
						}
						return 0;
					}
					*(string + i) = temp;
					countnumber++;
					if (countnumber > 9)
					{
						return 2147483647;
					}
					else if (countnumber == 9)
					{
						if (strcmp(string, max) > 0)
						{
							return 2147483647;
						}
					}
				}
			}
			//如果读到的第一个就是正整数；
			else
			{
				string[0] = temp;
				for (int i = 1; i < 200 - countspace - 1; i++)
				{
					temp = getchar();
					if (temp < 48 || temp > 57)
					{
						for (int j = 0; j <= countnumber; j++)
						{
							printf("%c", string[j]);
						}
						return 0;
					}
					*(string + i) = temp;
					countnumber++;
					if (countnumber > 9)
					{
						return 2147483647;
					}
					else if (countnumber == 9)
					{
						//如果string里面的数已经大到超过2^31，则截断
						if (strcmp(string, max) > 0)
						{
							return 2147483647;
						}
					}
				}
			}
		}
		//第一个读到了非数字或者正负号
		else
		{
			printf("0");
			return 0;
		}
	}
}