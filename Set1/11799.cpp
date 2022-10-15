#include<iostream>
//Problema 2899
using namespace std;

int main(){
    int T=-1,a;
    cin>>T;
        
    int casos[T];
    for(int j=0;j<T;j++){//Casos de entrada
        int N;
        int mayor;
            
        cin>>N;
        
        int c[N];
        //cout<<"Caso "<<j<<endl;
        for(int i=0;i<N;i++){
            cin>>a;
            c[i]=a;
        }
        //cout<<c[N-1]<<endl;
        //cout<<"Termina "<<j<<endl;
        //Hallando el mayor de una entrada
        mayor=0;
        for(int i=0;i<N;i++){
            if(c[i]>mayor)
                mayor=c[i];
        }
        
        cout<<"Case "<<j+1<<": "<<mayor<<endl;
        //casos[j]=mayor;
        
    }
    //Mostrando resultados
    /*for(int i=0;i<T;i++){
        cout<<"Caso "<<i+1<<": "<<casos[i]<<endl;
    }*/
    return 0;
}