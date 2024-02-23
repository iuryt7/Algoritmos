#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> fila; // ponteiro para a lista ligada
	list<int>::iterator p;
	int soma = 0;
	fila.push_back(2); // insere no inicio
	fila.push_back(1);
	fila.push_back(3);

	// Mostrando a lista
	for(p = fila.begin(); p != fila.end(); p++)
	{
		soma += *p;
	}
	cout << "soma = " << soma << endl;
	while(!fila.empty())
	{
		fila.pop_front(); //remove o primeiro elemento da fila
	}
	return 0;
}
