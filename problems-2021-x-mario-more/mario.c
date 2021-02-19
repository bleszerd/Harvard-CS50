#include <cs50.h>
#include <stdio.h>

int printBricks(int n)
{
    //Verify input conditions
    if (n <= 0 || n == 9)
    {
        return -1;
    }

    for (int i = 0; i < n; i++) // Rule of rows
    {
        for (int j = 0; j < n; j++) // Rule of columns
        {
            if (n - i > j + 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
                if (j == n - 1)
                {
                    printf("  "); // Last column only
                    for (int k = i + 1; k > n - n; k--)
                    {
                        printf("#");
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}

int main(void)
{
    int n;

    //While input isn't valid, do this code section again...
    do
    {
        n = get_int("How rows?\n=> ");

    }
    while (printBricks(n) != 0);

    return 0;
}

/*
4 - 0 > 0 + 1       =       4 > 1       =       " "
4 - 0 > 1 + 1       =       4 > 2       =       " "
4 - 0 > 2 + 1       =       4 > 3       =       " "
4 - 0 > 3 + 1       =       4 > 4       =       "#"
4 - 1 > 0 + 1       =       3 > 1       =       " "
4 - 1 > 0 + 1       =       3 > 2       =       " "
4 - 1 > 0 + 1       =       3 > 3       =       "#"
4 - 1 > 0 + 1       =       3 > 4       =       "#"
...                 =       ...         =       ...
*/