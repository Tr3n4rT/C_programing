// "Scrabble like" game : Ask two players a word each. Calculate points made for each word depending of every letter it contains. 
// Print the one of the two players that get the most points.

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Compare scores and print the player with the highest scores or Tie if both score1 and score2 are equal
    if (score1 > score2)
    {
        printf("Player 1 wins !\n");
    }
    if (score1 < score2)
    {
        printf("Player 2 wins !\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    //Loop that iterate on a string until it reaches the end of a string
    for (int i = 0; word[i] != '\0'; i++)
    {
        //Determine if the character at word[i] is lowercase
        if (islower(word[i]))
        {
            //Adds every number at POINTS[n] into a variable to determine the player's score. POINTS[n] is determine by the substraction of word[i] by 97. Which correspond to every character position value in POINTS[]
            score = POINTS[word[i] - 97] + score;
        }
        //Determine if the character at word[i] is uppercase
        if (isupper(word[i]))
        {
            //Adds every number at POINTS[n] into a variable to determine the player's score. POINTS[n] is determine by the substraction of word[i] by 65. Which correspond to every character position value in POINTS[]
            score = POINTS[word[i] - 65] + score;
        }
    }
    return score;
}
