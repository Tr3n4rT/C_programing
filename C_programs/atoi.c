//Simple character to integer converter
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    //Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    if (strlen(input) == 0)
    {
        return input[0];
    }
    else
    {
        int n = strlen(input) - 1;
        int i = input[n] - 48;
        input[n] = input[strlen(input)];
        return i + 10 * convert(input);
    }
}
