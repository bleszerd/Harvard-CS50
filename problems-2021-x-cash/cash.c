#include <stdio.h>
#include <cs50.h>
#include <math.h>

int calcMoney()
{
    int coinCount = 0;
    float dollars = 0;

    //check for a valid input
    do
    {
        dollars = get_float("How money?\n=> ");
    }
    while (dollars <= 0);

    //convert dollars to cents
    int cents = round(dollars * 100);

    //do operations to count coins
    while (cents >= 25)
    {
        coinCount += 1;
        cents -= 25;
    }

    while (cents >= 10)
    {
        coinCount += 1;
        cents -= 10;
    }

    while (cents >= 5)
    {
        coinCount += 1;
        cents -= 5;
    }

    while (cents >= 1)
    {
        coinCount += 1;
        cents -= 1;
    }

    return coinCount;

}

int main(void)
{
    //print quantity of coins
    printf("%i\n", calcMoney());
    return 0;
}