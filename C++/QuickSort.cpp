#include <iostream>
#include <math.h>
using namespace std;
void quickSort(int vetor[], int i, int j)
{
	int trab, esq, dir, pivo;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir) / 2.0)];
	do
	{
		while (vetor[esq] < pivo)esq++;
		while (vetor[dir] > pivo)dir--;
		if (esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	}
	while (esq <= dir);
	if (dir - i >= 0)quickSort(vetor, i, dir);
	if (j - esq >= 0)quickSort(vetor, esq, j);
}
int main()
{
	int lista[20];
	int tamanho = 0;
	int i;
	int j;
	i = 0;
	cin >> lista[tamanho];
	while(lista[tamanho] != -1)
	{
		tamanho++;
		cin >> lista[tamanho];
	}
	j = tamanho - 1;
	quickSort(lista, i, j);
	for(int h = 0; h <= j; h++)
	{
		cout << lista[h] << " ";
	}
	return 0;
}
