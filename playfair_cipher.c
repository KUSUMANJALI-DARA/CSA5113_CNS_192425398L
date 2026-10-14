
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[100], text[200], matrix[5][5];
    char used[26] = {0};
    int i, j, r, c, k = 0;

    printf("Enter keyword: ");
    scanf("%99s", key);

    printf("Enter plaintext: ");
    scanf(" %199[^\n]", text);

    /* Create the 5 x 5 key matrix */
    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);
        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    /* Add remaining letters, combining I and J */
    for (i = 0; i < 26; i++)
    {
        if (i == ('J' - 'A'))
            continue;

        if (!used[i])
        {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }

    printf("\nPlayfair Matrix:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    /* Prepare plaintext: remove spaces, replace J with I */
    char clean[200], cipher[200];
    int n = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            char ch = toupper((unsigned char)text[i]);
            if (ch == 'J')
                ch = 'I';
            clean[n++] = ch;
        }
    }
    clean[n] = '\0';

    /* Encrypt two letters at a time */
    printf("\nCiphertext: ");

    for (i = 0; i < n; i += 2)
    {
        char a = clean[i];
        char b;

        if (i + 1 >= n)
            b = 'X';
        else if (clean[i] == clean[i + 1])
            b = 'X';
        else
            b = clean[i + 1];

        int r1, c1, r2, c2;

        for (r = 0; r < 5; r++)
            for (c = 0; c < 5; c++)
            {
                if (matrix[r][c] == a)
                    r1 = r, c1 = c;
                if (matrix[r][c] == b)
                    r2 = r, c2 = c;
            }

        if (r1 == r2)
        {
            cipher[i] = matrix[r1][(c1 + 1) % 5];
            cipher[i + 1] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            cipher[i] = matrix[(r1 + 1) % 5][c1];
            cipher[i + 1] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            cipher[i] = matrix[r1][c2];
            cipher[i + 1] = matrix[r2][c1];
        }

        printf("%c%c", cipher[i], cipher[i + 1]);

        if (i + 2 < n)
            printf(" ");
        
        if (i + 1 >= n || clean[i] == clean[i + 1])
            i--;
    }

    printf("\n");
    return 0;
}
