#include <stdio.h>
#include <stdlib.h>


int verificare(char *a, char *b)
{
    if(*a == *b && *b == '\0') return 1;

    if(*a != *b) return 0;

    return verificare(a + 1, b + 1);
}

int main()
{
    int n;
    scanf("%d ", &n);

    char* cuv = (char*)malloc(sizeof(char));
    char** vect = (char**)malloc(sizeof(char*));
    int* counter = (int*)malloc(sizeof(int));
    int k = 0;
    int h = 0;
    char c;

label:
    scanf("%c", &c);

    if(c != '\n' && c != ' ')
    {
        cuv[k++] = c;
        cuv = (char*)realloc(cuv, sizeof(char)*(k + 1));

        goto label;
    }

    cuv[k] = '\0';
    vect[0] = (char*)malloc(sizeof(char) * (k + 1));

    for(int i = 0; i <= k; i++)
        vect[0][i] = cuv[i];

    counter[0] = 1;


    for(int i = 2; i <= n; i++)
    {
        k = 0;

label2:
        scanf("%c", &c);

        if(c != '\n' && c != ' ')
        {
            cuv[k] = c;

            k++;
            cuv = (char*)realloc(cuv, sizeof(char)*(k + 1));

            goto label2;
        }

        cuv[k] = '\0';

        if(cuv[0] == '\0')
            goto label2;

        int ok = 1;


        for(int j = 0; j <=h; j++)
        {
            if(verificare(cuv, vect[j]))
            {

                counter[j]++;
                ok = 0;
                break;
            }
        }

        if(ok)
        {
            h++;
            vect = (char**)realloc(vect, sizeof(char*) * (h + 1));
            counter = (int*)realloc(counter, sizeof(int) * (h + 1));
            vect[h] = (char*)malloc(sizeof(char) * (k + 1));

            for(int l = 0; l <= k; l++)
            {
                vect[h][l] = cuv[l];
            }

            counter[h] = 1;

        }
    }

    for(int i = 0; i <= h; i++)
    {
        for(int j = 0; vect[i][j] != '\0'; j++)
            printf("%c", vect[i][j]);

        printf(" = %d\n", counter[i]);
    }

    free(cuv);
    free(counter);
    free(vect);

    return 0;
}
