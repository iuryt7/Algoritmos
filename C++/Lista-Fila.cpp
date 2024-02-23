#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> fila; // ponteiro para a lista ligada
	fila.push_back(2); // insere no inicio
	fila.push_back(1);
	fila.push_back(3);
	while(!fila.empty()){
		cout << *fila.begin() << endl;
		fila.pop_front();
	}
	return 0;
}