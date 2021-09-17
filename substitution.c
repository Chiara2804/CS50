//Mancarella Chiara cs50
/*questo programma è simile a caesar.c.
in questo caso dovremmo fornire la chiave: una mappatura di ciascuna delle lettere dell'alfabeto 
alla lettera a cui dovrebbe corrispondere quando la crittografiamo.  
scrivere un programma che chieda di fornire la chiave come spiegato sopra e che in base a quella crittografi il messaggio inserito*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


bool is_valid_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 charactes\n");
        return 1;
    }
    string s = get_string("plaintext: ");
    string difference = argv[1];
    for (int i = 'A'; i <= 'Z'; i++)
    {
        difference[i - 'A'] = toupper(difference[i - 'A']) - i;  //'B' - 'A'
    }
    printf("ciphertext: ");
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            s[i] = s[i] + difference[s[i] - (isupper(s[i]) ? 'A' : 'a')]; //s[i] -> B' 
        }
        printf("%c", s[i]);
    }
    printf("\n");
}

bool is_valid_key(string s)
{
    int len = strlen(s);
    if (len != 26)
    {
        return false;
    }
    int freq[26] = { 0 };
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
        int index = toupper(s[i]) - 'A';
        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }
    return true;
}
