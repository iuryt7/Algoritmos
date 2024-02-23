#include <iostream>
#include <iomanip>
using namespace std;
struct nota
{
	float n1;
	float n2;
	float n3;
	float n4;
	float media;
};

int main()
{
	nota *p = NULL;
	int tam;
	float mediat = 0;
	cin >> tam;

	p = new nota[tam];

	for(int i = 0; i < tam; i++)
	{
		cin >> p[i].n1;
		cin >> p[i].n2;
		cin >> p[i].n3;
		cin >> p[i].n4;
		p[i].media = (p[i].n1 + p[i].n2 + p[i].n3 + p[i].n4) / 4.0;
	}

	for(int j = 0; j < tam; j++)
	{
		mediat += p[j].media;
	}

	mediat = mediat / tam;

	cout << fixed << setprecision(2);
	cout << mediat << endl;

	delete p;

	return 0;
}
