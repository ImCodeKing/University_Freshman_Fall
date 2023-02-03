#include <stdio.h>
int main(int argc, char* argv[])
{
	int Inschool = 0;
	int Afterschool = 0;
	int Total = 0;
	int Happy[7] = { 0 };
	int Week[7] = { 1,2,3,4,5,6,7 };
	int Temp = 0;
	for (int i = 0; i < 7; i++)
	{
		scanf("%d%d", &Inschool, &Afterschool);
		Total = Inschool + Afterschool;
		if (Total <= 8)
		{
			Happy[i] = 0;
			continue;
		}
		else
		{
			Happy[i] = Total - 8;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i; j < 7 - i; j++)
		{
			if (Happy[i] < Happy[j])
			{
				Temp = Happy[i];
				Happy[i] = Happy[j];
				Happy[j] = Temp;
				Temp = Week[i];
				Week[i] = Week[j];
				Week[j] = Temp;
			}
		}
	}
	if (Happy[0] == 0)
	{
		printf("0");
	}
	else
	{
		printf("%d", Week[0]);
	}
	return 0;
}