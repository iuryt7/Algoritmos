#include <iostream>
#include <list>
using namespace std;
void BFS(list<no>adj[], int nVertices, int s)
{
	char state[10]; // 'u': nao processado, 'd': descoberto, 'p': processado
	int p[10]; // pai
	int u; // contador
	list<int> Q; // fila auxiliar
	for(u = 0; u < nVertices; u++)
		if(u != s)
		{
			state[u] = 'u';
			p[u] = -1; // sem pais
		}
	state[s] = 'd';
	p[s] = -1;
	Q.push_back(s);
	while(!Q.empty())
	{
		u = *Q.begin();
		Q.pop_front();
		cout << u << endl;
		for(q = adj[u].begin(); q != adj[u].end(); q++)
		{
			v = q -> v;
			cout << u << " " << v <<  endl;
			if(state[v] == 'u')
			{
				state[v] = 'd';
				p[v] = u;
				Q.push_back(v);
			}
		}
		state[u] = 'p';
	}
}
