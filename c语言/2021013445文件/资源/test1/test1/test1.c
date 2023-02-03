#include <stdio.h>
int main(int argc, char* argv[])
{
	char input[1001] = { '\0' };
	char substr[1001][1001] = { '\0' };
	int number[1000] = { 0 };
	int count = 0;
	int temp = 0;
	char tempstr[1001] = { '\0' };
	scanf("%s", input);
	for (int i = 0; i < 1000; i++)
	{
		count = 0;
		if (input[i] == '\0')
		{
			break;
		}
		for (int j = i; j < 1000; j++)
		{
			if (input[j] == '\0')
			{
				break;
			}
			if (input[i] != input[j] && i != j)
			{
				substr[i][count] = input[j];
				count++;
			}
			else if (i == j)
			{
				substr[i][count] = input[i];
				count++;
			}
			else if (input[i] == input[j] && i != j)
			{
				substr[i][count] = input[j];
				count++;
				number[i] = count;
				break;
			}
		}
	}
	for (int count1 = 0; count1 <1000; count1++)
	{
		for (int count2 = 0; count2 < 1000 - count1; count2++)
		{
			if (number[count1] < number[count1 + count2])
			{
				temp = number[count1];
				number[count1] = number[count1 + count2];
				number[count1 + count2] = temp;
				for (int i = 0; i < 1000; i++)
				{
					tempstr[i] = substr[count1][i];
					substr[count1][i] = substr[count2][i];
					substr[count2][i] = tempstr[i];
				}
			}
		}
	}
	printf("%s", substr[0]);
	return 0;
}