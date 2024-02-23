#include <iostream>
#include <list>
using namespace std;
struct no{
	int v; // destino
	int p; // peso
};
int main(){
	list<no> adj[10]; // lista de adjacencias
	no aux; //var aux para inserir os n�s nas listas
	int u, v; // vertices de origem e destino de uma aresta
	int p; // peso da aresta
	int orientado = 0; //0: nao orientado, 1: orientado
	int nVertices = 5; // # vertices do grafo
	list<no>::iterator q;
	
	// Lendo origem, destino e peso da aresta
	cin >> u >> v >> p;
	
	// Criando aresta
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	// Criando a aresta de volta se o grafo for nao orientado
	if(orientado == 0){
		aux.v = u;
		adj[v].push_back(aux);
	}
	// Mostrando a lista de adjacencias
	for(u = 0; u < nVertices; u++)
		for(q = adj[u].begin(); q != adj[u].end(); q++)
			cout << u << " " << q->v << " " << q->p << endl;
	return 0;
}