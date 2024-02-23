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
void dijkstra(list<no>adj[], int nVertices, int start, int end)
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
	int dist_aux;
	list<no>::iterator q;
	list<int>::iterator l;
	list<int> invert;
	for(u = 0; u < nVertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	distance[start] = 0;
	v = start;
	while(intree[v] == false)
	{
		intree[v] = true;
		for(q = adj[v].begin(); q != adj[v].end(); q++)
		{
			destino = q->v;
			weight = q->p;
			if(distance[destino] > distance[v] + weight)
			{
				distance[destino] = distance[v] + weight;
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
				dist_aux = dist;
				v = u;
			}
		}
	}
	destino = end;
	invert.push_front(destino);
	while(destino != start)
	{
		invert.push_front(parent[destino]);
		destino = parent[destino];
	}
	cout << "Menor caminho: ";
	for(l = invert.begin(); l!=invert.end(); l++){
		cout<< *l<< " ";
	}
	cout << endl;
	cout << "Custo: " << distance[end] << endl;
}
int main()
{
	list<no> adj[10]; // lista de adjacencias
	int u, v; // vertices de origem e destino de uma aresta
	int p; // peso da aresta
	int orientado; //0: nao orientado, 1: orientado
	int s; // Aresta de start
	int e; // Aresta de end
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
	cin >> e;
	cin >> u >> v >> p;
	while(u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}
	dijkstra(adj, nVertices, s, e);

	return 0;
}
