#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("./substitution KEY\n");
        return 1;
    }

    for(int i = 0, k = argc - i; i < 26; i++, k++)
    {
        if(argv[1][i] == ' ' || !isalpha(argv[1][i]) || argv[1][i] == argv[1][k])
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
    }

    string plaintxt = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for(int j = 0; j < strlen(plaintxt); j++)
    {
        if(isalpha(plaintxt[j]) && isupper(plaintxt[j]))
        {
            printf("%c", toupper(argv[1][plaintxt[j] - 65]));
        }
        else if (isalpha(plaintxt[j]) && islower(plaintxt[j]))
        {
            printf("%c", tolower(argv[1][plaintxt[j] - 97]));
        }
        else
        {
            printf("%c", plaintxt[j]);
        }
    }
    printf("\n");
}
