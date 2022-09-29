#include <iostream>
#include <vector>
using namespace std;
struct Punto;
int main(){

    int L;
    
    vector<string> respuestas;
    int i=0;
    while(true){
        cin>>L;
        if(L==0){
            break;
        }
        string instruccion;
        vector<string> instruccionCaso;
        cout<<"xd"<<endl;
        while(cin>>instruccion){
            //instruccionCaso.insert(instruccionCaso.begin(),instruccion);
            if(instruccion[instruccion.size()-1]=='\0'){break;}
               //break;
            instruccionCaso.push_back(instruccion);
            //cout<<instruccionCaso[0]<<endl;
        }
        cout<<"Caso "<<i<<endl;
        for(int j=0;j<instruccionCaso.size();j++){
            cout<<instruccionCaso[i]<<endl;
        }
        i++;
    }

    return 0;
}

struct Punto{

    int x;int y;int z;
    Punto(int x,int y,int z){
        this->x=x;
        this->y=y;
        this->z=z;
    }

};