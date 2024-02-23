#include <iostream>
#include <cstring>
using namespace std;
int calcula_chave(char palavra[])
{
	int i; // contador
	int tam; // comprimento da palavra
	int k; // chave
	tam = strlen(palavra);
	k = 0;
	for(i = 0; i < tam; i++)
		k += (int)palavra[i];
	return k;
}
struct dado
{
	char info[50]; // informacao
	int k; // chave
	int status; // 0: vazio, 1:ocupado, 2:removido
};
int main()
{
	char palavra[50];
	int k; //chave
	cin.getline(palavra, 50);
	k = calcula_chave(palavra);
	cout << k << endl;
}
