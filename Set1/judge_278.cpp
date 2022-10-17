#include<iostream>
using namespace std;

int main(){// 4<=m,n<=10
    int t, n, m;
    char letra;
    cin >> t;
    for(int i=0;i<t;i++) {
        cin >> letra >> n >> m;
        int respuesta;
        if(letra=='r') {
            if(m<n){
                respuesta=m;
            }
            else if(m>n){
                respuesta=n;
            }
            else{//m=n
                respuesta=m;
            }
        } 
        else if(letra=='Q') {
            
            if(m<n){
                respuesta=m;
            }
            else if(m>n){
                respuesta=n;
            }
            else{//m=n
                respuesta=m;
            }
        } 
        else if(letra=='K') {//rey
            respuesta = ((n+1)/2) * ((m+1)/2); // 1king take four cells
        } 
        else if(letra=='k') {//caballo
          
           if((n*m)%2){
            respuesta=n*m/2+1;
           }
           else{//division par
            respuesta=n*m/2;
           }
        }
        cout << respuesta << "\n";
    }
}