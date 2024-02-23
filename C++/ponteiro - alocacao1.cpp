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
	p = new nota; // alocando memoria p/ 1 ponto

	cin >> p->n1;
	cin >> p->n2;
	cin >> p->n3;
	cin >> p->n4;

	p->media = (p->n1 + p->n2 + p->n3 + p->n4) / 4.0;

	cout << fixed << setprecision(2);
	cout << p->media << endl;

	delete p;

	return 0;
}
