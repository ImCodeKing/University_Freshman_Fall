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
	//������Сֵ��������ԭ���������ں��������н�input�ĸ���ȥ��������ʵ��Ӧ����-2147483648
	char min[11] = "2147483648";
	//ɾ���ո�Ĳ���
	for (int i = 0; i < 200; i++)
	{
		temp = getchar();
		countspace++;
		if (temp != ' ')
		{
			break;
		}
	}
	//����ǲ��Ƕ����˸���
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
				//���string��������Ѿ��󵽳���2^31����ض�
				if (strcmp(string, max) > 0)
				{
					printf("-2147483648");
					return 0;
				}
			}
		}
	}
	//������Ǹ��ŵ����
	else
	{
		//��������ֻ�������
		if ((temp >= 48 && temp <= 57) || temp == '+')
		{
			//��������Ż���0��Ҫ����ȥ
			if (temp == '+' || temp == '0')
			{
				//������ǰ��0��ɾ��
				for (int i = 0; i < 200 - countspace; i++)
				{
					temp = getchar();
					count0++;
					//һֱ���������ַ�����0
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
			//��������ĵ�һ��������������
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
						//���string��������Ѿ��󵽳���2^31����ض�
						if (strcmp(string, max) > 0)
						{
							return 2147483647;
						}
					}
				}
			}
		}
		//��һ�������˷����ֻ���������
		else
		{
			printf("0");
			return 0;
		}
	}
}