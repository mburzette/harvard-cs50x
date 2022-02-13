#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)          // Main function
{
    //Get input from user until a float >= 0 is entered
    float dollars = 0;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    //Convert dollars and change to cents and round total cents to the nearest penny if float > 2 digits after the decimal
    int cents = round(dollars * 100);

    int pennies = 0;
    int nickels = 0;
    int dimes = 0;
    int remainder = 0;

    int quarters = cents / 25;
    //printf("quarters: %i\n", quarters);                   //Check quarters output

    if (cents != quarters * 25)                             //Check if amount can be fulfilled with dimes
    {
        remainder = cents - (quarters * 25);                //Find remaining amount after quarters
        dimes = remainder / 10;
        //printf("dimes: %i\n", dimes);                     //Check dimes output

        if (cents != (dimes * 10))                          //Check if amount can be fulfilled with nickels
        {
            remainder = remainder - (dimes * 10);           //Find remaining amount after quarters and dimes
            nickels = remainder / 5;
            //printf("nickels: %i\n", nickels);             //Check nickels output

            if (cents != ((dimes * 10) + (nickels * 5)))    //Check if amount can be fulfilled with pennies
            {
                pennies = remainder - (nickels * 5);        //Find remaining amount after quarters, dimes, and nickels
                //printf("pennies: %i\n", pennies);         //Check pennies output
            }
        }
    }
    int change = quarters + dimes + nickels + pennies;      //Change is how many of each coin type cashier needs to return
    printf("%i\n", change);
}
