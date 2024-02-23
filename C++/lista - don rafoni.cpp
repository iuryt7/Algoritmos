#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
	list<string> nome;
	list<string>::iterator n;
	list<int> lista;
	list<int>::iterator p;
	int nm;
	int qntd;
	string cliente;
	cin >> qntd;
	for(int i = 0; i < qntd; i++)
	{
		cin.ignore();
		getline(cin, cliente);
		cin >> nm;
		nome.push_back(cliente);
		lista.push_back(nm);
	}
	cin.ignore();
	getline(cin, cliente);
	while(!nome.empty() && !lista.empty())
	{
		n = nome.begin();
		if(*n != cliente)
		{
			cout << *nome.begin() << endl;
			cout << *lista.begin() << endl;
		}
		nome.pop_front();
		lista.pop_front();
	}
	return 0;
}
