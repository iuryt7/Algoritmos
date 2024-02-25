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

int main()
{
	ponto P, P1, P2, P3;
	float area, w1, w2, w3;

	cout << fixed << setprecision(3);

	cout << "Entre com o ponto P1: ";
	cin >> P1.x >> P1.y;
	cout << endl;
	cout << "Entre com o ponto P2: ";
	cin >> P2.x >> P2.y;
	cout << endl;
	cout << "Entre com o ponto P3: ";
	cin >> P3.x >> P3.y;
	cout << endl;
	cout << "Entre com o ponto P: ";
	cin >> P.x >> P.y;
	cout << endl;

	area = area_triangulo(P1, P2, P3);
	w1 = area_triangulo(P, P2, P3) / area;
	w2 = area_triangulo(P1, P, P3) / area;
	w3 = area_triangulo(P1, P2, P) / area;
	cout << "As coordenadas sao: " << w1 << " " << w2 << " " << w3 << endl;

	return 0;
}
