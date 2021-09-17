//Mancarella Chiara
/*Verso l'inizio del Mondo 1-1 in Super Mario Brothers di Nintendo, Mario deve saltare su piramidi di blocchi adiacenti.
permettiamo all'utente di decidere quanto devono essere alte le piramidi chiedendogli prima un numero intero positivo compreso tra, ad esempio, 1 e 8 inclusi.*/

#include <stdio.h>

int main(void)
{
    int n, k, j, z, i; //declaration

    printf("Quanto devono essere alte le piramidi? (inserisci un numero tra 1 e 8 inclusi).\n");
    
    //entro nel ciclo la prima volta e...
	do
    {
        printf("Altezza: "); //richiesta dell'altezza
        scanf("%d", &n); //leggo il valore della variabile
    }
    while (n < 1 || n > 8); //...ripeto finchè il numero inserito è compreso tra 1 e 8 inclusi
    
    printf("\n");
    
	//ciclo per disegnare le piramidi
	for (i = 1; i <= n; i++) 
    {
    	//inizio disegno prima piramide
        for (j = 1; j <= n - i; j++) //ripeto il ciclo finchè il contatore è minore di n - 1, quindi gli spazi vuoti prima della piramide sono diventati 0 (ci saranno solo cubetti pieni)
            printf(" "); //spazio prima di ogni cubetto pieno "         #"
            
        for (k = 0; k <= i - 1; k++) //ripeto il ciclo finchè non riempio tutta la riga di cubetti
            printf("#"); //cubetto pieno
        //fine disegno prima piramide
        
        printf("  "); //spazio fisso tra le due piramidi
        
        //inizio disegno seconda piramide
        for (z = 0; z <= i - 1; z++) 
            printf("#");
		//fine disegno seconda piramide
		//in questo caso non serve lo spazio vuoto
        
        printf("\n");
    }
}
