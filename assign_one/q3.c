/*
Program to find the count of even numbers in an array.
*/
#include<stdio.h>

int main()
{
    int arr[20];
    for(int i = 0; i < 20; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count_even = 0;
    for(int i = 0; i < 20; i++)
    {
        if(arr[i]%2 == 0)
        {
            count_even++;
        }
    }
    printf("Number of even integers = %d\n", count_even);
    return 0;
}