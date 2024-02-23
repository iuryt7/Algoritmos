#include <iostream>
#include <list>
#include <climits>
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
void prim(list<no>adj[], int nVertices, int start)
{
	int v;
	int u = 0;
	int valor = 0;
	int distance[20];
	int parent[20];
	bool intree[20];
	int destino;
	int weight;
	int dist;
	list<no>::iterator q;
	for(u = 0; u < nVertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	distance[start] = 0;
	v = start;
	cout << "Arvore Geradora Minima: " << endl;
	while(intree[v] == false)
	{
		intree[v] = true;
		for(q = adj[v].begin(); q != adj[v].end(); q++)
		{
			destino = q->v;
			weight = q->p;
			if(distance[destino] > weight && intree[destino] == false)
			{
				distance[destino] = weight;
				parent[destino] = v;
			}
		}
		v = 0;
		dist = INT_MAX;
		for(u = 0; u < nVertices; u++)
		{
			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}
	for(int y = 1; y < nVertices; y++)
	{
		cout << parent[y] << " " << y << endl;
		valor = valor + distance[y];
	}
	cout << "Custo: " << valor << endl;
}
int main()
{
	list<no> adj[10]; // lista de adjacencias
	int u, v; // vertices de origem e destino de uma aresta
	int p; // peso da aresta
	int orientado; //0: nao orientado, 1: orientado
	int s; // Aresta de start
	int nVertices; // # vertices do grafo
	list<no>::iterator q;
	// Lendo origem, destino e peso da aresta
	cin >> nVertices;
	cin >> orientado;
	while(orientado != 0 && orientado != 1)
	{
		cin >> orientado;
	}
	cin >> s;
	cin >> u >> v >> p;
	while(u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}
	prim(adj, nVertices, s);

	return 0;
}
