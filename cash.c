//Mancarella Chiara cs50
//questo programma per un importo pagato dice quante monete di resto dare utilizzandone il meno possibile

#include <stdio.h>
#include <cs50.h>
#define QUARTERS 25
#define DIMES 10
#define NICKELS 5
#define PENNIES 1

int main(void)
{
    double c; 
    int dollars, quo, tot;

    do
    {
        c = get_double("Change owed:  ");
    }
    while (c < 0); //repeat this while insert the correct number
    double round(double c);  
    dollars = c * 100; 
    if (dollars >= 25)
    {
        quo = dollars / QUARTERS; //FOR QUARTERS
        tot = quo;
        dollars = dollars - (quo * QUARTERS);
        printf("%i\n", quo);
    }
    if (dollars < 25 && dollars >= 10)
    {
        quo = dollars / DIMES; //FOR DIMES
        tot = tot + quo;
        dollars = dollars - (quo * DIMES);
        printf("%i\n", quo);
    }
    if (dollars < 10 && dollars >= 5)
    {
        quo = dollars / NICKELS; //FOR NICKELS
        tot = tot + quo;
        dollars = dollars - (quo * NICKELS); 
        printf("%i\n", quo);
    }
    if (dollars < 5 && dollars >= 1)
    {
        quo = dollars / PENNIES; //FOR PENNIES
        tot = tot + quo;
        dollars = dollars - (quo * PENNIES);
        printf("%i\n", quo);
    }
    printf("%i\n", tot);
}
