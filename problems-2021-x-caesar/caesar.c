#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    string string_rest;
    string plaintext;

    //Verify input count
    if (argv[1] && !argv[2])
    {
        //split key and string values
        int key = (int)strtol(argv[1], &string_rest, 10);

        //validate for positive number
        if (key >= 0)
        {
            if (*string_rest)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }

            plaintext = get_string("plaintext: ");
            int plain_len = strlen(plaintext);

            char cyphertext[plain_len];

            //encrypt phase
            for (int i = 0; i < plain_len; i++)
            {
                if (isalpha(plaintext[i]))
                {
                    int result = (int)plaintext[i] + key;
                    while (result > 'z') //if number exceeds printed scope, reformat it
                    {
                        result -= 26;
                    }

                    cyphertext[i] = result;
                }
                else
                {
                    cyphertext[i] = plaintext[i];
                }
            }

            printf("ciphertext: %s\n", cyphertext);
            return 0;
        }
    }

    printf("Usage: ./caesar key\n");
    return 1;
}