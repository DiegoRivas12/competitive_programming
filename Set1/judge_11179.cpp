#include<iostream>
//Problema 2899
using namespace std;

int main(){
    int T=-1,a;
    cin>>T;
    if(T<=50 && T!=-1){
        int casos[T];
        for(int j=0;j<T;j++){//Casos de entrada
            int N;
            int mayor;
            
            cin>>N;
            if(1<=N && N<=100){
                int c[N];
                //cout<<"Caso "<<j<<endl;
                for(int i=0;i<N;i++){
                    cin>>a;
                    if(1<=a && a<=1000)
                        c[i]=a;
                }
                //cout<<c[N-1]<<endl;
                //cout<<"Termina "<<j<<endl;
                //Hallando el mayor de una entrada
                mayor=c[0];
                for(int i=1;i<N;i++){
                    if(c[i]>mayor)
                        mayor=c[i];
                }
                casos[j]=mayor;
            }
        }
        //Mostrando resultados
        for(int i=0;i<T;i++){
            cout<<"Caso "<<i+1<<": "<<casos[i]<<endl;
        }
    }
    return 0;
}