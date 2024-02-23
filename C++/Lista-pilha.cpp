#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> pilha; // ponteiro para a lista ligada
	pilha.push_front(2); // insere no inicio
	pilha.push_front(1);
	pilha.push_front(3);
	
	while(!pilha.empty()){
		cout << *pilha.begin() << endl;
		pilha.pop_front();
	}
	return 0;
}