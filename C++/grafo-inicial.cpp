#include <iostream>
#include <list>
using namespace std;

struct no
{
	int v; // destino
	int p; // peso
};

int main()
{
	list<no> adj[10]; //lista de adjacencias do grafo
	list<no>::iterator q;
	int u, v; // origem e destino da aresta
	int p; // peso da aresta
	int nVertices = 4;
	no aux; // var aux p/ amazenar as arestas em adj
	int orientado; // 1: orientado, 0: nao orientado

	u = 0; // origem
	v = 1; // destino
	p = 2; // peso
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	// Aresta de volta;
	if(orientado == 0)
	{
		aux.v = u; // destino
		adj[v].push_back(aux);
	}

	for(int i = 0; i < nVertices; i++)
	{
		for(q = adj[i].begin(); q != adj[i].end(); q++)
		{
			cout << "Origem: " << i;
			cout << " Destino: " << q -> v;
			cout << " Peso: " << q -> p << endl;
		}
	}

	return 0;
}
