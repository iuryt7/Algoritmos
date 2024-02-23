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
		if(res < *p){
			res = *p;
		}
		else if(res == 0 && *p < 0){
			res = *p;
		}
		p++;
	}
	cout << res << endl;
	return 0;
}