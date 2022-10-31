#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    int longitudPoste,cantHormiga;
    cin>>T;
    for(int i=0;i<T;i++){//Numero de casos
        cin>>longitudPoste;
        cin>>cantHormiga;
        int respuestaMayor=0,respuestaMenor=0;
        int posHormigas[cantHormiga];
        for(int j=0;j<cantHormiga;j++){//Cantidad de hormigas
            cin>>posHormigas[j];
            int mayor = max(longitudPoste-posHormigas[j],posHormigas[j]);
            int menor = min(longitudPoste-posHormigas[j],posHormigas[j]);
            respuestaMenor = max(menor,respuestaMenor);
            respuestaMayor = max(mayor,respuestaMayor);
        }
        printf("%d %d\n",respuestaMenor,respuestaMayor);
    }

    return 0;
}