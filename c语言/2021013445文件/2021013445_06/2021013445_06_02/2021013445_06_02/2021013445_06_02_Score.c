#include <stdio.h>
#include "2021013445_06_02_Score.h"
int MaxScore = 0;
int w[11] = { 0 };
int s[11] = { 0 };
int GetMaxScore(int h, int w[], int s[], int CourseCount)
{
	int tempA = 0;
	int tempB = 0;
	if (CourseCount > 1)
	{
		if (h >= w[CourseCount])
		{
			tempA = GetMaxScore(h - w[CourseCount], w, s, CourseCount - 1) + s[CourseCount];
			tempB = GetMaxScore(h, w, s, CourseCount - 1);
			if (tempA > tempB)
			{
				MaxScore = tempA;
			}
			else
			{
				MaxScore = tempB;
			}
		}
		else
		{
			MaxScore = GetMaxScore(h, w, s, CourseCount - 1);
		}
	}
	if (CourseCount == 1)
	{
		if (h >= w[1])
		{
			MaxScore = s[1];
		}
		else
		{
			MaxScore = 0;
		}
	}
	return MaxScore;
}