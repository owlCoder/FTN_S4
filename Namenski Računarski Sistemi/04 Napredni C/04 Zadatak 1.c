#include <stdio.h>
#include <stdlib.h>

char *konverzija(int x) {
    char *bb = (char *)malloc(sizeof(int) * 4 + 1);
    int n = sizeof(int) * 4 - 1;

    bb[0] = (x < 0 ? '1' : '0');

    for(int i = n; i > 0; i--) {
        if(x % 2 == 0)
            bb[i] = '0';
        else
            bb[i] = '1';

        x /= 2;
    }
    bb[n + 1] = '\0';

    return bb;
}

int main(void)
{
    int x;

    printf("Unesite broj: ");
    scanf("%d", &x);

    char *bin = konverzija(x);
    printf("DEK: %d --> BIN: %s\n", x, bin);
    free(bin);

    return 0;
}
