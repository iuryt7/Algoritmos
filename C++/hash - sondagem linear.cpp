#include <iostream>
using namespace std;

int hash_aux(int k, int m)
{
	// POSICAO
	int pos;
	pos = k % m;
	if(pos < 0)
		pos += m;
	return pos;
}
int hash1(int k, int i, int m)
{
	return (hash_aux(k,m)+i) % m;
}
int main()
{
	// VARIAVEIS
	int k;
	int m;
	int s;
	int i;
	
	// ENTRADA DE DADOS
	cin >> k >> m;
	for(i = 0;i < m;i++)
	{
		cout << hash1(k,i,m) << " ";
	}
	
	
	return 0;
}