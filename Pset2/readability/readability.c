#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get input from user
    string text = get_string("Text: ");
    float L = (count_letters(text) / (float) count_words(text)) * 100;
    float S = (count_sentences(text) / (float) count_words(text)) * 100;
    // Compute Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    // To check individual functions: printf("%i letters\n %i words\n %i sentences\n", count_letters(text), count_words(text), count_sentences(text));
}

// Count no. of letters
int count_letters(string text)
{
    int num_letter = 0;

    for(int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            num_letter++;
        }
    }
    return num_letter;
}

// Count no. of words
int count_words(string text)
{
    int num_words = 0;

    for(int j = 0; j <= strlen(text); j++)
    {
    /* Check condition where first character is not blank space and condition where no adjacent spacing
        Need to include j == 0 as we only want pass this condition once for the loop and we need to include back the first word which is omitted during the second condition
        No need to consider j == len(text)-1 during second condition where last character may be blank space as return from strlen(text) will exclude it */
        if ((j == 0 && text[0] != ' ') || (text[j] == ' ' && text[j + 1] != ' '))
        {
            num_words ++;
        }
        else if(text[j] == '-')
        {

        }
    }
    return num_words;
}

// Count no. of sentences
int count_sentences(string text)
{
    int num_sentences = 0;

    for(int k = 0; k < strlen(text); k++)
    {
        if(text[k] == '.' || text[k] == '!' || text[k] == '?' )
        {
            num_sentences++;
        }
    }
    return num_sentences;
}
