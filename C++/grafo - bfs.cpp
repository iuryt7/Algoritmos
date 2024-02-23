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
void BFS(list<no>adj[], int nVertices, int s)
{
	char state[10]; // 'u': nao processado, 'd': descoberto, 'p': processado
	int u; // contador
	int pai[20];
	int v;
	list<int> Q; // fila auxiliar
	list<no>::iterator p;
	for(u = 0; u < nVertices; u++)
		if(u != s)
		{
			state[u] = 'u';
			pai[u] = -1; // sem pais
		}
	state[s] = 'd';
	pai[s] = -1;
	Q.push_back(s);
	while(!Q.empty())
	{
		u = *Q.begin();
		Q.pop_front();
		cout << u << endl;
		for(p = adj[u].begin(); p != adj[u].end(); p++)
		{
			v = p -> v;
			cout << u << " " << v <<  endl;
			if(state[v] == 'u')
			{
				state[v] = 'd';
				pai[v] = u;
				Q.push_back(v);
			}
		}
		state[u] = 'p';
	}
}
int main()
{
	list<no> adj[10]; // lista de adjacencias
	int u, v; // vertices de origem e destino de uma aresta
	int p; // peso da aresta
	int s; // Aresta de start
	int orientado = 0; //0: nao orientado, 1: orientado
	int nVertices; // # vertices do grafo
	list<no>::iterator q;
	// Lendo origem, destino e peso da aresta
	cin >> nVertices;
	cin >> s;
	cin >> u >> v >> p;
	while(u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}
	BFS(adj, nVertices, s);
	
	return 0;
}
