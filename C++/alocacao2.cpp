#include <iostream>
#include <iomanip>
using namespace std;
struct notas
{
	int n1;
	int n2;
	int n3;
	int n4;
};
int main()
{
	int alunos;
	double resfinal;
	cin >> alunos;
	double res[alunos];
	notas *v;
	v = new notas;
	for(int i = 0; i < alunos; i++)
	{
		cin >> v -> n1;
		cin >> v -> n2;
		cin >> v -> n3;
		cin >> v -> n4;
		res[i] = ((v->n1) + (v->n2) + (v->n3) + (v->n4)) / 4.0;
	}
	for(int j = 0; j < alunos; j++){
		resfinal += res[j];
	}
	resfinal = resfinal / alunos;
	cout << resfinal << setprecision(2) << endl;
	return 0;
}