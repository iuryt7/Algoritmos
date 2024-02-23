#include<iostream>
using namespace std;

struct dado
{
	int k;
	int status;
};

// Função auxiliar para inserir a chave key em uma tabela hash de tamanho m
int hash_aux(int k, int m)
{
	int pos = k % m; // posição a inserir

	// Se a posição for negativa, temos que somar m
	if(pos < 0)
		pos += m;

	return pos;
}

// Função que implementa a sondagem linear
int h1(int k, int m)
{
	int pos;
	pos = k % m;
	if(pos < 0)
		pos += m;
	return pos;
}
int h2(int k, int m)
{
	int pos;
	pos = 1 + (k % (m - 1));
	if(pos < 0)
		pos += m;
	return pos;
}
int hash1(int k, int m, int i)
{
	int t;
	t = (h1(k, m) + (i * h2(k, m))) % m;
	return t;
}
int hash_insert(dado t[], int m, int k)
{
	int j, i = 0;
	do
	{
		j = hash1(k, m, i); // Substituindo j na função hash
		if (t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
		{
			i = i + 1;
		}
		while( i != m)
		{
			return -1; // tabela cheia
		}
	}
	while(i != m);

		return -1;
}
// Função de pesquisa
int hash_search(dado t[], int m, int k)
{
	int i, j;
	i = 0;
	do
	{
		j = hash1(k, m, i);
		if(t[j].k == k)
		{
			return j;
		}
		else
		{
			i = i + 1;
		}
	}
	while(t[j].status != 0 || i != m);
	return 0;
}
int hash_remove(dado t[], int m, int k)
{
	int j;
	j = hash_search(t, m, k);
	if(j != 1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int m; // tamanho da tabela
	int k; // chave a ser armazenada
	int i; // contador
	int s; // procurar valor
	dado t[100]; // tabela hash
	int status = 0; // status 1: inserir 2: pesquisar 3: remover 4: listar 5: sair
	int l;
	cin >> m;
	for(i = 0; i < m; i++)
	{
		t[i].status = 0;
		t[i].k = -1;
	}
	while(status != 5)
	{
		cin >> status;
		if(status == 1)
		{
			cin >> k;
			hash_insert(t, m, k);
		}
		else if(status == 2)
		{
			cin >> k;
			l = hash_search(t, m, k);
			// Saida da pesquisa
			if(l != -1)
			{
				cout << l << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else if(status == 3)
		{
			cin >> s;
			l = hash_remove(t, m, s);
		}
		else if(status == 4)
		{
			for(i = 0; i < m; i++)
				cout << t[i].k << " ";
			cout << endl;
		}
	}


	return 0;
}
