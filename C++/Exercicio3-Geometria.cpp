#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = vetorial(AB, AC) / 2;
	return area;
}
// retorna: 1 se p estiver à esquerda de ab,
// -1 se p estiver à direita,
// 0 se estiver alinhado
int lado(ponto a, ponto b, ponto p)
{
	float area = 0;
	area = area_triangulo(a, b, p);
	if(area > 0)
	{
		return 1;
	}
	else if(area < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	ponto P1, P2, P3;
	int resultado = 0;

	cout << fixed << setprecision(2);

	cout << "Entre com o ponto A: ";
	cin >> P1.x >> P1.y;
	cout << endl;
	cout << "Entre com o ponto B: ";
	cin >> P2.x >> P2.y;
	cout << endl;
	cout << "Entre com o ponto C: ";
	cin >> P3.x >> P3.y;
	cout << endl;

	resultado = lado(P1, P2, P3);
	if(resultado == 1){
		cout << "O ponto esta a esquerda." << endl;
	}
	else if(resultado == -1){
		cout << "O ponto esta a direita." << endl;
	}
	else if(resultado == 0){
		cout << "O ponto esta alinhado." << endl;
	}


	return 0;
}
