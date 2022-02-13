#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Function declaration
int compute_score(string word);

//Main function
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Compute and return score for string
int compute_score(string word)
{
    char WORD[strlen(word)];        //create a char array with size of string length
    strcpy(WORD, word);             //copy string into char array

    //iterate through WORD array and increment points based on letter score from POINTS array
    char letter;
    int num = 0, points = 0;
    for (int i = 0; i < sizeof(WORD); i++)
    {
        letter = WORD[i];
        if (letter >= 'A' && letter <= 'Z')
        {
            num = letter - 'A';
            points += POINTS[num];
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            num = letter - 'a';
            points += POINTS[num];
        }
    }
    return points;
}
