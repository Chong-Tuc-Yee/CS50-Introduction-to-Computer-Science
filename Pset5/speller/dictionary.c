// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int word_count = 0;

// Hash table
node *table[N];

void free_node(node* p);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO: Check if current word exists in dictionary
    int hash_num2 = hash(word);
    // Create cursor pointer and point to first node of linked list under specified head
    node *cursor = table[hash_num2];
    // Loop through cursor until end of linked list
    while(cursor != NULL)
    // Check if the words(case insensitive) are same
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else // Otherwise move cursor to next node
        {
            cursor = cursor->next;
        }
    }


    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO: Open dictionary file and check if return value is NULL
    FILE *dfile = fopen(dictionary, "r");
    if(dfile == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    // Loop through and read strings from file
    char str[LENGTH + 1];
    while(fscanf(dfile, "%s", str) != EOF)
    {
        // Create a new node and copy word into new node
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            printf("Not enough memory to store new node.\n");
            fclose(dfile);
            return false;
        }
        strcpy(n->word, str);
        n->next = NULL;

        // Call hash function to index string into linked list(head) inside hash table
        int hash_num = hash(str);

        // Insert word into linked list(head) based on index
        // Check if head points to NULL ie. no linked lists for the head
        if(table[hash_num]->next == NULL)
        {
            n->next = NULL; // Points n to NULL
        }
        else
        {
            n->next = table[hash_num]; // Otherwise points n to first node of linked list under the head
        }
        table[hash_num] = n;
        word_count += 1;
    }
    fclose(dfile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO: Return word count in dictionary when successfully loaded
    return word_count;
}

// Recursively free dictionary from memory
void free_node(node *p)
{
    if((p->next) == NULL)
    {
        return;
    }

    free_node(p->next);
    free(p);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO: Recursively free the dictionary from memory
    for(int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            free_node(table[i]);
        }
    }
    return false;
}