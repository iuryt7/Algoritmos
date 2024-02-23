#include <iostream>
#include <list>
using namespace std;
struct no
{
	int v;
	int peso;
};

int main(int argc, char** argv)
{
	list<no> adj[10]; //lista de adjacência
	int u, v; //vertices de origem e destino de uma aresta
	int peso;
	int nVertices = 3;
	int i;
	no aux;
	list<no>::iterator p;
	
	u = 0;
	v = 1;
	peso = 5;
	aux.v = v;
	aux.peso = peso;
	adj[u].push_back(aux);
	aux.v = u;
	adj[v].push_back(aux);
	
	u = 0;
	v = 2;
	peso = 3;
	aux.v = v;
	aux.peso = peso;
	adj[u].push_back(aux);
	aux.v = u;
	adj[v].push_back(aux);
	
	p = adj[0].begin();
	for(i=0; i < nVertices;i++){
		for(p = adj[i].begin(); p != adj[i].end();p++){
			cout << i << " " << p->v << " " << p->peso << endl;
		}
	}
	return 0;
}
