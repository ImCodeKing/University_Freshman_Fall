#include <stdio.h>
int count = 1;
int countfloat = 1;
unsigned int idx[11] = { 0 };
unsigned int idxfloat[11] = { 0 };
unsigned int intpart = 0;
float floatpart = 0;
void Integer_tran(unsigned int input, int type)
{
	if ((input / type) == 0)
	{
		for (int i = 0; i < count; i++)
		{
			idx[11 - count] = input % type;
			printf("%d", idx[11 - count + i]);
		}
	}
	else
	{
		idx[11 - count] = input % type;
		count++;
		input = (input - (input % type)) / type;
		Integer_tran(input, type);
	}
}
/*以上是整数部分转进制（十进制以内）*/
/*以下是小数部分转进制（十进制以内）*/
void Decimal_tran(float input, int type)
{
	if (countfloat == 1)
	{
		intpart = input;
		floatpart = input - intpart;
	}
	if (floatpart * type == 0 && countfloat != 1 || countfloat == 5)
	{
		printf("0.");
		for (int i = 0; i < countfloat - 1; i++)
		{
			printf("%d", idxfloat[10 - i]);
		}
	}
	else
	{
		idxfloat[11 - countfloat] = floatpart * type;
		countfloat++;
		intpart = floatpart * type;
		floatpart = floatpart * type - intpart;
		Decimal_tran(floatpart, type);
	}
}