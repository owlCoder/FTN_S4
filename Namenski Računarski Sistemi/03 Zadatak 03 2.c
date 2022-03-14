#include <stdio.h>
#include <stdlib.h>

void copyLEToLE(int x, void* copy){
   for(unsigned i=0; i<sizeof(x); i++){
      *((char*)copy+i) = *((char *)&x +i);
   }
}

void copyLEToBE(int x, void* copy){
   for(unsigned i=0; i<sizeof(x); i++){
      *((char*)copy+i) = *((char *)&x +sizeof(x)-1-i);
   }
}

int Count(char* buffer)
{
    int brojac = 0;

    return brojac;
}

int main(void)
{
    short N;
    do {
        printf("Unesite broj elemenata niza: ");
        scanf("%hd", &N);
    } while(N <= 1);

    double *niz1 = (double *)malloc(sizeof(double) * N);
    double *niz2 = (double *)malloc(sizeof(double) * N);

    printf("\nNiz1: ");
    for(int i = 0; i < N; i++)
        scanf("%lf", (niz1 + i));

     printf("Niz2: ");
    for(int i = 0; i < N; i++)
        scanf("%lf", (niz2 + i));

    char *buffer = (char *)malloc(sizeof(char) + (short) + 2 * N * sizeof(double));

    char LB;

     do {
        printf("Unesite L ili B: ");
        scanf("%c", &LB);
        fflush(stdin);
    } while(LB != 'L' && LB != 'B');

    buffer[0] = LB;
    *(short *)(buffer + 1) = N;
    double *brojevi = (double *)(buffer + 3);

    int j = 0;
    for(int i = 0; i < N; i++)
        brojevi[j++] = niz1[i];

    for(int i = 0; i < N; i++)
        brojevi[j++] = niz2[i];

        /* to do
    if(LB == 'B') {
        for(int i = 0; i < N; i++) {
            int br = niz[i];
            copyLEToBE(br, niz1[i]);
        }


    }
    else {
        copyLEToLE(broj1, brojevi);
        copyLEToLE(broj2, brojevi + 1);
    }
    */
    printf("\nVecih elemenata ima: %d\n", Count(buffer));

    free(niz1);
    free(niz2);
    free(buffer);

    return 0;
}
