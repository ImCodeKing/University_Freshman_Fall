#include <stdio.h>
int main(int argc, char* argv[])
{
	int minX = 0;
	int maxX = 0;
	int minY = 0;
	int maxY = 0;
	int x = 0;
	int y = 0;
	int nownum = 0;
	char number = 0;
	int press = 0;
	char input[1000] = { '\0' };
	scanf("%d%d%d%d", &minX, &maxX, &minY, &maxY);
	scanf("%s", input);
	for (int i = 0; i < 1000; i++)
	{
		number = input[i];
		if (number == '-')
		{
			break;
		}
		else
		{
			press = number;
			int up = press % 2;
			press = press - (press % 2) / 2;//进制转换使用
			int down = press % 2;
			press = press - (press % 2) / 2;
			int Ymove = up - down;//总的y步数
			y = Ymove;
			int right = press % 2;
			press = press - (press % 2) / 2;
			int left = press % 2;
			int Xmove = right - left;//总的x步数
			x = Xmove;
			if (Ymove > maxY)
			{
				y = minY + Ymove - maxY;
			}
			else if (Ymove < minY)
			{
				y = maxY + (Ymove - minY);
			}
			if (Xmove > maxX)
			{
				x = minX + Xmove - maxX;
			}
			else if (Xmove < minX)
			{
				x = maxX + (Xmove - minX);
			}
			printf("(%d, %d)\n", x, y);
		}
		return 0;
	}
}