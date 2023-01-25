// Search for the biggest integer in a list.
// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

//Return the max value in the array
int max(int array[], int n)
{
    int i = 0;
    int max = array[i];

    while(i < n)
    {
        if(max < array[i])
        {
            max = array[i];
        }
        i++;
    }
    return max;
}
