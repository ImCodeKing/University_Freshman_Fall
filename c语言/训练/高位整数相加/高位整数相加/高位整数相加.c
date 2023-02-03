#include <stdio.h>
int main(int argc, char* argv[])
{
	char num1[201] = { '\0' };
	char num2[201] = { '\0' };
	char temp[202] = { '\0' };
	char result[202] = { '\0' };
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int calculate1 = 0;
	int calculate2 = 0;
	int add = 0;
	int forwordidx = 0;
	for (int i = 0; i < 200; i++)
	{
		num1[i] = '0';
		num2[i] = '0';
		temp[i] = '0';
	}
	temp[200] = '0';
	scanf("%s%s", num1, num2);
	for (int i = 0; i < 201; i++)
	{
		if (num1[i] == '\0')
		{
			num1[i] = '0';
			break;
		}
		count1++;
	}
	for (int j = 0; j < count1; j++)
	{
		num1[200 - count1 + j] = num1[j];
		num1[j] = '0';
	}
	for (int i = 0; i < 201; i++)
	{
		if (num2[i] == '\0')
		{
			num2[i] = '0';
			break;
		}
		count2++;
	}
	for (int j = 0; j < count2; j++)
	{
		num2[200 - count2 + j] = num2[j];
		num2[j] = '0';
	}
	printf("%s\n%s\n", num1, num2);
	for (int i = 199; i > 0; i--)
	{
		calculate1 = num1[i] - 48;
		calculate2 = num2[i] - 48;
		add = calculate1 + calculate2 + forwordidx;
		if (add >= 10)
		{
			add -= 10;
			temp[i + 1] = add + 48;
			forwordidx = 1;
		}
		else
		{
			temp[i + 1] = add + 48;
			forwordidx = 0;
		}
	}
	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < 201; j++)
		{
			if (temp[count] != '0')
			{
				break;
			}
			count++;
		}
		if (temp[count + i] == '\0')
		{
			break;
		}
		result[i] = temp[count + i];
	}
	printf("%s", result);
	return 0;
}