#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> lista;
	list<int>::iterator p;
	int nm;
	int x;
	int y;
	cin >> nm;
	while(nm != -1)
	{
		lista.push_front(nm);
		cin >> nm;
	}
	cin >> x;
	cin >> y;
	p = lista.begin();
	while(*p != x){
		p++;
	}
	p++;
	lista.insert(p, y);
	while(!lista.empty()){
		cout << *lista.begin() << " ";
		lista.pop_front();
	}
	return 0;
}
