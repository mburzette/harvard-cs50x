#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)          // Main function
{
    // Initialized variables
    long i = 0;
    long cardnum = 0;
    long cardlength = 0;
    int numlength = 0;
    long num = 0;
    long digit = 0;
    int sum1 = 0;
    int sum2 = 0;

    do
    {
        cardnum = get_long("Number: ");                                 // Prompt user for card number
        cardlength = floor(log10(labs(cardnum))) + 1;                   // Find number of digits in card number
        if (cardlength != 13 && cardlength != 15 && cardlength != 16)   // Invalid card number for all lengths other than 13, 15, 16
        {
            printf("INVALID\n");
            exit(0);
        }
    }
    while (cardlength != 13 && cardlength != 15 && cardlength != 16);
    // Do-while loop is necessary to prevent get_long from re-prompting user

    printf("\ncardlength: %li\n", cardlength);
    printf("\n------1st PASS------\n");

    for (i = 10; i < pow(10, cardlength); i = i * 100)                  // Parse through card number starting with second to last digit
    {
        num = (cardnum / i) % 10;                                       // num stores each digit starting with second to last digit
        printf("\nnum: %li\n", num);

        num = num * 2;                                                  // Multiply num by two and store value in num
        printf("mum*2: %li\n", num);

        numlength = floor(log10(labs(num))) + 1;                        // Find number of digits in num
        if (numlength < 1)                                              // If statement prevents negative output when numlength is 0
        {
            numlength = 0;
        }
        printf("numlength: %i\n", numlength);

        if (numlength > 1)                                              // If num has 2 digits, add the 2 digits together and store in num
        {
            digit = num % 10;
            num = num / 10;
            printf("digit1: %li\n", digit);
            printf("digit2: %li\n", num);

            num = num + digit;
            printf("num: %li\n", num);
        }
        sum1 = sum1 + num;                                              // Sum of first pass is stored in sum1
        printf("sum1: %i\n", sum1);

    }

    printf("\n------2nd PASS------\n");

    for (i = 1; i < pow(10, cardlength); i = i * 100)                   // Parse through card number starting with last digit
    {
        num = cardnum / i % 10;                                         // num stores each digit starting with last digit
        printf("\nnum: %li\n", num);

        sum2 = sum2 + num;                                              // Sum of second pass is stored in sum2
        printf("sum2: %i\n", sum2);
    }

    int sum = sum1 + sum2;                                              // Sum of both passes is stored in sum
    printf("\nsum = sum1 %i + sum2 %i = %i\n", sum1, sum2, sum);
    printf("VALID if second digit of sum is 0: %i\n", sum % 10);

    long firstdigit = cardnum;                                          // Find first digit of card number
    while (firstdigit >= 10)
    {
        firstdigit /= 10;
    }

    long firstdigits = cardnum;                                         // Find second digit of card number
    while (firstdigits >= 100)
    {
        firstdigits /= 10;
    }

    if (sum % 10 == 0)                                                  // Last digit of card number must be 0 to be valid
    {
        // AMEX cards must have these first 2 digits and a card length of 15 digits to be valid
        if (firstdigits == 34 || firstdigits == 37)
        {
            if (cardlength == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // MASTERCARD cards must have these first 2 digits and a card length of 16 to be valid
        else if (firstdigits == 51 || firstdigits == 52 || firstdigits == 53 || firstdigits == 54 || firstdigits == 55)
        {
            if (cardlength == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // VISA cards must have this first digit and a card length of 13 or 16 to be valid
        else if (firstdigit == 4)
        {
            if (cardlength == 13 || cardlength == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
