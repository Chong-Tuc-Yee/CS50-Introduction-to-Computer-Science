#include <cs50.h>
#include <stdio.h>

bool validity(long long ccn_number);
int check_length(long long ccn_number);
bool check_sum(long long ccn_number);
void print_ccn(long long ccn_number);

int main(void)
{
    long long ccn_number;
    do
    {
        ccn_number = get_long("Number:"); //Request user input credit card number
    }
    while(ccn_number < 0);

    if (validity(ccn_number)) //Print out the type of credit card if number valid
    {
        print_ccn(ccn_number);
    }
    else
    {
        printf("Invalid\n");
    }
}

/* Check validity for credit card number */
bool validity(long long ccn_number)
{
    int ccn_length = check_length(ccn_number);
    if((ccn_length == 13 || ccn_length == 15 || ccn_length == 16) && check_sum(ccn_number))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Obtain the number of digits for credit card number */
int check_length(long long ccn_number)
{
    int len;
    for(len = 0; ccn_number > 0 ; len++, ccn_number /= 10);
    return len;
}

/* Perform Luhn's algorithm to check validity */
bool check_sum(long long ccn_number)
{
    int i, sum = 0;
    for(i = 0; ccn_number > 0; i++, ccn_number /= 10)
    {
        if(i % 2 == 0)
        {
            sum += ccn_number % 10;
        }
        else
        {
            int doub;
            doub = 2 * (ccn_number % 10);
            sum += (doub / 10) + (doub % 10);
        }
    }

    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Evaluate type of credit card for input card number and display type */
void print_ccn(long long ccn_number)
{
    if((ccn_number >= 34e13 && ccn_number < 35e13) || (ccn_number >= 37e13 & ccn_number < 38e13))
    {
        printf("AMEX\n");
    }
    else if(ccn_number >= 51e14 && ccn_number < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if((ccn_number >= 4e12 && ccn_number < 5e12) || (ccn_number >= 4e15 && ccn_number < 5e15))
    {
        printf("VISA\n");
    }
}
