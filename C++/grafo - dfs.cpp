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
	// Criando aresta
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	// Criando a aresta de volta se o grafo for nao orientado
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

void ordenacao_topologica(int f[], int nVertices){
    
    int aux[50];
    int i;
    int a;
    int b;
    
    for(i =0; i<nVertices; i++){
        aux[i] = i;
    }
    
    for(a=0; a < nVertices; a++)
    {
        for(i= a + 1; i<nVertices; i++)
        {
            if(f[aux[a]] < f[aux[i]])
            {
                b = aux[a];
                aux[a] = aux[i];
                aux[i] = b;
            }
        }
    }
    for(i=0; i<nVertices; i++)
    {
        cout<<aux[i] << " ";
    }
    cout<<endl;
}


void dfs_visit(list<no>adj[], int nVertices, int u, int color[], int pai[], int &time, int f[], int d[])
{
    
	color[u] = 2;
	time += 1;
	d[u] = time;
	
	// varrer a lista
	list<no>::iterator v;
	
	for(v = adj[u].begin(); v != adj[u].end(); v++)
	{
		if (color[v->v] == 1)
		{
			pai[v->v] = u;
			dfs_visit(adj,nVertices, v->v, color, pai, time,f,d);
		}
	}
	color[u] = 3;
	time+=1;
	f[u] = time;
}


void dfs(list<no>adj[], int nVertices)
{
    int time;
    int u;
	int d[20];
    int f[50];
	int color[20]; // 1 - white, 2 - grey, 3 - black
	int pai[20];

	for(int i = 0; i < nVertices; i++)
	{
		color[i] = 1;
		pai[i] = -1;
	}
	time = 0;
	for(int i = 0; i < nVertices; i++)
	{
		if(color[i] == 1)
		{
			dfs_visit(adj,nVertices, u, color, pai, time, f, d);
		}
	}
	ordenacao_topologica(f, nVertices);
}


int main()
{
    list<no>adj[50];
    int u, v; // vertices de origem e destino de uma aresta
	int p; // peso da aresta
	int orientado; //0: nao orientado, 1: orientado
	int nVertices; // # vertices do grafo
	// Lendo origem, destino e peso da aresta
	cin >> nVertices;
	cin >> orientado;
	cin >> u >> v;
	while(u != -1 && v != -1)
	{
		cria_aresta(adj, u, v, 1, orientado);
		cin >> u >> v;
	}
    
    dfs(adj,nVertices);
    
	return 0;
}
