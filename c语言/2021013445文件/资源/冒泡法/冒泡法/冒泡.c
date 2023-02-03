#include <stdio.h>
int main(int argc, char* argv[])
{
	int number[5] = { 2,3,1,6,5 };
	int temp = 0;
	for (int count1 = 0; count1 </*数组长度*/5; count1++)
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
/*以上是从小到大排列*/
/*以下是从大到小排列*/
	for (int count1 = 0; count1 </*数组长度*/5; count1++)
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
