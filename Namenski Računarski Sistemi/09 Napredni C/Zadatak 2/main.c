#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "ispit.h"
#pragma pack(4)

typedef bool polozenIspit(int);

char *citanjePodatakaIUpisUBafer(void);
int ucitajSifruIsputnogRokaBaza16();
bool dobarZnak(char);
int prebroj(char *, polozenIspit *);

bool polozen(int ocena)
{
    return (ocena >= 6 ? true : false);
}

int main()
{
    /// ZADATAK POD A
    char *buffer = citanjePodatakaIUpisUBafer();
    ispisPodatke(buffer);

    /// ZADATAK POD B
    /// UNOSI SE SIFRA ISPITNOG ROKA --> U SASTAVU POZIVA F-JE POD A

    /// ZADATAK POD C
    int polozenih = prebroj(buffer, polozen);

    if(polozenih == 0)
        printf("\nNEMA POLOZENIH ISPITA!\n");
    else
        printf("\nBROJ POLOZENIH ISPITA JE: %d ISPIT/A.\n", polozenih);

    return 0;
}

char *citanjePodatakaIUpisUBafer()
{
    int N, M;

    printf("Unesite dimenziju N\n>> ");
    scanf("%d", &N);

    printf("\nUnesite dimenziju M\n>> ");
    scanf("%d", &M);

    char *buffer = (char *) malloc(2 * sizeof(int)
                               + N * M * sizeof(ispit));

    /// DIREKTAN PRISTUP MEMORIJI
    *((int *) buffer) = N;
    *((int *) buffer + 1) = M;
    char *podaci = buffer + 2 * sizeof(int);

    for(int i = 0; i < N; i++)
    {
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

            /// ZADATAK POD B
            *sifra = ucitajSifruIsputnogRokaBaza16();

            /// ZADATAK POD A
            // printf("\tSifra Ispitnog Roka: ");
            // scanf("%d", sifra);

            printf("\tProfesor: ");
            scanf(" %s", prof);
        }
    }

        return buffer;
}

/// ZADATAK POD B
int ucitajSifruIsputnogRokaBaza16()
{
    char ucitano[10];
    int broj = -1, i;

    while(true)
    {
        printf("\tSifra Ispitnog Roka: ");
        scanf(" %s", ucitano);

        for(i = 0; i < strlen(ucitano); i++)
        {
            if(dobarZnak(ucitano[i]))
                continue;
            else
                break;
        }

        if(i == strlen(ucitano))
            break;
    }

    broj = (int) strtol(ucitano, NULL, 16);

    return broj;
}

bool dobarZnak(char c)
{
    c = tolower(c);

    return ( (c >= '0' && c <= '9') ||
             (c == 'a' || c == 'b'  || c == 'c' || c == 'd' || c == 'e' || c == 'f'));
}

/// ZADATAK POD C
int prebroj(char *buffer, polozenIspit *p)
{
    int brojac = 0;

    /// DIREKTAN PRISTUP MEMORIJI
    int N = *buffer, M = *(buffer + sizeof(int));
    char *podaci = buffer + 2 * sizeof(int);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {

            char  *ocena  = ((char  *) (podaci + (i * M + j) * sizeof(ispit) + 6));
            int ocenaInt = *ocena - '0'; // iz char u int

            if( p(ocenaInt) )
                brojac++;
        }
    }

    return brojac;
}
