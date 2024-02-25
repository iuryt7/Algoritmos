#include <iostream>
#include <iomanip>
using namespace std;
int pot(int a, int n)
{
	if(n == 0)
		return 1;
	else
		return a * pot(a, n - 1);
}
double raiz(double x, double xo, double e)
{
	double cal, cal2;
	cal = (pot(xo, 2) - x) * -1;
	if( cal <= e)
	{
		return xo;
	}
	else
	{
		cal2 = (pot(xo, 2) + x) / (2 * xo);
		return raiz(x, cal2, e);
	}
}
int main()
{
	double x;
	double xo;
	double e;
	double resultado;
	cin >> x;
	cin >> xo;
	cin >> e;
	resultado = raiz(x, xo, e);
	cout << resultado << setprecision(4) << endl;
	return 0;
}
