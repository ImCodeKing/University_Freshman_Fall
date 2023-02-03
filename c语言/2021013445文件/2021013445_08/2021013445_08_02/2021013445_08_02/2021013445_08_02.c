#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	char* space = (char*)malloc(10 * sizeof(char));
	char temp;
	int returnnumber = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		temp = getchar();
		if (i == 0)
		{
			if (temp == '\n')
			{
				printf("\n");
				exit(0);
			}
		}
		if (temp != '\n')
		{
			*(space + i) = temp;
			returnnumber = 0;
		}
		else
		{
			*(space + i) = '\0';
            realloc(space, i + 1);
			returnnumber = -1;
			break;
		}
	}
	if (returnnumber == 0)
	{
		for (j = 0; j < 4294967296; j++)
		{
			realloc(space, 10 + j + 1);
			temp = getchar();
			if (temp != '\n')
			{
				*(space + 10 + j) = temp;
			}
			else
			{
				*(space + 10 + j) = '\0';
				break;
			}
		}
	}
	for (int k = 0; k < (i + j); k++)
	{
		if (*(space + k) >= 65 && *(space + k) <= 90)
		{
			*(space + k) += 32;
		}
		else if (*(space + k) >= 97 && *(space + k) <= 122)
		{
			*(space + k) -= 32;
		}
		else if (*(space + k) == 32)
		{
			*(space + k) = 95;
		}
		else if (*(space + k) >= 48 && *(space + k) <= 57)
		{
			if (*(space + k) == '0')
			{
				*(space + k) = '9';
			}
			else if (*(space + k) == '9')
			{
				*(space + k) = '0';
			}
			else if (*(space + k) == '1')
			{
				*(space + k) = '8';
			}
			else if (*(space + k) == '8')
			{
				*(space + k) = '1';
			}
			else if (*(space + k) == '2')
			{
				*(space + k) = '7';
			}
			else if (*(space + k) == '7')
			{
				*(space + k) = '2';
			}
			else if (*(space + k) == '3')
			{
				*(space + k) = '6';
			}
			else if (*(space + k) == '6')
			{
				*(space + k) = '3';
			}
			else if (*(space + k) == '4')
			{
				*(space + k) = '5';
			}
			else if (*(space + k) == '5')
			{
				*(space + k) = '4';
			}
		}
	}
	printf("%s", space);
	return 0;
}