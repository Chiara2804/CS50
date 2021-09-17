/*Verso la fine del Mondo 1-1 in Super Mario Brothers di Nintendo, Mario deve salire sulla piramide di blocchi allineata a destra, come in basso.
E permettiamo all'utente di decidere quanto deve essere alta la piramide chiedendogli prima un numero intero positivo compreso tra, diciamo, 1 e 8 inclusi.*/


#include <stdio.h>

int main(void)
{
    int Height, i, j, k;
    printf("Write a number between 1 and 8 inclusive for the size of the pyramid\n");
    do                            
    {
    	printf("Height: ");
        scanf("%d", &Height);        //I prompt the height of the pyramid
    }
    while (Height > 8 || Height < 1); //I repeat this, while the number isn't included between 1 and 8
    
	for (i = 1; i <= Height; i++) //I build the pyramid
    { 
        for (j = 1; j <= Height - i; j++)
        {
            printf(" ");
        }
        for (k = 0; k <= i - 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }     
}

