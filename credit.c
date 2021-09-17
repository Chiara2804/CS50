//Mancarella Chiara
//questo programma chiede di inserire il numero della propria carta e poi dice se quella carta è valida o no in base ad un algoritmo

#include <stdio.h>
#include <cs50.h>
#define EX1 340000000000000
#define EX2 370000000000000
#define MASTER1 5100000000000000
#define MASTER5 5500000000000000
#define VISA1 4000000000000
#define VISA2 4000000000000000
#define T 10
#define H 100

int main(void)
{
    long n; //card's number
    int tot = 0, a = 0, sum = 0, r = 0;
    do
    {
        n = get_long("Number: ");
    }
    while ((n <= EX1 && n >= (EX1 + 9999999999999)) || (n <= EX2 && n >= (EX2 + 9999999999999)) || (n <= VISA1
            && n >= (VISA1 + 999999999999)) || (n <= VISA2 && n >= (VISA2 + 999999999999999)) || (n <= MASTER1
                    && n >= (MASTER5 + 9999999999999999))); //repeat this while there is no correct number
    do//algorithm to verify the validity
    {
        tot = n % T;
        a = tot * 2;
        sum = sum + a;
        n = n - tot;
        r = n / T;
    }
    while (tot == 0);  //1.
    do
    {
        tot = n % H;
        sum = sum + tot;
        n = n - tot;
        r = n / T;
    }
    while (tot == 0); //2.
    if (sum / T) //if the number finish by 0
    {
        if ((n >= EX1 && n <= (EX1 + 9999999999999)) || (n >= EX2 && n <= (EX2 + 9999999999999)))
        {
            printf("AMEX\n");
        }
        else if ((n >= VISA1 && n <= (VISA1 + 999999999999)) || (n >= VISA2 && n <= (VISA2 + 999999999999999)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("MASTERCARD\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }
}
