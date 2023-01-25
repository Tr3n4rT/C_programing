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
    //write row
    for (int i = 0; i < n; i++)
    {
        //write space for right-align the pyramid
        for (int j = i; j < n - 1; j++)
        {
            printf(" ");
        }
        //write a right-align pyramid followed by 2 spaces
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        //write a left-align pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}