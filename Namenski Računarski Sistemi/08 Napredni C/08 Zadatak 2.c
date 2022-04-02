#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int provera(int);

int pozitivan(int x) { return (x >= 0 ? 1 : 0); }
int negativan(int x) { return (x <  0 ? 1 : 0); }

int *izdvoj(int *buffer, provera *znakBroja) {
    int ukupnoBrojeva = *buffer, brojac = 0;
    int *brojevi = buffer + 1;
    int niz[ukupnoBrojeva];

    for(int i = 0; i < ukupnoBrojeva; i++)
        if((* znakBroja) (brojevi[i])) {
            niz[brojac] = brojevi[i];
            brojac++;
        }

    int *izdvojeno = (int *) malloc(sizeof(int) * brojac + 1);
    *izdvojeno = brojac;
    int *br = izdvojeno + 1;

    for(int i = 0; i < brojac; i++)
        br[i] = niz[i];

    return izdvojeno;
}

int main(void)
{
    int n = 0;

    while(n < 1) {
        printf("Unesite velicinu niza\n>> ");
        scanf("%d", &n);
        printf("\n");
    }

    int *buffer = (int *) malloc(sizeof(int *) * n + 1);
    *buffer = n;

    int *brojevi = buffer + 1;

    printf("Unos elemenata niza\n>> ");
    for(int i = 0; i < n; i++)
        scanf("%d", &brojevi[i]);

     {
        int *buffer1 = buffer;
        int *izdvojeno = izdvoj(buffer1, pozitivan), *tmp = izdvojeno;

        if(*tmp == 0)
            printf("\n[NEMA POZITIVNIH BROJEVA!]");
        else {
            printf("\nNIZ POZITIVNIH: ");
            for(int i = 0; i < *izdvojeno; i++)
                printf("%d ", *(++tmp));
        }
        free(izdvojeno);
    }

    {
        int *buffer1 = buffer;
        int *izdvojeno = izdvoj(buffer1, negativan), *tmp = izdvojeno;

        if(*tmp == 0)
            printf("\n[NEMA NEGATIVNIH BROJEVA!]");
        else {
            printf("\nNIZ NEGATIVNIH: ");
            for(int i = 0; i < *izdvojeno; i++)
                printf("%d ", *(++tmp));
        }
        free(izdvojeno);
    }
    printf("\n");
    free(buffer);

    return 0;
}
