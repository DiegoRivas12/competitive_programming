#include <iostream>
#include <vector>
using namespace std;
// Rotaciones: https://www.colegioconcepcionsanpedro.cl/wp-content/uploads/2020/07/GEOMETRIA-4%C2%BAC-G-NORAMBUENA-6-al-10-de-julio.pdf
struct Punto{

    int x;int y;int z;
    Punto(int x,int y,int z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    Punto(){

    }

};
void rotarY90(Punto,Punto&,char);
void rotarZ90(Punto,Punto&,char);
int main(){

    int L;
    int i=0;
    while(true){
        cin>>L;
        if(L==0){
            break;
        }
        //Creando Puntos de 0 hasta n
        Punto alambre[L+1]={};
        alambre[0].x=0;alambre[0].y=0;alambre[0].z=0;
        for(int p=1;p<=L;p++){
            alambre[p].x=p;alambre[p].y=0;alambre[p].z=0;
        }
        /*cout<<"Puntos Iniciales "<<i<<endl;
        for(int j=0;j<=L;j++){
            cout<<alambre[j].x<<" "<<alambre[j].y<<" "<<alambre[j].z<<endl;
        }*/

        string instruccion;
    
        //cout<<"xd"<<L<<endl;
        for(int j=L-1;j>0;j--){//Recepcion de instrucciones
            cin>>instruccion;
            //instruccionCaso.insert(instruccionCaso.begin(),instruccion);
            //instruccionCaso.push_back(instruccion);
            //cout<<instruccionCaso[j]<<endl;
            for(int k=j+1;k<=L;k++){//Des desde el punto de referencia rotaremos todos los puntos que estan a su derecha
                char signo=instruccion[0];
                if(instruccion[1]=='y'){
                    rotarY90(alambre[j],alambre[k],signo);//Punto puntoReferencial,Punto& puntoRotado
                }
                else if(instruccion[1]=='z'){
                    rotarZ90(alambre[j],alambre[k],signo);//Punto puntoReferencial,Punto& puntoRotado
                }
                else{//No
                    continue;
                }
            }
        }
        /*cout<<"Puntos finales "<<i<<endl;
        for(int j=0;j<=L;j++){
            cout<<alambre[j].x<<" "<<alambre[j].y<<" "<<alambre[j].z<<endl;
        }*/
        //Respuesta
        string respuesta;
        int x=alambre[L].x-alambre[L-1].x;
        int y=alambre[L].y-alambre[L-1].y;
        int z=alambre[L].z-alambre[L-1].z;
        if(x==1 && y==0 && z==0){
            cout<<"+x"<<endl;
        }
        else if(x==-1 && y==0 && z==0){
            cout<<"-x"<<endl;
        }
        else if(x==0 && y==1 && z==0){
            cout<<"+y"<<endl;
        }
        else if(x==0 && y==-1 && z==0){
            cout<<"-y"<<endl;
        }
        else if(x==0 && y==0 && z==1){
            cout<<"+z"<<endl;
        }
        else if(x==0 && y==0 && z==-1){
            cout<<"-z"<<endl;
        }
        //cout<<
        i++;
    }

    return 0;
}


void rotarY90(Punto puntoReferencial,Punto& puntoRotado,char signo){
    int x=puntoRotado.x-puntoReferencial.x;
    int y=puntoRotado.y-puntoReferencial.y;
    int z=puntoRotado.z-puntoReferencial.z;
    if(signo=='-'){// (x,y) -> (y,-x)
        puntoRotado.x=y;
        puntoRotado.y=-x;
    }
    else if(signo=='+'){// (x,y) -> (-y,x)
        puntoRotado.x=-y;
        puntoRotado.y=x;
    }

    //Sumamos el punto referencial
    puntoRotado.x=puntoRotado.x+puntoReferencial.x;
    puntoRotado.y=puntoRotado.y+puntoReferencial.y;
    puntoRotado.z=puntoRotado.z+puntoReferencial.z;
}
void rotarZ90(Punto puntoReferencial,Punto& puntoRotado,char signo){
    int x=puntoRotado.x-puntoReferencial.x;
    int y=puntoRotado.y-puntoReferencial.y;
    int z=puntoRotado.z-puntoReferencial.z;
    if(signo=='-'){// (x,z) -> (z,-x)
        puntoRotado.x=z;
        puntoRotado.z=-x;
    }
    else if(signo=='+'){// (x,z) -> (-z,x)
        puntoRotado.x=-z;
        puntoRotado.z=x;
    }
    //Sumamos el punto referencial
    puntoRotado.x=puntoRotado.x+puntoReferencial.x;
    puntoRotado.y=puntoRotado.y+puntoReferencial.y;
    puntoRotado.z=puntoRotado.z+puntoReferencial.z;
}