#include <iostream>
using namespace std;
//Problema 2113
int main(){
    int t=-1;
    cin>>t;
    if(t<15 && t!=-1){
        int a,b;
        int numeros[t][2];
        for(int i=0;i<t;i++){
            cin>>a>>b;
            numeros[i][0]=a;
            numeros[i][1]=b;
        }

        //Mostrando salida
        for(int i=0;i<t;i++){
            if(numeros[i][0] < numeros[i][1]){
                cout<<"<"<<endl;
            }
            else if(numeros[i][0] > numeros[i][1]){
                cout<<">"<<endl;
            }
            else if(numeros[i][0] = numeros[i][1]){
                cout<<"="<<endl;
            }
            else{
                cout<<"Error no especificado"<<endl;
            }
        }
    }
    else{
        cout<<"Error"<<endl;
    }

    
    return 0;
}