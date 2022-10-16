#include <bits/stdc++.h>
#include<iostream>
using namespace std;
//#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    //fastio
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
            //respuesta = min(n, m); //queen problem always have solution for n>=4
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
           //respuesta = (n*m)%2 ? n*m/2+1 : n*m/2; // knight occupy one color
           if((n*m)%2){
            respuesta=n*m/2+1;
           }
           else{
            respuesta=n*m/2;
           }
        }
        cout << respuesta << "\n";
    }
}