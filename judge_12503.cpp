#include <iostream>
//Problema 3947
#include <string>
using namespace std;

int main(){

    int T;
    int x=0;
    cin>>T;
    int respuesta[T];
    if(T<=100){
        for(int i=0;i<T;i++){
            int n;
            string instruccion;
            cin>>n;
            int registroInstru[n];
            cin.ignore();
            if(1<=n && n<=100){
                for(int j=0;j<n;j++){
                    //cout<<"haaa "<<instruccion<<endl;
                    
                    getline(cin,instruccion);
                    //cin>>instruccion;
                    //cout<<"haaa "<<instruccion<<endl;
                    if(instruccion=="LEFT"){
                        x--;
                        registroInstru[j]=-1;
                    }
                    else if(instruccion=="RIGHT"){
                        x++;
                        registroInstru[j]=1;
                    }
                    else if(instruccion.substr(0,7)=="SAME AS"){
                        //cout<<"entro"<<endl;
                        string agregar = instruccion.substr(8,instruccion.size()-7-1);
                        cout<<agregar<<endl;
                        int numAgregar = stoi(agregar);
                        
                        x=x+registroInstru[numAgregar-1];
                        registroInstru[j]=registroInstru[numAgregar-1];
                    }
                    //cin.clear();
                }
                //cout<<"Respuesta"<<x<<endl;
                respuesta[i]=x;
                x=0;
            }
        }
        //Mostrand resultados
        cout<<"Salida"<<endl;
        for(int i=0;i<T;i++){
            cout<<respuesta[i]<<endl;
        }
    }
    return 0;
}