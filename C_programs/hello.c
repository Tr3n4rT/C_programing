//First program wrote in C. Ask for the user name and print a greating.
#include <stdio.h>
#include <cs50.h>

int main(void)

{
    string name = get_string("What's your name ?");
    printf("hello, %s\n", name);
}
