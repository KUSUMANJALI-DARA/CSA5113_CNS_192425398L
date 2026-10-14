
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char plaintext[200], key[100];
    int i, j = 0, p, k, c;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    scanf("%99s", key);

    int keylen = strlen(key);

    printf("Ciphertext: ");

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)plaintext[i]))
        {
            char ch = toupper((unsigned char)plaintext[i]);
            char keych = toupper((unsigned char)key[j % keylen]);

            p = ch - 'A';
            k = keych - 'A';

            c = (p + k) % 26;

            printf("%c", c + 'A');
            j++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}
