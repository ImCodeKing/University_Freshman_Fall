#include <stdio.h>
int main(int argc, char* argv[])
{
	char input[50000] = { '\0' };
	int number[50000] = { 0 };
	char substr[50000] = { '\0' };
	int count = 0;
	int i;
	scanf("%s", input);
	for (i = count; i < 50000; i++)
	{
		for (int j = 0; j < 50000; j++)
		{
			if (substr[j] == '\0')
			{
				substr[j] = input[i];
				count++;
				break;
			}
			else if (substr[j] == input[i])
			{
				for (int l = 0; l < 50000; l++)
				{
					substr[l] = '\0';
				}
				i--;
				break;
			}
		}
	}
	return 0;
}
/*以上程序可以将字符串截成没有重复字符的子字串*/