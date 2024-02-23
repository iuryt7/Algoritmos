#include <iostream>
using namespace std;
struct ponto
{
	float x;
	float y;
};
int main()
{
	ponto *p = NULL;
	int tam;
	cin >> tam;
	p = new ponto[tam]; // alocando memoria p/ 1 ponto
	for(int i = 0; i < tam; i++){
		cin >> p[i].x;
		cin >> p[i].y;
	}
	
	for(int i = 0; i < tam; i++){
		cout << p[i].x << " ";
		cout << p[i].y;
		cout << endl;
	}

	delete [] p;

	return 0;
}
