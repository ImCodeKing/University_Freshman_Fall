#include <stdio.h>
void Input(char* String)
{
	scanf("%s", String);
}
void triangle_matrix(char* String)
{
	int i = 0;
	int j = 0;
	int Lenth = 0;
	int ToPrint = 0;
	for (i = 0; String[i] != '\0'; i++)
	{
		Lenth++;
	}
	for (i = 0; i < Lenth - 1; i++)
	{
		ToPrint = 0;
		for (j = i; j < Lenth - 1; j++)
		{
			printf("%d,", ToPrint);
			ToPrint += 1;
		}
		printf("%c\n", String[Lenth - i - 1]);
	}
	printf("%c\n", String[0]);
}
int main(int argc, char* argv[])
{
	char String[25] = { '\0' };
	Input(String);
	triangle_matrix(String);
	while (String[0] != ' ')
	{
		printf("ÇëÊäÈëS\n");
		Input(String);
		triangle_matrix(String);
	}
	return 0;
}