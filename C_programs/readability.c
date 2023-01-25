// Grade a text on Amercican standards using the Coleman-Liau index formula

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Ask user for text
    string text = get_string("Text: ");
    //Count letters
    int letters = count_letters(text);
    //Count words
    float words = count_words(text);
    //Count sentences
    int sentences = count_sentences(text);

    float l = letters / words * 100;
    float  s = sentences / words * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int i = 0;
    //Increment j until it reach '\0', aka the end of the string
    for (int j = 0; text[j] != '\0'; j++)
    {
        //Count every capital letters by incrementing i for every letters
        while (text[j] >= 65 && text[j] <= 90)
        {
            j++;
            i++;
        }
        //Count every small letters by incrementing i for every letters
        while (text[j] >= 97 && text[j] <= 122)
        {
            j++;
            i++;
        }
    }
    return i;
}

int count_words(string text)
{
    int i = 0;
    //Increment j until it reach '\0', aka the end of the string
    for (int j = 0; text[j] != '\0'; j++)
    {
        //Increment i if one character before [j] is any character but a space AND [j] itself is a space OR '\0'
        if (text[j - 1] >= 33 && (text[j] == 32 || text[j + 1] == '\0'))
        {
            i++;
        }
    }
    return i;
}

int count_sentences(string text)
{
    int i = 0;
    //Increment j until it reach '\0', aka the end of the string
    for (int j = 0; text[j] != '\0'; j++)
    {
        //Increment i if [j] is either . ? ! AND the next character after [j] is a space OR '\0'
        if ((text[j] == 46 || text[j] == 33 || text[j] == 63) && (text[j + 1] == 32 || text[j + 1 ] == '\0'))
        {
            i++;
        }
    }
    return i;
}
