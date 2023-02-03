#include <stdio.h>
char CodeTransform(char code, char message)
{
	if (code >= 'a' && code <= 'z' && message >= 'a' && message <= 'z')
	{
		return code;
	}
	else if (code >= 'A' && code <= 'Z' && message >= 'A' && message <= 'Z')
	{
		return code;
	}
	else if (code >= 'A' && code <= 'Z' && message >= 'a' && message <= 'z')
	{
		return (code - 'A' + 'a');
	}
	else if (code >= 'a' && code <= 'z' && message >= 'A' && message <= 'Z')
	{
		return (code - 'a' + 'A');
	}
}
int main(int argc, char* argv[])
{
	int count = -1;
	int countCode = 0;
	char Code[101] = { '\0' };
	char Message[1001] = { '\0' };
	char TempCode = '\0';
	scanf("%s%s", Code, Message);
	for (int i = 0; Message[i] != '\0'; i++)
	{
		count++;
		if (Code[count] == '\0')
		{
			count = 0;
		}
		TempCode = CodeTransform(Code[count], Message[i]);
		char Temp[27] = { '\0' };
		for (int j = 0; j < 26; j++)//���岢��ʼ����һ����ǰ�������
		{
			if (Message[i] <= 'z' && Message[i] >= 'a')
			{
				if (TempCode + j > 'z')
				{
					Temp[j] = TempCode + j - 26;
				}
				else
				{
					Temp[j] = TempCode + j;
				}
			}
			else
			{
				if (TempCode + j > 'Z')
				{
					Temp[j] = TempCode + j - 26;
				}
				else
				{
					Temp[j] = TempCode + j;
				}
			}
		}
		for (int k = 0; k < 26; k++)//Ѱ�ҵ�ǰ�ַ���������е�λ��
		{
			if (Message[i] == Temp[k])
			{
				countCode = k;
				break;
			}
		}
		if (Message[i] <= 'z' && Message[i] >= 'a')
		{
			printf("%c", 'a' + countCode);
		}
		else
		{
			printf("%c", 'A' + countCode);
		}
	}
	return 0;
}