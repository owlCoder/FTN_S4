#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    short brojOsoba = *(short *)buffer;
    int velicina = sizeof(Osoba), maxOsobaIndex = 0;

    for(int i = 1; i < brojOsoba; i++) {
        short *dan1    = (short *) &buffer[26 + maxOsobaIndex * velicina + 2];
        short *mesec1  = (short *) &buffer[28 + maxOsobaIndex * velicina + 2];
        short *godina1 = (short *) &buffer[30 + maxOsobaIndex * velicina + 2];

        short *dan2    = (short *) &buffer[26 + i * velicina + 2];
        short *mesec2  = (short *) &buffer[28 + i * velicina + 2];
        short *godina2 = (short *) &buffer[30 + i * velicina + 2];

        if(!(*godina1 < *godina2 ||
       (*godina1 == *godina2 && *mesec1 < *mesec2) ||
       (*godina1 == *godina2 && *mesec1 == *mesec2 && *dan1 < *dan2) ))
            maxOsobaIndex = i;
    }
    const unsigned index = maxOsobaIndex * velicina;
    printf("Ime: %s\nPrezime: %s\nPol: %c\nJMBG: %s",
            buffer + index + 2, (buffer + index + 14), *(buffer + index + 26), (buffer + index + 34));

}
int main(void)
{
    Osoba o[3];
    char *buffer = (char *)malloc(sizeof(o) + 2);

    o[0] = (Osoba) {
        "Danijel",
        "Jovanovic",
        'M',
        12,
        1,
        2001,
        "0123456789123"
    };

    o[1] = (Osoba) {
        "Milena",
        "Kovac",
        'Z',
        15,
        1,
        2001,
        "0123666789123"
    };

    o[2] = (Osoba) {
        "Marijana",
        "Lenic",
        'Z',
        21,
        1,
        2001,
        "0163666789123"
    };

    const short brojOsoba = 3;
    short *br = (short *)buffer;

    *br = brojOsoba;
    memcpy(buffer + 2, &o, sizeof(o));

    ispisStariju(buffer);
    free(buffer);

    return 0;
}
