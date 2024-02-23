#include<iostream>
using namespace std;

// Função auxiliar para inserir a chave k em uma tabela hash de tamanho m
int hash_aux(int k, int m)
{
    int pos = k % m; // posição a inserir
    
    // Se a posição for negativa, temos que somar m
    if(pos < 0)
        pos += m;
        
    return pos;    
}
// Função para sondagem quadrática
int hash(int k, int i, int m, int c1, int c2)
{
	int h;	
	h = ((hash_aux(k,m)) + (c1 * i) + (c2 * (i * i))) % m;
	return h;
}
int main()
{
	// Variáveis
	int k; // numero a ser inserido
	int i = 0;
	int m; // tamanho da tabela
	int c1; 
	int c2;
	
	// Entrada de dados
	cin >> k >> m >> c1 >> c2;
	
	// Saída da função quadrática
	for(i = 0;i < m;i++)
	{
		cout << hash(k,i,m,c1,c2) << " ";
		cout << endl;
	}

    return 0;
}