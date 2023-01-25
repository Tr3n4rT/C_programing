//Simple plaintext encrypting program. 

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    //Stop the program if the number of argument is not equal to 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Verify that the second argument entered contain only digits. Stop the program if not.
    if (only_digits(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Convert the second argument vector to an integer
    int key = atoi(argv[1]);
    //Ask a plaintext to user
    string plaintext = get_string("PLAINTEXT:");

    printf("CIPHERTEX: ");
    //Iterate over plaintext to use the rotate function on each character inside it.
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        //Rotate(char, int) will switch every character in that character + key.
        char c = rotate(plaintext[i], key % 26);
        printf("%c", c);
    }
    printf("\n");
}

bool only_digits(string s)
{

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int k)
{
    if (islower(c))
    {
        c = c - 97;
        c = (c + k) % 26;
        c = c + 97;
    }
    if (isupper(c))
    {
        c = c - 65;
        c = (c + k) % 26;
        c = c + 65;
    }
    return c;
}
