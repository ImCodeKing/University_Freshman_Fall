#include <stdio.h>
#include "help.h"
int main(int argc, char* argv[])
{
	int intnum = 0;
	int inttype = 0;
	printf("请输入正整数数值和要转换的进制:");
	scanf("%d%d", &intnum, &inttype);
	printf("转换完成:");
	Integer_tran(intnum, inttype);
	float floatnum = 0;
	int floattype = 0;
	printf("\n请输入正纯小数数值和要转换的进制:");
	scanf("%f%d", &floatnum, &floattype);
	printf("转换完成: ");
	Decimal_tran(floatnum, floattype);
	return 0;
}