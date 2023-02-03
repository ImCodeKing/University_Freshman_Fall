#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "2021013445_05_01_GameCore.h"
int MakeRandomTarget()
{
	srand((unsigned)time(NULL));
	int Dig[9] = { 1,2,3,4,5,6,7,8,9 };
	//定义一个数组容纳四个随机数
	int RandomNum[4] = { 0 };
	for (int i = 0; i <= 3; i++)
	{
		//随机一个数
		int Idx = rand() % (8 - i);
		//从原数组中取随机到的数并赋给中间值middle
		int middle = Dig[Idx];
		for (int j = 0; j <= (8 - Idx); j++)
		{
			//覆盖数组应去掉的数
			Dig[Idx + j] = Dig[Idx + j + 1];
		}
		//将middle加入预设的数组
		RandomNum[i] = middle;
	}
	int returntarget = 1000 * RandomNum[0] + 100 * RandomNum[1] + 10 * RandomNum[2] + RandomNum[3];
	return returntarget;
}
_Bool IsValidNumber(int Number)
{
	//以下将输入数拆分
	int thousand = (Number / 1000) % 10;
	int hundred = (Number / 100) % 10;
	int ten = (Number / 10) % 10;
	int single = Number % 10;
	//定义关键返回变量
	int bool = 1;
	//千位是否独一无二
	if (thousand != hundred && thousand != ten && thousand != single)
	{
		//百位是否独一无二
		if (hundred != ten && hundred != single)
		{
			//十位是否独一无二
			if (ten != single)
			{
				bool = 1;
			}
			else
			{
				bool = 0;
			}
		}
		else
		{
			bool = 0;
		}
	}
	else
	{
		bool = 0;
	}
	return bool;
}
void GetABCount(int Target, int Input, int Count[2])
{
	Count[0] = 0;
	Count[1] = 0;
	//以下将输入数拆分赋给数组
	int thdIn = (Input / 1000) % 10;
	int hudIn = (Input / 100) % 10;
	int tenIn = (Input / 10) % 10;
	int sglIn = Input % 10;
	int in[4] = { thdIn, hudIn, tenIn, sglIn };
	//以下将系统随机数拆分赋给数组
	int thdTar = (Target / 1000) % 10;
	int hudTar = (Target / 100) % 10;
	int tenTar = (Target / 10) % 10;
	int sglTar = Target % 10;
	int tar[4] = { thdTar, hudTar, tenTar, sglTar };
	for (int i = 0; i <= 3; i++)
	{
		//判断两个数组一共有多少个数相同且位数相同
		if (in[i] == tar[i])
		{
			Count[0]++;
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			{
				//判断两个数组一共有多少个数相同
				if (in[i] == tar[j])
				{
					Count[1]++;
				}
			}
		}
	}
	Count[1] = Count[1] - Count[0];
}
int Judge(int Number)
{
	//判断数字是否在范围内
	while (Number >= 10000 || Number <= 999)
	{
		scanf("%d", &Number);
	}
	_Bool judgement;
	//判断是否符合要求
	judgement = IsValidNumber(Number);
	//为假则重新输入
	while (judgement == 0)
	{
		scanf("%d", &Number);
		judgement = IsValidNumber(Number);
	}
	return Number;
}