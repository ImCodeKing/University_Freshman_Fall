#include <stdio.h>
int main(int argc, char* argv[])
{
	int input = 0;
	int temp = 0;
	int Xmin = 0;
	int Xmax = 0;
	int Ymin = 0;
	int Ymax = 0;
    int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int Xmove = 0;
	int Ymove = 0;
	scanf("%d%d%d%d", &Xmin, &Xmax, &Ymin, &Ymax);
	for (int i = 0; i < 2147483647; i++)
	{
		scanf("%d", &input);
		if (input == -1)
		{
			break;
		}
		else
		{
			if (input > 0)
			{
				temp = input;
				up = (unsigned int)(temp << 31) >> 31;
				temp = input;
				down = (unsigned int)((temp >> 1) << 31) >> 31;
				temp = input;
				left = (unsigned int)((temp >> 2) << 31) >> 31;
				temp = input;
				right = (unsigned int)((temp >> 3) << 31) >> 31;
				Ymove = Ymove + up - down;
				Xmove = Xmove + right - left;
			}
			//?
			else
			{
				temp = input;
				up = -1 * (unsigned int)(temp << 31) >> 31;
				temp = input;
				down = -1 * (unsigned int)((temp >> 1) << 31) >> 31;
				temp = input;
				left = -1 * (unsigned int)((temp >> 2) << 31) >> 31;
				temp = input;
				right = -1 * (unsigned int)((temp >> 3) << 31) >> 31;
				Ymove = Ymove + up - down;
				Xmove = Xmove + right - left;
			}
			if (Ymove > Ymax)
			{
				Ymove = Ymin;
			}
			else if (Ymove < Ymin)
			{
				Ymove = Ymax;
			}
			if (Xmove > Xmax)
			{
				Xmove = Xmin;
			}
			else if (Xmove < Xmin)
			{
				Xmove = Xmax;
			}
			printf("(%d, %d)\n", Xmove, Ymove);
		}
	}
	return 0;
}
//转码方式除了（unsigned int）还有什么其他的方法呢？
//负数的按位左右移是否补的是1？