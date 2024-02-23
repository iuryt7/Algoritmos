#include <iostream>
#include <list>
using namespace std;
struct no
{
	int v; // destino
	int p; // peso
};
void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
	no aux; //var aux para inserir os nós nas listas
	if(u != -1 && v != -1 && p != -1)
	{
		// Criando aresta
		aux.v = v;
		aux.p = p;
		adj[u].push_back(aux);
		// Criando a aresta de volta se o grafo for nao orientado
		if(orientado == 0)
		{
			aux.v = u; // destino
			adj[v].push_back(aux);
		}
	}
}
int main()
{
	list<no> adj[10]; // lista de adjacencias
	int u, v; // vertices de origem e destino de uma aresta
	int p; // peso da aresta
	int orientado; //0: nao orientado, 1: orientado
	int nVertices; // # vertices do grafo
	list<no>::iterator q;
	// Lendo origem, destino e peso da aresta
	cin >> nVertices;
	cin >> orientado;
	while(orientado != 0 && orientado != 1)
	{
		cin >> orientado;
	}
	cin >> u >> v >> p;
	while(u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}

	// Mostrando a lista de adjacencias
	for(u = 0; u < nVertices; u++)
		for(q = adj[u].begin(); q != adj[u].end(); q++)
			cout << u << " " << q->v << " " << q->p << endl;
	return 0;
}
