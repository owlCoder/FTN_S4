#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int konverzija(char *s) {
    int x = 0;
    int n = strlen(s);

    for(int i = n - 1, j = 0; i >= 0; i--)
        x += (s[i] - '0') * pow(2, j++);

    return x;
}

int main(void)
{
    char str[32];

    printf("Unesite binarni broj: ");
    gets(str);

    int db = konverzija(str);
    printf("BIN: %s --> DEK: %d\n", str, db);

    return 0;
}
