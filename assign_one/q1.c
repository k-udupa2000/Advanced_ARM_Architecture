/*
Program to find the largest of 3 numbers.
*/
#include<stdio.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int answer = a;
    if(b > a)
    {
        if(b > c)
        {
            answer = b;
        }
        else
        {
            answer = c;
        }
    }
    else if(c > a)
    {
        answer = c;
    }
    printf("Maximum element = %d\n", answer);
    return 0;
}
