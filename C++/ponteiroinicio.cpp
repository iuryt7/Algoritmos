#include <iostream>
using namespace std;
struct ponto
{
	float x;
	float y;
};
int main()
{
	ponto *p = NULL;
	p = new ponto; // alocando memoria p/ 1 ponto

	p->x = 2.0;
	p->y = 3.0;

	cout << p->x << endl;
	cout << p->y << endl;
 
    delete p;

	return 0;
}
