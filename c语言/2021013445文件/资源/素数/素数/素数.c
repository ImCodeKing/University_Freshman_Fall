#include <stdio.h>
int main(int argc, char* argv[])
{
	int input = 0;
	int total = 0;
	scanf("%d%d", &input, &total);
	int number[20] = { 0 };
	int count = 0;
	int count1 = 0;
	for (int count2 = input; count < total; count2++)
	{
		for (int count3 = 2; count3 < count2; count3++)
		{
			if ((count2 % count3) == 0)
			{
				break;
			}
			else if (count3 == count2 - 1)
			{
				count++;
				number[count1] = count2;
				count1++;
			}
		}
	}
	return 0;
}