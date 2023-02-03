#include <stdio.h>
int main(int argc, char* argv[])
{
	unsigned int input = 0;
	double result = 0;
	double price = 0;
	unsigned int output = 0;
	scanf("%d", &input);
	if (input <= 100)
	{
		result = input;
	}
	else if (input > 100 && input <= 500)
	{
		price = (input - 100) * 0.03;
		result = 100 + price;
	}
	else if (input > 500 && input <= 1000)
	{
		price = (input - 500) * 0.05;
		result = price + 512;
	}
	else if (input > 1000 && input <= 2000)
	{
		price = (input - 1000) * 0.1;
		result = price + 1037;
	}
	else if (input > 2000)
	{
		price = (input - 2000) * 0.15;
		result = price + 2137;
	}
	output = result;
	printf("%lu", output);
	return 0;
}