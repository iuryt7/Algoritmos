#include <iostream>
using namespace std;
int main(){
    int qntd;
    cin >> qntd;
    int vetor[qntd];
    int *p;
    for(int i = 0; i < qntd; i++){
        cin >> vetor[i];
    }
    p = vetor;
    for(int j = 0; j < qntd; j++){
        cout << *p << " ";
        p++;
    }
    return 0;
}