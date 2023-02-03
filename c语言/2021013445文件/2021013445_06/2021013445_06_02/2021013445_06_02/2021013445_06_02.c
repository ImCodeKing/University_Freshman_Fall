#include <stdio.h>
#include "2021013445_06_02_Score.h"
int ScoreMax = 0;
int coursecount = 0;
int totaltime = 0;
int main(int argc, char* argv[])
{
	scanf("%d%d", &totaltime, &coursecount);
	for (int i = 1; i <= coursecount; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= coursecount; i++)
	{
		scanf("%d", &s[i]);
	}
	ScoreMax = GetMaxScore(totaltime, w, s, coursecount);
	printf("%d", ScoreMax);
	return 0;
}