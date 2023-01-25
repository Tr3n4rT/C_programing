// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

/* // SELECTION SORT ALGORITHM
void sort_cities(void)
{
    for(int i = 0; i < NUM_CITIES; i++)
    {
        for(int j = i + 1; j <= NUM_CITIES; j++)
        {
            if(temps[i].temp < temps[j].temp)
            {
                printf("BEFOR SWAP: %s %s\n", temps[i].city, temps[j].city);
                string city_swap = temps[i].city;
                int temp_swap = temps[i].temp;

                temps[i].city = temps[j].city;
                temps[i].temp = temps[j].temp;

                temps[j].city = city_swap;
                temps[j].temp = temp_swap;

                printf("AFTER SWAP: %s %s\n", temps[i].city, temps[j].city);
            }
        }
    }
    return;
}*/
/* //BUBLE SORT ALGORITHM
void sort_cities(void)
{
    int k = 0;

    do
    {
        int i = 0;
        int j = i + 1;
        k = 0;

        while(j <= NUM_CITIES)
        {
            printf("BEFOR SWAP: %s %s\n", temps[i].city, temps[j].city);
            if(temps[i].temp < temps[j].temp)
            {
                string city_swap = temps[i].city;
                int temp_swap = temps[i].temp;

                temps[i].city = temps[j].city;
                temps[i].temp = temps[j].temp;

                temps[j].city = city_swap;
                temps[j].temp = temp_swap;
                k++;
            }
            printf("AFTER SWAP: %s %s\n", temps[i].city, temps[j].city);
            i++, j++;
        }
    }
    while(k != 0);

return;
}*/
