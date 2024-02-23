#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double raiz(double x, double n, double e)
{
	if(fabs(pow(n, 2) - x) <= e)
		return n;
	else
	{
		return raiz(x, ((pow(n, 2) + x) / (2 * n)), e);
	}
}
int main()
{
	double x, n, e;
	double resultado;
	cin >> x >> n >> e;
	resultado = raiz(x, n, e);
	cout << fixed;
	cout << setprecision(4) << resultado <<  endl;
	return 0;
}
