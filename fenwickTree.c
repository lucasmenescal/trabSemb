#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <stdio.h>
#include <time.h>

const int MAX = 2001;

int lista[2001]; //array de 2000 numeros

void update(int k, int v)
{
	while (k < MAX)
	{
		lista[k] += v;
		k += (k & -k);
	}
}

int rsq(int b)
{
	int teste = 0;
	int v[2001];
	srand(time(NULL));
	for (int i = 1; i <= MAX; i++)
	{
		v[i] = 1;
	}
	memset(lista, 0, sizeof lista);

	for (int i = 1; i <= MAX; i++)
	{
		update(i, v[i]);
	}

	int soma = 0;
	int count = 0;

	while (b > 0)
	{
		soma += lista[b];
		b -= (b & -b);
		count += 1;
	}

	//printf("Foram feitas %d interecoes com a Arvore de Feniwick. \n", count);

	count = 0;

	//Soma Ingenua.
	for (int i = 1; i <= MAX - 1; i++)
	{
		teste += v[i];
		//count += 1;
		//printf("%d \n", teste);
	}
	//Fim soma Ingenua.

	printf("Foram feitas %d interecoes com a soma normal. \n", count);
	printf("O resultado da soma 'normal' e: %d \n", teste);

	//Atualizando e fazendo a soma novamente:
	int novo = 3;
	int pos = 1920;
	for (int i = 1; i <= MAX - 1; i++)
	{
		//Atualização por Fenwick
		update(pos, novo - v[pos]);
		printf("A soma atualizada, Arvore de Fenwick e: %d", rsq(MAX - 1));
	}

	return soma;
}

int main()
{

	printf("A soma feita pela Arvore de Fenwick e: %d", rsq(MAX - 1));
	return 0;
}