#include <stdio.h>
#include <stdlib.h>

enum kop { sabiranje, oduzimanje, mnozenje, deljenje };
float * Calculate(const char *inBuff);

int main(int argc, char *argv[])
{
		//zauzimamo bafer koji cemo proslediti funkciji
	char *p_ParametarFunkcije = (char*)malloc(sizeof(char)+2 * sizeof(int));
	char operacija;

	printf("Unesite operaciju koju zelite da koristite : ");
	scanf("%c", &operacija);
    fflush(stdin);

	if (operacija == '+')
		p_ParametarFunkcije[0] = sabiranje; //kod operacije u prvi bajt
	else if (operacija == '-')
		p_ParametarFunkcije[0] = oduzimanje;
	else if (operacija == '*')
		p_ParametarFunkcije[0] = mnozenje;
	else if (operacija == '/')
		p_ParametarFunkcije[0] = deljenje;
	else return 0;

	int op1, op2;

	printf("Unesite prvi broj : ");
	scanf("%d", &op1);
	getchar();

	printf("Unesite drugi broj : ");
	scanf("%d", &op2);
	getchar();

	int *operand = (int *)(p_ParametarFunkcije + sizeof(char));

		//smestamo operande na njihovu poyiciju u baferu
	operand[0] = op1;
	operand[1] = op2;

	float *rezultat;

	rezultat = Calculate(p_ParametarFunkcije);
	printf("Resenje je : %f\n", *rezultat);
	free(rezultat);
	free(p_ParametarFunkcije);
	return 0;
}

float * Calculate(const char *inBuff)
{
	int *operand = (int*)(inBuff + 1);
	float *rez=NULL;
	rez = (float*)malloc(sizeof(float));

	switch (inBuff[0])
	{
	case sabiranje:
		*rez = (float)(operand[0] + operand[1]);
		break;
	case oduzimanje:
		*rez = (float)(operand[0] - operand[1]);
		break;
	case mnozenje:
		*rez = (float)(operand[0] * operand[1]);
		break;
	case deljenje:
		*rez = (float)operand[0] / operand[1];
		break;
	}

	return  rez;
}
