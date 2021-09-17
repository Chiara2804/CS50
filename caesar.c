//Mancarella Chiara
/*Presumibilmente, Cesare (sì, quel Cesare) era solito "crittografare" (cioè nascondere in modo reversibile) i messaggi riservati 
spostando ogni lettera al suo interno di un certo numero di posti. Ad esempio, potrebbe scrivere A come B, B come C, C come D, ... e, 
avvolgendo alfabeticamente, Z come A. E così, per dire CIAO a qualcuno, Cesare potrebbe scrivere IFMP. 
Più formalmente, l'algoritmo di Caesar (cioè il cifrario) crittografa i messaggi "ruotando" ogni lettera di k posizioni. Ruota solo caratteri alfabetici!
Le lettere minuscole rimangono minuscole e le lettere maiuscole rimangono maiuscole. 
scrivere un programma che crittografi quello che inserisce l'utente*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
bool check_valid_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !check_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("palintext: ");
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char m = 'A';
            if (islower(c))
            {
                m = 'a';
            }
            printf("%c", (c - m + key) % 26 + m);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

bool check_valid_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
