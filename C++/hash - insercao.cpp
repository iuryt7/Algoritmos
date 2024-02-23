#include<iostream>
using namespace std;

struct dado
{
	int k; // chave
	int status; // 0:vazia, 1:ocupada, 2:removido
};
int hash_aux(int k, int m)
{
    int pos = k % m; // posição a inserir
    
    // Se a posição for negativa, temos que somar m
    if(pos < 0)
        pos += m;
        
    return pos;    
}
// Função que implementa a sondagem linear
int hash(int k, int i, int m)
{
    return (hash_aux(k,m)+i) % m;
}
int hash_insert(dado t[], int m, int k)
{
	int j,i=0;
    while(i != m)
	{
		j = hash(k,i,m);// Substituindo j na função hash
		if (t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
            return j;
		}
        else{
            i = i+1;
		}
	}	
	
    return -1;
}
int main()
{
    int m; // tamanho da tabela
    int k; // chave a ser armazenada
    int i; // contador
    dado t[100]; // tabela hash
    
    // Lendo chave e tamanho da tabela
    cin >> m;
	// Inicializando a tabela
	for(i=0;i<m;i++)
	{
		t[i].status = 0;
		t[i].k = -1;
	}
	// Inserindo valores na função hash
	cin >> k;
	while(k != 0)
	{
		hash_insert(t,m,k);
		cin >> k;
	}
	
    // Saida da pesquisa
    for(i = 0;i < m; i++)
		cout << t[i].k << " ";
	cout << endl;
    
       
    
    return 0;
}