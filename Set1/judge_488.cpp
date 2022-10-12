#include<iostream>
using namespace std;
void crearOnda(int,int);
int main(){

    int n;//Numero de casos
    int amplitud,frecuencia;
    string blanco;
    cin>>n;
    //cin>>blanco;
    getline(cin,blanco);

    for(int i=0;i<n;i++){
        cin>>amplitud;
        cin>>frecuencia;
        cout<<endl;
        crearOnda(amplitud,frecuencia);
        //cin>>blanco;
        
        getline(cin,blanco);
        if(i==n-1)
           cout<<endl;
    }
    return 0;
}
void crearOnda(int amplitud,int frecuencia){
    for(int f=0;f<frecuencia;f++){
        for(int i=1;i<=amplitud;i++){
            for(int j=1;j<=i;j++){
                cout<<i;
            }
            cout<<endl;
        }
        for(int i=amplitud-1;i>=1;i--){
            for(int j=i;j>=1;j--){
                cout<<i;
            }
            cout<<endl;
        }
        if(f!=frecuencia-1)
            cout<<endl;
    }
}