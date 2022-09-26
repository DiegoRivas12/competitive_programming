#include <iostream>
#include <vector>
//Problema 3166
using namespace std;
int hallarMayor(int[],int);
int main(){ 
    int T;
    string auxURL;
    int auxV;
    cin>>T;
    vector<vector<string>> casos(T);
    for(int i=0;i<T;i++){//Numeros de casos
        int mayor;
        string URL[10];
        int V[10];
        for(int j=0;j<10;j++){//10 paginas por cada caso
            cin>>auxURL;
            cin>>auxV;
            if(1<=auxURL.size() && auxURL.size()<=100 && 1<=auxV && auxV<=100){
                //cout<<"HAHAHAH"<<endl;
                URL[j]=auxURL;
                V[j]=auxV;
                //cout<<"HAHAHAHsasa"<<endl;
                //cout<<"url "<<URL[j]<<"v "<<V[j]<<endl;;
            }
        }
        //cout<<"urla "<<URL[9]<<"va "<<V[9]<<endl;;
        
        mayor=hallarMayor(V,10);//Pagina mas rankeada
        //cout<<"Mayor "<<mayor<<endl;
        //Escogiendo paginas rankeadas que coincidan en ser el mayor
        for(int p=0;p<10;p++){
            if(V[p]==mayor){
                casos[i].push_back(URL[p]);
            } 
        }
    }
    //Mostrando datos
    for(int i=0;i<T;i++){
        cout<<"Caso #"<<i+1<<":"<<endl;
        for(int j=0;j<casos[i].size();j++){
            cout<<casos[i][j]<<endl;
        }
    }
    return 0;
}

int hallarMayor(int V[],int lon){
    int mayor=V[0];
    for(int i=1;i<lon;i++){
        if(V[i]>mayor){
            mayor=V[i];
        }
    }
    return mayor;
}