#include <stdio.h>
#include <stdlib.h>

enum operacija{sabiranje, oduzimanje, mnozenje, deljenje};

float* Calculate(char* buffer)
{
    int *operandi = (int *)(buffer + sizeof(char));
    float *rezultat = (float *)malloc(sizeof(float));

    if(buffer[0] == sabiranje)
        *rezultat = (float)(1. * operandi[0] + operandi[1]);
    else if(buffer[0] == oduzimanje)
        *rezultat = (float)(1. * operandi[0] - operandi[1]);
    else if(buffer[0] == mnozenje)
        *rezultat = (float)(1. * operandi[0] * operandi[1]);
    else
        *rezultat = (float)(1. * operandi[0] / operandi[1]);

    return rezultat;
}

int main(void)
{
    char *bufferParametri = (char *)malloc(sizeof(char) + 2 * sizeof(int));
    char operacija;

    printf("Unesite operaciju: ");
    scanf("%c", &operacija);

    if(operacija == '+')
        bufferParametri[0] = sabiranje;
    else if(operacija == '-')
        bufferParametri[0] = oduzimanje;
    else if(operacija == '*')
        bufferParametri[0] = mnozenje;
    else
        bufferParametri[0] = deljenje;

    int op1, op2;

    printf("Unesite dva broja: ");
    scanf("%d %d", &op1, &op2);

    int *operandi = (int *)(bufferParametri + sizeof(char));
    operandi[0] = op1, operandi[1] = op2;

    float *rezultat = Calculate(bufferParametri);
    printf("\nRezultat: %.3f", *rezultat);

    free(bufferParametri);
    free(rezultat);

    return 0;
}
