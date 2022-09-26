#include <iostream>
#include <fstream>
#include <vector>
//Problema 2595

using namespace std;
void extraerNumeros(string,int[],int);
void MERGE_SORT(int* A,int p,int r,int cantX,int canY);
void MERGE(int* A,int p,int q,int r,int cantX,int canY);

void MERGE_SORT(int**,int* A,int p,int r,int cantX,int canY);
void MERGE(int**,int* A,int p,int q,int r,int cantX,int canY);
void intercambiar(int**m,int x,int y,int fila1,int fila2);
bool hayCamas(int*,int,int);
void mostrarArreglo(int* m,int Cantx){
    if(m!=nullptr){
        for (int j = 0; j < Cantx; j++){
        std::cout<<m[j]<<" ";
    }
    std::cout<<endl;
    }
    
}
void mostrarMatriz(int** m,int Cantx,int cantY){
    if(m!=nullptr){
        for (int i = 0; i < Cantx; i++){
        for (int j = 0; j < cantY; j++){
            std::cout<<m[i][j]<<" ";
        }
        std::cout<<endl;
    }
    }
    
}
int main(){

    ifstream archivo("archivo_11559.txt");//
    string linea;
    int g=0;
    vector<int> salida;
    while(!archivo.eof()){//Lee cada uno de los casos//
        int primerLinea[4];//numero participantes, presupuesto, cantidad hoteles, semanas de eleccion
        int i=0,j=0;
        getline(archivo,linea);

        extraerNumeros(linea,primerLinea,4);
    
        int N=primerLinea[0],B=primerLinea[1],H=primerLinea[2],W=primerLinea[3];
        //int a[H][W];//Numero de camas disponibles cada fin de semana en el hotel
        int**a=nullptr;//
        int* p=nullptr;//
        a=new int*[H];//filas
        for(int i=0;i<H;i++){
            a[i]=new int[W];//Creando columnas
        } 
        //int p[H];//Precio d una persona
        p=new int[H];

        if(1<=N && N<=200 && 1<=B && B<=500000 && 1<=H && H<=18 && 1<=W && W<=13){
            for(int m=0;m<H;m++){
                getline(archivo,linea);//Precio d una persona
                p[m]=stoi(linea);
                getline(archivo,linea);
                
                extraerNumeros(linea,a[m],W);//Numero de camas disponibles cada fin de semana en el hotel
            }
        }
        //Analisis de datos para decidir si viajamos o no
        
        MERGE_SORT(a,p,0,H-1,H,W);//Ordenamos los datos priorizando los mas baratos//
        
        for(int o=0;o<H;o++){
            //int precioHotel=minimo(p,H);
            if(N*p[o]>B){
                if(o==H-1){//Hemos verificado hasta el ultimo hotel y nada     
                    salida.push_back(-1);//error
                    break;
                }
                continue;
            }                
            //hayCamas(a[o],N,W);
            
            MERGE_SORT(a[o],0,W-1,W,H);//Ordenamos los datos priorizando los mas baratos
            //hayCamas(a[o],N,W);

            if(hayCamas(a[o],N,W)){//Si el presupuesto alcanza y hay numero de camas disponibles
                int tmp=p[o];
                salida.push_back(N*tmp);
                    
                break;
            }
                
        }
        mostrarArreglo(p,H);
        mostrarMatriz(a,H,W);
            
        for(int i=0;i<H;i++) {//Borraando matriz
            delete [] a[i];
        }
        delete[] a;
        delete[] p;
        a=nullptr;p=nullptr;
            
        
        
        g++;
    }
    
    //Mostrando la salida
    std::cout<<"OUTPUT"<<endl;
    for(int i=0;i<salida.size();i++){
        if(salida[i]!=-1){
            std::cout<<salida[i]<<endl;
        }
        else{
            std::cout<<"stay home"<<endl;
        }
    }
    
    
    return 0;
}
void extraerNumeros(string linea,int v[],int lon){
    int i=0,j=0;
    while(i<linea.size()){
        if(linea[i]==' ' || linea[i]=='\n'){
            v[j]=stoi(linea.substr(0,linea.substr(0,i).size()));
            //std::cout<<"nhahaaaa"<<endl;
            //std::cout<<v[j]<<endl;
            linea=linea.substr(i+1,linea.size());
            j++;
            i=0;
        }
        i++;
    }
    v[j]=stoi(linea);//leemos el cuarto numero
    //std::cout<<v[lon-1]<<endl;
}

void MERGE_SORT(int**m,int* A,int p,int r,int cantX,int canY){//p izquierda q medio r derecha
    if(p<r){
        int q=((p+r)/2);
        MERGE_SORT(m,A,p,q, cantX, canY);//divide
        MERGE_SORT(m,A,q+1,r, cantX, canY);//divide
        MERGE(m,A,p,q,r, cantX, canY);//junta
    }
}

void MERGE(int**m,int* A,int p,int q,int r,int cantX,int canY){
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;

    
    //vector<int>L(n1+1);
    int L[n1+1]={};
    int R[n2+1]={};
    //vector<int>R(n2+1);

    for(i=0;i<=n1-1;i++){
        L[i]=A[p+i];
    }

    for(j=0;j<=n2-1;j++){
        R[j]=A[q+j+1];
    }
    L[n1]=INT32_MAX;
    R[n2]=INT32_MAX;  

    i=0;
    j=0;
    //p->inicio r->final n1->elementosIzq n2->elementosDer
    for(k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            intercambiar(m,cantX,canY,k,i);
            i=i+1;
        }
        else{//L[i]>R[j]
            A[k]=R[j];
            //intercambiar(m,cantX,canY,k,j);
            j=j+1;
        }
        
    }
}
void intercambiar(int**m,int x,int y,int fila1,int fila2){
    for(int j=0;j<y;j++){
        swap(m[fila1][j],m[fila2][j]);
    }
}
void MERGE_SORT(int* A,int p,int r,int cantX,int canY){//p izquierda q medio r derecha
    if(p<r){
        int q=((p+r)/2);
        MERGE_SORT(A,p,q, cantX, canY);//divide
        MERGE_SORT(A,q+1,r, cantX, canY);//divide
        MERGE(A,p,q,r, cantX, canY);//junta
    }
}

void MERGE(int* A,int p,int q,int r,int cantX,int canY){
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;

    
    //vector<int>L(n1+1);
    int L[n1+1]={};
    int R[n2+1]={};
    //vector<int>R(n2+1);

    for(i=0;i<=n1-1;i++){
        L[i]=A[p+i];
    }

    for(j=0;j<=n2-1;j++){
        R[j]=A[q+j+1];
    }
    L[n1]=INT32_MAX;
    R[n2]=INT32_MAX;  

    i=0;
    j=0;
    //p->inicio r->final n1->elementosIzq n2->elementosDer
    for(k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            //intercambiar(m,cantX,canY,k,i);
            i=i+1;
        }
        else{//L[i]>R[j]
            A[k]=R[j];
            //intercambiar(m,cantX,canY,k,j);
            j=j+1;
        }
        
    }
}
bool hayCamas(int* v,int cantCama,int lon){//cantCama la cantidad de camas que necesitamos
    int contar=0;
    for(int i=0;i<lon;i++){
        if(cantCama<=v[i]){
            //return true;
            contar++;
        }
    }
    if(contar==cantCama){
        return true;
    }
    return false;
}