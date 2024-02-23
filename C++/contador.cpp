#include <iostream>
#include <list>
using namespace std;
int contar(list<int> lista){
	int soma = 0;
	list<int>::iterator p;
	for(p = lista.begin(); p != lista.end(); p++){
		soma++;
	}
	return soma;
}
int main()
{
	list<int> lista; // ponteiro para a lista ligada
	int x;
	int resultado;
	while(x != 0)
	{
		cin >> x;
		if(x != 0)
		{
			lista.push_back(x);
		}
	}
	resultado = contar(lista);
	cout << resultado << endl;
}
