#include <iostream>
using namespace std;

int solucao[7][10];

int n = 7;
int c = 10;
int peso[7] = (7, 3, 4, 5, 3, 5, 2);
int valor[7] = (42, 12, 40, 25, 26, 41, 23);
int mochila(int item, int capacidade)
{
	if (item >= n)
		return 0;

	if(solucao[item][capacidade] != -1)
	{
		return solucao[item][capacidade];
	}

	// escolhi o item atual
	int ans1 = 0;
	if(capacidade >= peso[item])
		int ans1 = mochila (item + 1, capacidade - peso[item]) + valor[item];

	// não escolhi
	int ans2 = mochila(item + 1,  capacidade)
	int ans = max(ans1, ans2);
	solucao[item][capacidade] = ans;
	return ans;
}
int main()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < c; j++)
		{
			solucao[i][j] = -1;
		}
	}
	cout << mochila(0, c) << endl;
}
