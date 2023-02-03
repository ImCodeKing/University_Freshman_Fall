#include <stdio.h>
int main(int argc, char* argv[])
{
	unsigned int input = 0;
	//可以改为unsigned int
	unsigned int bonus = 0;
	unsigned int total = 0;
	scanf("%u", &input);
	if (input <= 100)
	{
		total = input;
	}
	else if (input > 100 && input <= 500)
	{
		bonus = (input - 100) * 0.03;
		total = input + bonus;
	}
	else if (input > 500 && input <= 1000)
	{
		bonus = (input - 500) * 0.05 + 12;
		total = input + bonus;
	}
	else if (input > 1000 && input <= 2000)
	{
		bonus = (input - 1000) * 0.1 + 12 + 25;
		total = input + bonus;
	}
	else if (input > 2000)
	{
		bonus = (input - 2000) * 0.15 + 12 + 25 + 100;
		total = input + bonus;
	}
	printf("%u", total);
	return 0;
}