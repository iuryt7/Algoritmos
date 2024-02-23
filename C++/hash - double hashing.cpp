#include <iostream>
using namespace std;

int h1(int k, int m)
{
	int pos;
	pos = k % m;
	if(pos < 0)
        pos += m;
	return pos;
}
int h2(int k, int m)
{
	int pos;
	pos = 1 + (k %(m - 1));
	if(pos < 0)
        pos += m;
	return pos;
}
int hash1(int k, int m, int i)
{
	int t;
	t = (h1(k,m) + (i * h2(k,m))) % m;
	return t;
}
int main()
{
	// Variáveis
	int k;
	int m;
	int i;
	
	cin >> k >> m;
	
	for(i = 0;i < m;i++)
	{
		cout << hash(k,m,i) << " ";
		cout << endl;
	}
	return 0;
}