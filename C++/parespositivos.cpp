#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int tam;
	double res = 0;
	int *p;
	cin >> tam;
	int vetor[tam];
	for(int i = 0; i < tam; i++){
		cin >> vetor[i];
	}
	p = vetor;
	for(int j = 0; j < tam; j++){
		if(*p % 2 == 0){
			if(*p >= 0){
				res++;
			}
		}
		p++;
	}
	cout << res << endl;
	return 0;
}