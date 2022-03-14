#include <stdio.h>
#include <stdlib.h>

int* CalculateMinMax(char* buffer)
{
    int *rez = malloc(2 * sizeof(int));
    int N = (int)(*buffer);
    int *niz = (int *)(buffer + sizeof(short));

    rez[0] = niz[0];
    rez[1] = niz[0];

    for(int i = 1; i < N; i++) {
        if(niz[i] < rez[0])
            rez[0] = niz[i];

        if(niz[i] > rez[1])
            rez[1] = niz[i];
    }
    return rez;
}

int main(void)
{
    short N;

    do {
        printf("Unesite N\n>> ");
        scanf("%hu", &N);
        printf("\n");
    } while(N <= 1);

    int *niz = malloc(N * sizeof(int));

    printf("Unos niza\n");
    for(int i = 0; i < N; i++) {
        printf("\tniz[%d] = ", i);
        scanf("%d", niz + i);
    }

    char *buffer = malloc(N * sizeof(int) + sizeof(short));
    buffer[0] = (char)N;

    int *brojevi = (int *)(buffer + sizeof(short));
    for(int i = 0; i < N; i++)
        brojevi[i] = niz[i];

    free(niz);

    int *rez = CalculateMinMax(buffer);
    printf("\nMin = %d, Max = %d\n", rez[0], rez[1]);

    free(rez);

    return 0;
}
