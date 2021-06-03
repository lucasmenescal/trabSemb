#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <stdio.h>
#include <time.h> //necessário p/ função time()


int main(void)
{
  int i;
  int x = 9;
  int lista[10];

  printf("Gerando 2000 valores inteiros aleatorios...\n");
  srand(time(NULL));

  for (i = 0; i <= x; i++)
  {
    lista[i] = rand();
  }
  printf("[ %d, ", lista[0]);
  for (i = 1; i < x; i++)
  {
    printf("%d, ", lista[i]);
  }
  printf("%d. ] \n", lista[x]);
  printf("10 valores inteiros aleatorios foram gerados com sucesso!...\n");
  
}