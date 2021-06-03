
#include <conio.h>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <stdio.h>
#include <string.h>
#include <time.h> //necessário p/ função time()

const int MAX = 20;

int lista[20];

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
	int soma = 0;
	while (b > 0)
	{
		soma += lista[b];
		b -= (b & -b);
	}
	return soma;
}

int main()
{
	int v[] = {1, 3, 2, 4, 1, 2, 5, 3, 6, 4, 7, 1, 9, 6, 5};
	memset(lista, 0, sizeof lista);

	for (int i=0; i <= 15; i++)
	{
		update(i, v[i]);
	}

	//Trocar elemento na posição 4 para 7
	//int pos = 4;
	//int novo = 7;
	//update(pos, novo-v[pos]);
	//v[pos] = novo;

	//Consulta
	printf("%d", rsq(15));

	return 0;
}