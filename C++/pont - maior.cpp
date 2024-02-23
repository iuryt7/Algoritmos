#include <iostream>
using namespace std;
int main(){
    int qntd;
    int maior;
    cin >> qntd;
    int vetor[qntd];
    int *p;
    for(int i = 0; i < qntd; i++){
        cin >> vetor[i];
    }
    p = vetor;
    maior = vetor[0];
    for(int j = 0; j < qntd; j++){
        if(*p > maior){
            maior = *p;
        }
        p++;
    }
    cout << maior << endl;
    return 0;
}