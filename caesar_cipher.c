#include <stdio.h>

int main()
{
    char plaintext[100], ciphertext[100];
    int k, i, p, c;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key k (1-25): ");
    scanf("%d", &k);

    if (k < 1 || k > 25)
    {
        printf("Invalid key. Enter a value between 1 and 25.");
        return 0;
    }

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            p = plaintext[i] - 'A';
            c = (p + k) % 26;
            ciphertext[i] = c + 'A';
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            p = plaintext[i] - 'a';
            c = (p + k) % 26;
            ciphertext[i] = c + 'a';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';

    printf("Ciphertext: %s", ciphertext);

    return 0;
}
