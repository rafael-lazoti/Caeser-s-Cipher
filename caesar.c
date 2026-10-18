#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(string key_input);
int zero_checker(int n);
void rotate(char c, int key);

int main(int argc, string argv[]) // argc = how many args(2)|argv = array of str for args
{

    if (argc == 2)
    {
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // ensures single line command argument

    only_digits(argv[1]);

    int digit = atoi(argv[1]);
    zero_checker(digit);

    printf("The valid key is: %i\n", digit);

    string plain_text = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plain_text); i < n; i++)

    {
        char c = plain_text[i];
        rotate(c, digit);
    }

    printf("\n");

    return 0;
}

int only_digits(string key_input) // only accpets digits in the command line argument, if not, prints usage and exits program
{
    for (int i = 0, n = strlen(key_input); i < n; i++)
    {
        char c = key_input[i];
        if (isdigit(c))
        {
            continue;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }
    return 0;
}
int zero_checker(int n)

{
    if (n == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        return 0;
    }
}
void rotate(char c, int key) // rotates the character c by the key value and prints the result
{
    char c1 = 0;
    if (isalpha(c) && isupper(c))
    {
        c1 = ((c - 65 + key) % 26) + 65;
        printf("%c", c1);
    }
    else if (isalpha(c) && islower(c))
    {

        c1 = ((c - 97 + key) % 26) + 97;
        printf("%c", c1);
    }

    else
    {
        printf("%c", c);
    }
}
