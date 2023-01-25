//A program that visualy represent, with dark and light bulb emoji, how many bits are used to represent a character, a word or a text.
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void decimal_to_binary(int i);

int main(void)
{
    //Ask user for message
    string message = get_string("What's your message ?:");
    //Iterate over each character of the string
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        /*Function that call the print_bulb() function on 8 bits. Will print a Light emoji on every bits that the character's decimal number contain.
        Else, will print a Dark emoji*/
        decimal_to_binary((int) message[i]);
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }

}

void decimal_to_binary(int i)
{
    if (i % 127 < i)
    {
        print_bulb(1);
        i = i % 127;
    }
    else
    {
        print_bulb(0);
    }
    if (i % 64 < i)
    {
        print_bulb(1);
        i = i % 64;
    }
    else
    {
        print_bulb(0);
    }
    if (i % 32 < i)
    {
        print_bulb(1);
        i = i % 32;
    }
    else
    {
        print_bulb(0);
    }
    if (i % 16 < i)
    {
        print_bulb(1);
        i = i % 16;
    }
    else
    {
        print_bulb(0);
    }
    if (i % 8 < i)
    {
        print_bulb(1);
        i = i % 8;
    }
    else
    {
        print_bulb(0);
    }
    if (i % 4 < i)
    {
        print_bulb(1);
        i = i % 4;
    }
    else
    {
        print_bulb(0);
    }
    if (i % 2 < i)
    {
        print_bulb(1);
        i = i % 2;
    }
    else
    {
        print_bulb(0);
    }
    if (i % 1 < i)
    {
        print_bulb(1);
        i = i % 1;
    }
    else
    {
        print_bulb(0);
    }
    printf("\n");

}
