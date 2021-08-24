/*
Program to find the largest number in an array.
*/
#include<stdio.h>
int findMax(int *, int);
int findMax(int *arr, int n)
{
    int maxele = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxele)
        {
            maxele = arr[i];
        }
    }
    return maxele;
}
int main()
{
    int arr[15];
    for(int i = 0; i < 15; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = findMax(arr, 15);
    printf("Maximum element = %d\n", ans);
    return 0;
}