#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node *izdvoji(char *buffer)
{
    node *studenti;
    init(&studenti);

    int brojStudenta = *(int *)buffer;
    student *tmp = (student *)(buffer + 4);

    for(int i = 0; i < brojStudenta; i++, tmp++)
        if(tmp -> brIspita > 5)
            addBegin(studenti, *tmp);

    return studenti;
}

void ispisiStudente(node *l)
{
    // ispis studenata
    node *t = l -> next;
    while (t != l) {
        printf("\nIme: %s\n", t -> data.ime);
        printf("Prezime: %s\n", t -> data.prezime);
        printf("INDEKS: %s\n", t -> data.brIndeksa);
        printf("BR ISPITA: %d\n", t -> data.brIspita);
        t = t -> next;
    }
}

int main(void)
{
    node *l;
    student st;
    int n, i;
    init(&l);

    // ucitavanje studenata
    printf("Unesite broj studenata: ");
    scanf("%d", &n);

    char *buffer = (char *)malloc(n * sizeof(student) + 4);
    int *brN = (int *)buffer;

    *brN = n;

    student *upis = (student *)(buffer + 4);

    for (i = 0; i < n; i++) {
        printf("\nUnesite podatke o studentu broj %d: \n", i + 1);

        printf("\tIme: ");
        scanf("%s", st.ime);

        printf("\tPrezime: ");
        scanf("%s", st.prezime);

        printf("\tIndeks: ");
        scanf("%s", st.brIndeksa);

        printf("\tBroj ispita: ");
        scanf("%d", &st.brIspita);

        upis[i] = st;
    }

    node *studenti = izdvoji(buffer);

    printf("\n------------------------ STUDENTI ------------------------\n");
    ispisiStudente(studenti);

    free(buffer);

    return 0;
}
