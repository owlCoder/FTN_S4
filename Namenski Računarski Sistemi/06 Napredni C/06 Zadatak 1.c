#include <stdio.h>
#include <stdlib.h>

#pragma pack(4)

typedef struct
{
    char ime[12];
    char prezime[12];
    char pol;
    short danR, mesecR, godinaR;
    char JMBG[14];
} Osoba;

void ispisStariju(char *buffer) {
    short *dan1    = (short *) &buffer[26];
    short *mesec1  = (short *) &buffer[28];
    short *godina1 = (short *) &buffer[30];

    int velicina = sizeof(Osoba);

    short *dan2    = (short *) &buffer[26 + velicina];
    short *mesec2  = (short *) &buffer[28 + velicina];
    short *godina2 = (short *) &buffer[30 + velicina];

    if(*godina1 < *godina2 ||
       (*godina1 == *godina2 && *mesec1 < *mesec2) ||
       (*godina1 == *godina2 && *mesec1 == *mesec2 && *dan1 < *dan2) )
        printf("Ime: %s\nPrezime: %s\nPol: %c\nJMBG: %s",
                buffer, (buffer + 12), *(buffer + 24), (buffer + 32));
    else
        printf("Ime: %s\nPrezime: %s\nPol: %c\nJMBG: %s",
                (buffer + velicina), (buffer + 12 + velicina), *(buffer + 24 + velicina), (buffer + 32 + velicina));
}
int main(void)
{
    Osoba o[2];

    o[0] = (Osoba) {
        "Danijel",
        "Jovanovic",
        'M',
        19,
        1,
        2001,
        "0123456789123"
    };

    o[1] = (Osoba) {
        "Milena",
        "Kovac",
        'Z',
        18,
        1,
        2001,
        "0123666789123"
    };

    ispisStariju((char *)o);

    return 0;
}
