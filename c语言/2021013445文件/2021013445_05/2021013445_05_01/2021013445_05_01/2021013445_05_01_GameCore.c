#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "2021013445_05_01_GameCore.h"
int MakeRandomTarget()
{
	srand((unsigned)time(NULL));
	int Dig[9] = { 1,2,3,4,5,6,7,8,9 };
	//����һ�����������ĸ������
	int RandomNum[4] = { 0 };
	for (int i = 0; i <= 3; i++)
	{
		//���һ����
		int Idx = rand() % (8 - i);
		//��ԭ������ȡ����������������м�ֵmiddle
		int middle = Dig[Idx];
		for (int j = 0; j <= (8 - Idx); j++)
		{
			//��������Ӧȥ������
			Dig[Idx + j] = Dig[Idx + j + 1];
		}
		//��middle����Ԥ�������
		RandomNum[i] = middle;
	}
	int returntarget = 1000 * RandomNum[0] + 100 * RandomNum[1] + 10 * RandomNum[2] + RandomNum[3];
	return returntarget;
}
_Bool IsValidNumber(int Number)
{
	//���½����������
	int thousand = (Number / 1000) % 10;
	int hundred = (Number / 100) % 10;
	int ten = (Number / 10) % 10;
	int single = Number % 10;
	//����ؼ����ر���
	int bool = 1;
	//ǧλ�Ƿ��һ�޶�
	if (thousand != hundred && thousand != ten && thousand != single)
	{
		//��λ�Ƿ��һ�޶�
		if (hundred != ten && hundred != single)
		{
			//ʮλ�Ƿ��һ�޶�
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
	//���½���������ָ�������
	int thdIn = (Input / 1000) % 10;
	int hudIn = (Input / 100) % 10;
	int tenIn = (Input / 10) % 10;
	int sglIn = Input % 10;
	int in[4] = { thdIn, hudIn, tenIn, sglIn };
	//���½�ϵͳ�������ָ�������
	int thdTar = (Target / 1000) % 10;
	int hudTar = (Target / 100) % 10;
	int tenTar = (Target / 10) % 10;
	int sglTar = Target % 10;
	int tar[4] = { thdTar, hudTar, tenTar, sglTar };
	for (int i = 0; i <= 3; i++)
	{
		//�ж���������һ���ж��ٸ�����ͬ��λ����ͬ
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
				//�ж���������һ���ж��ٸ�����ͬ
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
	//�ж������Ƿ��ڷ�Χ��
	while (Number >= 10000 || Number <= 999)
	{
		scanf("%d", &Number);
	}
	_Bool judgement;
	//�ж��Ƿ����Ҫ��
	judgement = IsValidNumber(Number);
	//Ϊ������������
	while (judgement == 0)
	{
		scanf("%d", &Number);
		judgement = IsValidNumber(Number);
	}
	return Number;
}