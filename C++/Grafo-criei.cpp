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
	int n;
	int h;
	no aux; // var aux p/ amazenar as arestas em adj
	cout << "Quantos vertices voce tem?" << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "----- Quantos destinos tem o no " << i << "?" << endl;
		cin >> h;
		for(int j = 0; j < h; j++){
			cin >> aux.v;
			cin >> aux.p;
			adj[i].push_back(aux);
		}
	}
	return 0;
}