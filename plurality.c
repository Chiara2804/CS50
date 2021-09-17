//Mancarella Chiara cs50
/*Le elezioni si presentano in tutte le forme e dimensioni. Nel Regno Unito, 
il Primo Ministro è ufficialmente nominato dal monarca, che generalmente sceglie il leader 
del partito politico che ottiene il maggior numero di seggi alla Camera dei Comuni. 
Gli Stati Uniti utilizzano un processo di collegio elettorale in più fasi in cui i cittadini 
votano su come ogni stato dovrebbe allocare gli elettori che poi eleggono il presidente.
Forse il modo più semplice per tenere un'elezione, tuttavia, è tramite un metodo comunemente 
noto come "voto pluralità" (noto anche come "primo-passato-il-post" o "vincitore prende tutto"). 
Nel voto di pluralità, ogni elettore può votare per un candidato. 
Alla fine delle elezioni, il candidato che ha ottenuto il maggior numero di voti viene dichiarato vincitore dell'elezione.
scrivi un programma che chieda il numero di candidati (max 9), ciascun candidato ha 2 string (nome e voti) e dica chi è il vincitore tra i candidati.

ex. 
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX 9 //max number of candidates

typedef struct //candidates have name and vote count
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX]; //array of candidates

int candidate_count; //number of candidates

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2) //check for invalid usage
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    
    //populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    
    int voter_count = get_int("Number of voters: ");
    
    //loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        
        //check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    
    print_winner();
}

int get_index(string name)
{
    for (int i = 0; i < candidate_count; i++)
        if (strcmp(name, candidates[i].name) == 0)
        {
            return i;
        }
    return -1;
}

bool vote(string name) //update vote totals given a new vote
{
    //figure out the index corresponding to the name that's given to me
    int candidate_index = get_index(name);
    if (candidate_index != -1)
    {
        //increment vote of that candidate
        candidates[candidate_index].votes++;
        return true;
    }
    return false;
}

int get_max(void)
{
    int max_votes = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }

    return max_votes;
}

void print_winner(void) //print the winner (or winners) of the election
{
    int max_votes = get_max(); //figure out the maximum of votes
    
    //printing the name of those candidates who got have the max 
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

}
