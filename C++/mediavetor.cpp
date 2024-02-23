#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int tam;
	double res;
	int *p;
	cin >> tam;
	int vetor[tam];
	for(int i = 0; i < tam; i++){
		cin >> vetor[i];
	}
	p = vetor;
	for(int j = 0; j < tam; j++){
		res += *p;
		p++;
	}
	res = res / tam;
	cout << res << setprecision(2) << endl;
	
	return 0;
}