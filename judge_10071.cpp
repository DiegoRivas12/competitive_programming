#include <iostream>
using namespace std;
//Problema 1012
int main(){

    int t,v;
    cin>>v>>t;
    if(-100<=v && v<=100 && 0<=t && t<=200){
        cout<<2*v*t<<endl;
    }
    else{
        cout<<"Error";
    }
    return 0;
}