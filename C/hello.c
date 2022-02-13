#include <stdio.h>  //import sdio header file
#include <cs50.h>   //import cs50 header file

int main(void)      //main function
{
    string name = get_string("What is your name?\n");   //prompt user for name, store in variable called name
    printf("Hello, %s.\n", name);                       //print hello and the user's entered name
}
