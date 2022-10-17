#include <cstdio>
#include <iostream>

using namespace std;
int main(void) {
    int N, M;
    int respuesta;
    while (cin>>M>>N) {
        bool cambio=false;
        if(M==0 && N==0)
          break;
        // Print the result
        if (M > N){
            swap(M, N);
            cambio=true;
        }

        //Los caballos estaran en una sola fila por lo tanto nunca uno llegara al otro
        if (M==1){//El cabballo no se puede mover
            respuesta=N;
        }
        // Cada 2*2 se coloca 4 caballos
        else if (M==2){//N&4 sera cero si N < 4
            respuesta=(N / 4) * 4;
            if(N % 4 < 3){
                respuesta=respuesta+(N%4)*2;
            }
            else{
                respuesta=respuesta+4;
            }
            //return (N / 4) * 4 + ((N % 4 < 3) ? (N % 4) * 2 : 4);//N%4 sera 0,1,2 (nultiplos de 4)
        }
        else{//Para m,n >=3 el caballo ya se puede mover por lo tanto los caballos deben colocarse en sus diagonales
            if((N*M)%2){
                respuesta=N*M/2+1;
            }
            else{//division par
                respuesta=N*M/2;
            }
            //return (M * N + 1) / 2;
        }
        if(cambio){
            cout<<respuesta<<" knights may be placed on a "<<N<<" row "<<M<<" column board."<<endl;
        }
        else{
            cout<<respuesta<<" knights may be placed on a "<<M<<" row "<<N<<" column board."<<endl;
        }
        //printf("%d knights may be placed on a %d row %d column board.\n", knights(N, M), N, M);
    }

    return 0;
}