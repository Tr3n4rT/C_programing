#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    //prompt user for height
    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);
    //write rows
    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n - 1; k++)
        {
            printf(" ");
        }
        //write columns
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}