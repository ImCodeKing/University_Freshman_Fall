#include <stdio.h>
int main(int argc, char* argv[])
{
	int number[5] = { 2,3,1,6,5 };
	int temp = 0;
	for (int count1 = 0; count1 </*���鳤��*/5; count1++)
	{
		for (int count2 = 0; count2 < 5 - count1; count2++)
		{
			if (number[count1] > number[count1 + count2])
			{
				temp = number[count1];
				number[count1] = number[count1 + count2];
				number[count1 + count2] = temp;
			}
		}
	}
/*�����Ǵ�С��������*/
/*�����ǴӴ�С����*/
	for (int count1 = 0; count1 </*���鳤��*/5; count1++)
	{
		for (int count2 = 0; count2 < 5 - count1; count2++)
		{
			if (number[count1] < number[count1 + count2])
			{
				temp = number[count1];
				number[count1] = number[count1 + count2];
				number[count1 + count2] = temp;
			}
		}
	}
	return 0;
}
