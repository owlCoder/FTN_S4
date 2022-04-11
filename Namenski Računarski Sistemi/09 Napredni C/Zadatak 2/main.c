#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ispit.h"
#pragma pack(4)

int main()
{
    char *buffer;
    int N, M;

    printf("Unesite dimenziju N\n>> ");
    scanf("%d", &N);

    printf("\nUnesite dimenziju M\n>> ");
    scanf("%d", &M);

    buffer = (char *) malloc(2 * sizeof(int)
                               + N * M * sizeof(ispit));

    /// DIREKTAN PRISTUP MEMORIJI
    *((int *) buffer) = N;
    *((int *) buffer + 1) = M;
    char *podaci = buffer + 2 * sizeof(int);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            /*
                  8 - dan
                  9 - dan
                 10 - mesec
                 11 - mesec
                 12 - godina
                 13 - godina
                 14 - ocena
                 15 - /
                 16 - sifra
                 17 - sifra
                 18 - sifra
                 19 - sifra
                 20 - prof
                    ....
                 50 - prof
            */
            short *dan    = ((short *) (podaci + (i * M + j) * sizeof(ispit)));
            short *mesec  = ((short *) (podaci + (i * M + j) * sizeof(ispit)+ 2));
            short *godina = ((short *) (podaci + (i * M + j) * sizeof(ispit) + 4));
            char  *ocena  = ((char  *) (podaci + (i * M + j) * sizeof(ispit) + 6));
            int   *sifra  = ((int   *) (podaci + (i * M + j) * sizeof(ispit) + 8));
            char  *prof   = ((char  *) (podaci + (i * M + j) * sizeof(ispit) + 12));

            /// DODAVANJE U BAFER UCITANOG ISPITA
            printf("\nStudent[%d]", i + 1);

            printf("\n\tDan, Mesec, Godina: ");
            scanf("%hd %hd %hd", dan, mesec, godina);

            printf("\tOcena: ");
            scanf(" %c", ocena);
            fflush(stdin);

            printf("\tSifra Ispitnog Roka: ");
            scanf("%d", sifra);

            fflush(stdin);
            printf("\tProfesor: ");
            gets(prof);
        }

    ispisPodatke(buffer);

    return 0;
}
