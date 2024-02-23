#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> pilha; // ponteiro para a lista ligada
	pilha.push_front(2); // insere no inicio
	pilha.push_front(1);
	pilha.push_front(3);
	cout << *pilha.begin() << endl;
	pilha.pop_front(); // remove o primeiro elemento da pilha
	cout << *pilha.begin() << endl;
	pilha.pop_front();
	cout << *pilha.begin() << endl;
	return 0;
}