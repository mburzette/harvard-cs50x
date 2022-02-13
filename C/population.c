#include <cs50.h>
#include <stdio.h>

int main(void)          // Main function
{
    // Prompt for starting size
    int starting = get_int("Starting population size: ");
    while (starting < 9)
    {
        starting = get_int("Starting size cannot be less than 9. Enter again: ");
    }

    // Prompt for end size
    int ending = get_int("Ending population size: ");
    while (ending < starting)
    {
        ending = get_int("Ending size cannot be less than starting size %i. Enter again: ", starting);
    }

    // Calculate number of years until we reach threshold
    int born_init = starting / 3;
    int passed_init = starting / 4;
    int growth = starting + born_init - passed_init;
    int born = 0;
    int passed = 0;
    int years;
    for (years = 1; growth < ending; years++)
    {
        born = growth / 3;
        passed = growth / 4;
        growth += born - passed;
    }

    // Print number of years
    if (starting == ending)
    {
        printf("Years: 0\n");
    }
    else
    {
        printf("Years: %i\n", years);
    }
}
