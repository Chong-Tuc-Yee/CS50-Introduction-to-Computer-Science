#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, i, j, k;

    //Ask user for pyramid height
    do
    {
        height = get_int("Height: ");
    }
    while(height<1 || height>8);

    //Print out left side block of spaces and hashes for pyramid
    for(i=0; i<=height-1; i++)
    {
        for(j=0; j<=height-i-1; j++)
        {
            printf(" ");
        }
        for(k=0; k<=i; k++)
        {
            printf("#");
        }
        //Print out the middle two spacing
        printf("  ");
        //Print out the right side block of hashes for pyramid
        for(j=0; j<=i ; j++)
        {
            printf("#");
        }

        printf("\n");
    }

}