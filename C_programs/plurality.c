#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void swap(int i, int j);
void find_best_score(void);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //Uses string compare to check if the name entered is in the candidates list
        //Updates candidate votes by + 1 if it does
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Find the best votes score in the list, going through the list just one time.
    find_best_score();

    //Print the first candidate name of the list
    //Print any candidate name which score equal the first candidate score
    for (int i = 0; i < candidate_count; i++)
    {

        if (candidates[0].votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

void find_best_score(void)
{
    for (int j = 1; j <= candidate_count; j++)
    {
        if (candidates[0].votes < candidates[j].votes)
        {
            //Swap [j] (best votes score and affiliate candidate) to the position [0] of the candidates list
            swap(0, j);
        }
    }

    return;
}

void swap(int i, int j)
{
    string swap_name = candidates[j].name;
    int swap_votes = candidates[j].votes;

    candidates[j].name = candidates[i].name;
    candidates[j].votes = candidates[i].votes;

    candidates[i].name = swap_name;
    candidates[i].votes = swap_votes;

    return;
}