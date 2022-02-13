#include <cs50.h>
#include <stdio.h>

int main(void)          // Main function
{
    // Prompt user for height until integer between 1 and 8 inclusive
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // Prints pyramid
    for (int i = 0; i < height; i++)
    {
        int space = height - (i + 1);
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        int stair = i + 1;
        for (int k = 0; k < stair; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < stair; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
