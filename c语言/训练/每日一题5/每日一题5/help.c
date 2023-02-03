#include <stdio.h>
#include <stdlib.h>
#include "help.h"
int Create2DMatrix(float** p, unsigned int Row, unsigned int Col)
{
	if (Row == 0 || Col == 0)
	{
		return 0;
	}
	else
	{
		*p = (float*)calloc(Row * Col, sizeof(float));
		return (Row * Col * sizeof(float));
	}
}