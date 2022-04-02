#include <stdio.h>
#include <stdlib.h>

typedef int poredjenje(int, int);

int uporediManje(int a, int b) { return a < b; }
int uporediVece(int a, int b)  { return a > b; }

void bubbleSort(int a[], int n, poredjenje *uporedi)
{
    int i, j, t;

    for (j = n - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if ((* uporedi)(a[i+1], a[i]))
            {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
}

int main(void)
{
    int n;

    printf("Unesi broj n: ");
    scanf("%d", &n);

    int i, a[n];

    printf("\nUnesite elemente niza\n>> ");
    for (i=0; i < n; i++)
        scanf("%d", &a[i]);

    bubbleSort(a, n, uporediManje);
    printf("\nNIZ SORTIRAN RASTUCE\n");
    for (i=0; i < n; i++)
        printf("%d ", a[i]);

    bubbleSort(a, n, uporediVece);
    printf("\n\nNIZ SORITRAN OPADAJUCE\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
