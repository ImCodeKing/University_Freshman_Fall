#include <stdio.h>
#include "help.h"
int main(int argc, char* argv[])
{
	int intnum = 0;
	int inttype = 0;
	printf("��������������ֵ��Ҫת���Ľ���:");
	scanf("%d%d", &intnum, &inttype);
	printf("ת�����:");
	Integer_tran(intnum, inttype);
	float floatnum = 0;
	int floattype = 0;
	printf("\n����������С����ֵ��Ҫת���Ľ���:");
	scanf("%f%d", &floatnum, &floattype);
	printf("ת�����: ");
	Decimal_tran(floatnum, floattype);
	return 0;
}