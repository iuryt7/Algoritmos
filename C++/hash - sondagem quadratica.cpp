#include<iostream>
using namespace std;

// Fun��o auxiliar para inserir a chave k em uma tabela hash de tamanho m
int hash_aux(int k, int m)
{
    int pos = k % m; // posi��o a inserir
    
    // Se a posi��o for negativa, temos que somar m
    if(pos < 0)
        pos += m;
        
    return pos;    
}
// Fun��o para sondagem quadr�tica
int hash(int k, int i, int m, int c1, int c2)
{
	int h;	
	h = ((hash_aux(k,m)) + (c1 * i) + (c2 * (i * i))) % m;
	return h;
}
int main()
{
	// Vari�veis
	int k; // numero a ser inserido
	int i = 0;
	int m; // tamanho da tabela
	int c1; 
	int c2;
	
	// Entrada de dados
	cin >> k >> m >> c1 >> c2;
	
	// Sa�da da fun��o quadr�tica
	for(i = 0;i < m;i++)
	{
		cout << hash(k,i,m,c1,c2) << " ";
		cout << endl;
	}

    return 0;
}