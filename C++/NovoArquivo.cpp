#include <iostream>
#include <cmath>
using namespace std;
void quickSort(int vetor[], int tamanho, int i, int j)
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
	if (dir - i >= 0)quickSort(vetor, tamanho, i, dir);
	if (j - esq >= 0)quickSort(vetor, tamanho, esq, j);
}
int main()
{
	int vetor = 0, x[20];
	cin >> x[vetor];
	while(x[vetor] != -1)
	{
		if(x[vetor] != -1)
			vetor++;
		cin >> x[vetor];
	}
	vetor = vetor - 1;
	quickSort(x, vetor + 1, 0, vetor);
	for(int j = 0; j <= vetor; j++)
	{
		cout << x[j] << " ";
	}

	return 0;
}
