#include "izraz.h"
#include "list.h"
#pragma pack(4)

void izracunaj(char *buffer)
{
    int n = *((int *) buffer);
    int i, rez, velicina = sizeof(izraz);
    short br1, br2;
    char op;

    for(i = 0; i < n; i++)
    {
        br1 = *((short *)(buffer + sizeof(int) + i * velicina));
        op = *(buffer + sizeof(int) + i * velicina + 2);
        br2 = *((short*)(buffer + sizeof(int) + i * velicina + 4));

        if (op == '+')
            rez = br1 + br2;
        else if (op == '-')
            rez = br1 - br2;
        else if (op == '*')
            rez = br1 * br2;
        else if (op == '/')
            rez = br1 / br2;

        *((int *)(buffer + sizeof(int) + i * velicina + 8)) = rez;
    }
};

void copyLEToBE(int x, void* copy)
{
    for(int i=0; i<sizeof(x); i++)
        *((char*)copy+i) = *((char *)&x + sizeof(x) - 1 - i);
}

node* izdvoj(char *buffer)
{
    int n = *((int*) buffer);
    int i, rez, rezBE, velicina = sizeof(izraz);
    node* l;
    init(&l);

    for(i=0; i < n; i++)
    {
        rez = *((short*)(buffer + sizeof(int) + i * velicina + 8));
        copyLEToBE(rez, &rezBE);
        addEnd(&l, rezBE);
    }
    return l;
}

int main(void)
{
    char *buffer = napraviNiz();
    ispisNiz(buffer);
    izracunaj(buffer);
    ispisNiz(buffer);

    node *l = izdvoj(buffer);
    node *temp = l -> next;
    int rezBE, rez;

    printf("\nRezultati izraza su: ");
    while (temp != l)
    {
        rezBE = temp -> data;
        copyLEToBE(rezBE, &rez);
        printf("%d ", rez);
        temp = temp -> next;
    }

    return 0;
}
