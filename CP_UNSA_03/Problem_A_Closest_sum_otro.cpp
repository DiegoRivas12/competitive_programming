#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
long int arregloSumas[1000000];
void realizarSumas(long int [],vector<long int>,int& );
long int busquedaBinaria(long int [], int tamano, int clave);

int main(){
    
    long int n,m,tmp,evaluarConsulta;
    int caso=1;
    while(cin>>n){
        
        std::vector<long int> numeros;
        for(int i=0;i<n;i++){
            cin>>tmp;
            numeros.push_back(tmp);
        }
        //std::sort(numeros.begin(), numeros.end());
        /*for (auto& elem : numeros)
            std::cout << elem << " - " << std::endl;*/
        //long int arregloSumas[numeros[numeros.size()-1] + numeros[numeros.size()-2]]={};//ultimo y penultimo de los numeros disponibles
        int pos=0;
        realizarSumas(arregloSumas,numeros,pos);
        std::sort(arregloSumas, arregloSumas+pos);
        //cout<<"Case 1:"<<endl;//Closest sum to 1 is 15.
        cout<<"Case "<<caso<<":"<<endl;//Closest sum to 1 is 15.
        cin>>m;
        int evaluar;
        for(int i=0;i<m;i++){
            cin>>evaluar;
            //cout<<"La pos "<<pos<<endl;
            if(evaluar<=arregloSumas[0]){//El numero mas cercano a el es el mismo numero
                cout<<"Closest sum to "<<evaluar<<" is "<<arregloSumas[0]<<"."<<endl;
            }
            else if(arregloSumas[pos-1]<=evaluar){//El numero evaluado es mas alto que la suma mas grande, por lo tanto el numero mas grande esta cerca de el
                cout<<"Closest sum to "<<evaluar<<" is "<<arregloSumas[pos-1]<<"."<<endl;
            }//arregloSumas[numeros.size()-1]>evaluar
            else{
                cout<<"Closest sum to "<<evaluar<<" is "<<busquedaBinaria(arregloSumas,pos,evaluar)<<"."<<endl;
            }
        }
        caso++;
    }
    return 0;
}
void realizarSumas(long int arregloSumas[], vector<long int> numeros,int& pos){
    for(int i=0;i<numeros.size();i++){
        for(int j=i+1;j<numeros.size();j++){
            if (numeros[i] == numeros[j]) continue;
            arregloSumas[pos]=numeros[i] + numeros[j];//La posicion es la suma y el contenido 1 indica que la suma existe en el conjunt
            pos++;
        }
    }
}
long int busquedaBinaria(long int arreglo[], int tamano, int clave){//Devuelve el numero mas cercano
    long int Iarriba = tamano-1;
    long int Iabajo = 0;
    long int Icentro;
    while (Iabajo <= Iarriba){
        //cout<<Iabajo<<" "<<Iarriba<<endl;
        Icentro = (Iarriba + Iabajo)/2;
        if(Iarriba - Iabajo == 1){
            //cout<<arreglo[Iabajo]<<" "<<arreglo[Iarriba]<<endl;
            //if(Iarriba==1 && Iabajo==0)//Devuelve primera posicion
                //return arreglo[0];
            if(clave - arreglo[Iabajo] > arreglo[Iarriba]-clave){
                return arreglo[Iarriba];
            }
            if(arreglo[Iarriba] - clave > arreglo[Iabajo]-clave){
                return arreglo[Iabajo];
            }
            if(arreglo[Iarriba] - clave == arreglo[Iabajo]-clave){
                return arreglo[Iabajo];
            }
            break;//2 3 5 7 9
        }
        
        /*if (arreglo[Icentro] == clave)
            return arreglo[Icentro];*/
        else
            if (clave < arreglo[Icentro])
                Iarriba=Icentro;//+1
            else
                Iabajo=Icentro;//-1
    }
    return -1;
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void realizarSumas(long int [],vector<long int>);
int main(){
    
    long int n,m,tmp,evaluarConsulta;
    int caso=1;
    while(cin>>n){
        
        std::vector<long int> numeros;
        for(int i=0;i<n;i++){
            cin>>tmp;
            numeros.push_back(tmp);
        }
        std::sort(numeros.begin(), numeros.end());
        //for (auto& elem : numeros)
            //std::cout << elem << " - " << std::endl;
        long int arregloSumas[numeros[numeros.size()-1] + numeros[numeros.size()-2]]={};//ultimo y penultimo de los numeros disponibles

        realizarSumas(arregloSumas,numeros);

        cout<<"Case 1:"<<endl;//Closest sum to 1 is 15.
        cin>>m;
        int evaluar;
        for(int i=0;i<m;i++){
            cin>>evaluar;
            if(arregloSumas[evaluar]==1){//El numero mas cercano a el es el mismo numero
                cout<<"Closest sum to "<<evaluar<<" is "<<evaluar<<"."<<endl;
            }
            else if(arregloSumas[evaluar]==0){//El numero evaluado no es una suma disponible, debemos buscar en izquierda y derecha
                int recorre=0;
                while(true){
                    if(arregloSumas[evaluar-recorre]==1){//Evaluamos izquierda
                        cout<<"Closest sum to "<<evaluar<<" is "<<evaluar-recorre<<"."<<endl;break;
                    }
                    else if(arregloSumas[evaluar+recorre]==1){//Evaluamos derecha
                        cout<<"Closest sum to "<<evaluar<<" is "<<evaluar+recorre<<"."<<endl;break;
                    }
                    recorre++;
                }
            }
            else if(arregloSumas[numeros.size()-1]<evaluar){//El numero evaluado es mas alto que la suma mas grande, por lo tanto el numero mas grande esta cerca de el
                cout<<"Closest sum to "<<evaluar<<" is "<<arregloSumas[numeros.size()-1]<<"."<<endl;
            }//arregloSumas[numeros.size()-1]>evaluar
        }
        caso++;
    }
    return 0;
}
void realizarSumas(long int arregloSumas[], vector<long int> numeros){
    for(int i=0;i<numeros.size();i++){
        for(int j=i+1;j<numeros.size();j++){
            arregloSumas[numeros[i] + numeros[j]]=1;//La posicion es la suma y el contenido 1 indica que la suma existe en el conjunto
        }
    }
}
*/

  