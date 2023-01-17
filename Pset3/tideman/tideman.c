#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool has_cycle(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO: Update one voter's vote rankings to match the candidates using candidate index
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name,candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO: Update preference count for one voter with ranking and candidate index
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO: Update winner and loser pair candidate index to pairs array
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(preferences[i][j] != 0 && preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO: Use bubble sort to rearrange the pairs array according to decreasing order of strength of victory
    int swap_winner, swap_loser;

    for(int i = 0; i < pair_count; i++)
    {
        for(int j = 0; j < pair_count - 1; j++)
        {
            if(preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                swap_winner = pairs[i].winner;
                pairs[i].winner = pairs[j].winner;
                pairs[j].winner = swap_winner;

                swap_loser = pairs[i].loser;
                pairs[i].loser = pairs[j].loser;
                pairs[j].loser = swap_loser;
            }
        }
    }
    return;
}

bool has_cycle(int winner, int loser)
{
    if(locked[loser][winner] == true)
    {
        return true;
    }
    for(int i = 0; i < candidate_count; i++)
    {
        if(locked[loser][i] == true && has_cycle(winner,i))
        {
            return true;
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for(int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if(!has_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(locked[j][i] == true)
            {
                break;
            }
            else if(j == candidate_count - 1)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
    return;
}
