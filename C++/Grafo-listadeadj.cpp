#include <iostream>
#include <list>
using namespace std;

struct no
{
	int v; // destino
	int p; // peso
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux;
	if(u != -1 && v != -1 && p != -1)
	{
		aux.v = v;
		aux.p = p;
		adj[u].push_back(aux);
		if(orientado == 0)
		{
			aux.v = u; // destino
			adj[v].push_back(aux);
		}
	}
}

int main()
{
	list<no> adj[10]; //lista de adjacencias do grafo
	list<no>::iterator q;
	int u, v; // origem e destino da aresta
	int p; // peso da aresta
	int nVertices;
	int orientado = 0; // 1: orientado, 0: nao orientado
	cin >> nVertices;
	cin >> orientado;
	while(orientado != 0 && orientado != 1)
	{
		cin >> orientado;
	}
	cin >> u;
	cin >> v;
	cin >> p;
	while( u != -1 && p != -1 && v != -1)
	{

		cria_aresta(adj, u, v, p, orientado);
		cin >> u;
		cin >> v;
		cin >> p;
	}

	for(int i = 0; i < nVertices; i++)
	{
		for(q = adj[i].begin(); q != adj[i].end(); q++)
		{
			cout << i << " ";
			cout << q -> v << " ";
			cout << q -> p << endl;
		}
	}

	return 0;
}
