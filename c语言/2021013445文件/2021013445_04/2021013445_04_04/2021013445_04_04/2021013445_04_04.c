#include <stdio.h>
int main()
{
	char nation;
	char ability;
	char position;
	float weight = 0;
	float price = 0;
	printf("Please enter your nation\n");
	scanf("%c", &nation);
	getchar();
	printf("Please enter your ability\n");
	scanf("%c", &ability);
	getchar();
	printf("Please enter your position\n");
	scanf("%c", &position);
	getchar();
	printf("Please enter your weight of the luggage\n");
	scanf("%f", &weight);
	if (position == 'F' || position == 'f' || position == 'A' || position == 'a')
	{
		if (weight <= 30)
		{
			price = 0;
		}
		else if (weight > 30 && weight <= 35)
		{
			price = (weight - 30) * 4;
		}
		else if (weight > 35 && weight <= 40)
		{
			price = 20 + (weight - 35) * 5;
		}
		else if (weight > 40 && weight <= 50)
		{
			price = 45 + (weight - 40) * 7;
		}
		else if (weight > 50)
		{
			price = 115 + (weight - 50) * 12;
		}
	}
	else if (position == 'C' || position == 'c' || position == 'D' || position == 'd')
	{
		if (weight <= 25)
		{
			price = 0;
		}
		else if (weight > 25 && weight <= 30)
		{
			price = (weight - 25) * 5;
		}
		else if (weight > 30 && weight <= 35)
		{
			price = 25 + (weight - 30) * 6;
		}
		else if (weight > 35 && weight <= 45)
		{
			price = 55 + (weight - 35) * 8;
		}
		else if (weight > 45)
		{
			price = 135 + (weight - 45) * 13;
		}
	}
	else if (
		position == 'Y' || position == 'y' || position == 'B' || position == 'b' ||
		position == 'H' || position == 'h' || position == 'K' || position == 'k' ||
		position == 'L' || position == 'l' || position == 'M' || position == 'm' ||
		position == 'N' || position == 'n' || position == 'Q' || position == 'q' ||
		position == 'T' || position == 't' || position == 'X' || position == 'x' ||
		position == 'U' || position == 'u' || position == 'E' || position == 'e' ||
		position == 'W' || position == 'w' || position == 'R' || position == 'r' ||
		position == 'O' || position == 'o'
		)
	{
		if (weight <= 20)
		{
			price = 0;
		}
		else if (weight > 20 && weight <= 25)
		{
			price = (weight - 20) * 6;
		}
		else if (weight > 25 && weight <= 30)
		{
			price = 30 + (weight - 25) * 7;
		}
		else if (weight > 30 && weight <= 40)
		{
			price = 65 + (weight - 30) * 9;
		}
		else if (weight > 40)
		{
			price = 155 + (weight - 40) * 14;
		}
		if (position == 'B' || position == 'b')
		{
			price = price / 0.9;
		}
		else if (position == 'H' || position == 'h')
		{
			price = price / 0.85;
		}
		else if (position == 'K' || position == 'k')
		{
			price = price / 0.8;
		}
		else if (position == 'L' || position == 'l')
		{
			price = price / 0.75;
		}
		else if (position == 'M' || position == 'm')
		{
			price = price / 0.7;
		}
		else if (position == 'N' || position == 'n')
		{
			price = price / 0.65;
		}
		else if (position == 'Q' || position == 'q')
		{
			price = price / 0.6;
		}
		else if (position == 'T' || position == 't')
		{
			price = price / 0.55;
		}
		else if (position == 'X' || position == 'x')
		{
			price = price / 0.5;
		}
		else if (position == 'U' || position == 'u')
		{
			price = price / 0.45;
		}
		else if (position == 'E' || position == 'e')
		{
			price = price / 0.4;
		}
		else if (position == 'W' || position == 'w')
		{
			price = price / 0.35;
		}
		else if (position == 'R' || position == 'r')
		{
			price = price / 0.3;
		}
		else if (position == 'O' || position == 'o')
		{
			price = price / 0.25;
		}
	}
	if (nation == 'f' || nation == 'F')
	{
		price = price * 2;
		if (ability == 'u' || ability == 'U')
		{
			price = price * 0.5;
		}
		else if (ability == 'n' || ability == 'N')
		{
			price = price;
		}
	}
	else if (nation == 'c' || nation == 'C')
	{
		if (ability == 'u' || ability == 'U')
		{
			price = price * 0.5;
		}
		else if (ability == 'n' || ability == 'N')
		{
			price = price;
		}
	}
	printf("%.2f", price);
	return 0;
}