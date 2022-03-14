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

float Calculate(char *buffer)
{
    float rez = 0.;
    int *brojevi = (int *)(buffer + 2);

    int b1 = brojevi[0], b2 = brojevi[1];
    if(buffer[0] == 'B') {
        copyLEToBE(b1, buffer + 2);
        copyLEToBE(b2, buffer + 6);
    }

    if(buffer[1] == '+')
        rez = brojevi[0] + brojevi[1];
    else if(buffer[1] == '-')
        rez = brojevi[0] - brojevi[1];
    else if(buffer[1] == '*')
        rez = brojevi[0] * brojevi[1];
    else
        rez = 1. * brojevi[0] / brojevi[1];

    float r;
    if(buffer[0] == 'B')
        copyLEToBE(*(int*)&rez, &r);
    else
        copyLEToLE(*(int *)&rez, &r);

    return r;
}

int main(void)
{
    char *buffer = (char *)malloc(10);
    char LB, OPERACIJA;

    do {
        printf("Unesite L ili B: ");
        scanf("%c", &LB);
        fflush(stdin);
    } while(LB != 'L' && LB != 'B');

    buffer[0] = LB;

    printf("\n");
     do {
        printf("Unesite +, -, *, /: ");
        scanf("%c", &OPERACIJA);
        fflush(stdin);
    } while(OPERACIJA != '+' && OPERACIJA != '-'
                      && OPERACIJA != '*' && OPERACIJA != '/');
    buffer[1] = OPERACIJA;

    int broj1, broj2;

    printf("\nUnesite 2 broja: ");
    scanf("%d %d", &broj1, &broj2);

    int *brojevi = (int *)(buffer + 2);
    if(LB == 'B') {
        copyLEToBE(broj1, brojevi);
        copyLEToBE(broj2, brojevi + 1);
    }
    else {
        copyLEToLE(broj1, brojevi);
        copyLEToLE(broj2, brojevi + 1);
    }

    float rezultat = Calculate(buffer), r = rezultat;
    if(buffer[0] == 'B')
        copyLEToBE(*(int*)&rezultat, &r);

    printf("\nRezultat: %.2f", r);

    free(buffer);

    return 0;
}
