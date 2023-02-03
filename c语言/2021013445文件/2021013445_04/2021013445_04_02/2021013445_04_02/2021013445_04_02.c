#include <stdio.h>
int main()
{
    int age = 1;
    int now = 1;
    int suppose = 0;
    int miss = 0;
    int left = 0;
    while (left != 236)
    {
        age = 1;
        now++;
        while (age < now)
        {
            suppose = (now * (now + 1)) / 2;
            miss = (age * (age - 1)) / 2;
            left = suppose - miss;
            if (left != 236)
            {
                age++;
            }
            else
            {
                break;
            }
        }
    }
    printf("%d\n", age);
    return 0;
}