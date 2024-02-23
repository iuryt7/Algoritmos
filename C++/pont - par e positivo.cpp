#include <iostream>
using namespace std;
int main(){
    int qntd;
    int certo = 0;
    cin >> qntd;
    int vetor[qntd];
    int *p;
    for(int i = 0; i < qntd; i++){
        cin >> vetor[i];
    }
    p = vetor;
    for(int j = 0; j < qntd; j++){
        if(*p % 2 == 0){
            if(*p >= 0){
                certo++;
            }
        }
        p++;
    }
    cout << certo << endl;
    return 0;
}