#include <iostream>
using namespace std;
int main(){
    int qntd;
    float media = 0;
    cin >> qntd;
    int vetor[qntd];
    int *p;
    for(int i = 0; i < qntd; i++){
        cin >> vetor[i];
    }
    p = vetor;
    for(int j = 0; j < qntd; j++){
        media += *p;
        p++;
    }
    media = media / qntd;
    cout << media << endl;
    return 0;
}