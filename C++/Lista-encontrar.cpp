#include <iostream>
#include <list>
using namespace std;
bool encontrar(list<int> lista, int x)
{
	list<int>::iterator p;
	bool achou = false;
	for(p = lista.begin(); p != lista.end(); p++)
	{
		if(*p == x)
			achou = true;
	}
	return achou;
}
int main()
{
	list<int> lista; // ponteiro para a lista ligada
	int x;
	int y;
	bool procurar = false;
	while(x != 0)
	{
		cin >> x;
		if(x != 0)
		{
			lista.push_front(x);
		}
	}
	cin >> y;
	procurar = encontrar(lista, y);
	if(procurar == true){
		cout << "Encontrado" << endl;
	}
	else{
		cout << "Nao encontrado" << endl;
	}
	return 0;
}
