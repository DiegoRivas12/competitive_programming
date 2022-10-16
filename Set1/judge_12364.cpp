#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
void numerosBraille(char**,char,int);
string brailleNumeros(string[],int);
int main(){

    int D;//Numero de digitos del mensaje
    char letra;//Pueder 'S' o 'B'
    string digitosDecimales;//SI RECIBIMOS 'S'
    
    while(cin>>D){
        if(D==0)
          break;
        cin>>letra;
        if(letra=='S'){
            cin>>digitosDecimales;

            char **respuestaBraille = new char*[3];
            for (int i = 0; i < 3; i++) {
                respuestaBraille[i] = new char[2*D];
            }
            //cout<<D<<endl;
            //char respuestaBraille[3][D];//3*D (cada numero tiene 2 columnas)
            memset(respuestaBraille[0], '.', 2*D);
            memset(respuestaBraille[1], '.', 2*D);
            memset(respuestaBraille[2], '.', 2*D);
            //Transformando datos
            for(int i=0;i<D;i++){
                numerosBraille(respuestaBraille,digitosDecimales[i],i);
            }
            //Mostrando datos
            for(int i=0;i<3;i++){
                cout<<respuestaBraille[i][0]<<respuestaBraille[i][1];
                for(int j=2;j<2*D;){//Cada numero equivale a dos espacios en braille
                    cout<<" ";
                    
                    cout<<respuestaBraille[i][j]<<respuestaBraille[i][j+1];j++;j++;
                }
                cout<<endl;
            }

            //eLIMINACION DE LA MATRIZ
            for (int i = 0; i < 3; i++) {
                delete [] respuestaBraille[i];
            }
            delete [] respuestaBraille;
        }
        else if(letra=='B'){
            string lineasBraille[3];//Cada posicion del arreglo es una de las 3 filas de entrada si recibimos 'B'
            cin.ignore();
            for(int i=0;i<3;i++){
                getline(cin,lineasBraille[i]);
                //cout<<lineasBraille[i]<<endl;
            }
            string respuestaBraille="";
            //cout<<"XD"<<endl;
            for(int i=0;i<D;i++){
                //cout<<i<<endl;
                respuestaBraille=respuestaBraille+brailleNumeros(lineasBraille,i);
            }
            //cout<<"res "<<endl;
            cout<<respuestaBraille<<endl;
        }
    }
    return 0;
}

void numerosBraille(char**respuestaBraille,char numero,int ordenNumero){//ordenNumero va de 0 hasta n-1
    int i,j;//OrdenNumero define a que numero pertenece las modificaciones
    if(numero=='1'){
        respuestaBraille[0][0+2*ordenNumero]='*';
    }
    else if(numero=='2'){
        respuestaBraille[0][0+2*ordenNumero]='*';
        respuestaBraille[1][0+2*ordenNumero]='*';
    }
    else if(numero=='3'){
        respuestaBraille[0][0+2*ordenNumero]='*';
        respuestaBraille[0][1+2*ordenNumero]='*';
    }
    else if(numero=='4'){
        respuestaBraille[0][0+2*ordenNumero]='*';
        respuestaBraille[0][1+2*ordenNumero]='*';
        respuestaBraille[1][1+2*ordenNumero]='*';
    }
    else if(numero=='5'){
        respuestaBraille[0][0+2*ordenNumero]='*';
        respuestaBraille[1][1+2*ordenNumero]='*';
    }
    else if(numero=='6'){
        respuestaBraille[0][0+2*ordenNumero]='*';
        respuestaBraille[0][1+2*ordenNumero]='*';
        respuestaBraille[1][0+2*ordenNumero]='*';
    }
    else if(numero=='7'){
        respuestaBraille[0][0+2*ordenNumero]='*';
        respuestaBraille[0][1+2*ordenNumero]='*';
        respuestaBraille[1][0+2*ordenNumero]='*';
        respuestaBraille[1][1+2*ordenNumero]='*';
    }
    else if(numero=='8'){
        respuestaBraille[0][0+2*ordenNumero]='*';
        respuestaBraille[1][0+2*ordenNumero]='*';
        respuestaBraille[1][1+2*ordenNumero]='*';
    }
    else if(numero=='9'){
        respuestaBraille[0][1+2*ordenNumero]='*';
        respuestaBraille[1][0+2*ordenNumero]='*';
    }
    else if(numero=='0'){
        respuestaBraille[0][1+2*ordenNumero]='*';
        respuestaBraille[1][0+2*ordenNumero]='*';
        respuestaBraille[1][1+2*ordenNumero]='*';
    }
}
string brailleNumeros(string respuestaBraille[],int ordenNumero){//ordenNumero va de 0 hasta n-1
    int i,j;//OrdenNumero define a que numero pertenece las modificaciones
    if(respuestaBraille[0][0+3*ordenNumero]=='*' && respuestaBraille[0][1+3*ordenNumero]=='.' 
       && respuestaBraille[1][0+3*ordenNumero]=='.' && respuestaBraille[1][1+3*ordenNumero]=='.' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){//El mas 1 es porque el string contiene tambien la sepaacion de blancos
        return "1";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='*' && respuestaBraille[0][1+3*ordenNumero]=='.' 
       && respuestaBraille[1][0+3*ordenNumero]=='*' && respuestaBraille[1][1+3*ordenNumero]=='.' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "2";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='*' && respuestaBraille[0][1+3*ordenNumero]=='*' 
       && respuestaBraille[1][0+3*ordenNumero]=='.' && respuestaBraille[1][1+3*ordenNumero]=='.' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "3";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='*' && respuestaBraille[0][1+3*ordenNumero]=='*' 
       && respuestaBraille[1][0+3*ordenNumero]=='.' && respuestaBraille[1][1+3*ordenNumero]=='*' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "4";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='*' && respuestaBraille[0][1+3*ordenNumero]=='.' 
       && respuestaBraille[1][0+3*ordenNumero]=='.' && respuestaBraille[1][1+3*ordenNumero]=='*' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "5";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='*' && respuestaBraille[0][1+3*ordenNumero]=='*' 
       && respuestaBraille[1][0+3*ordenNumero]=='*' && respuestaBraille[1][1+3*ordenNumero]=='.' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "6";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='*' && respuestaBraille[0][1+3*ordenNumero]=='*' 
       && respuestaBraille[1][0+3*ordenNumero]=='*' && respuestaBraille[1][1+3*ordenNumero]=='*' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "7";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='*' && respuestaBraille[0][1+3*ordenNumero]=='.' 
       && respuestaBraille[1][0+3*ordenNumero]=='*' && respuestaBraille[1][1+3*ordenNumero]=='*' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "8";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='.' && respuestaBraille[0][1+3*ordenNumero]=='*' 
       && respuestaBraille[1][0+3*ordenNumero]=='*' && respuestaBraille[1][1+3*ordenNumero]=='.' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "9";
    }
    else if(respuestaBraille[0][0+3*ordenNumero]=='.' && respuestaBraille[0][1+3*ordenNumero]=='*' 
       && respuestaBraille[1][0+3*ordenNumero]=='*' && respuestaBraille[1][1+3*ordenNumero]=='*' 
       && respuestaBraille[2][0+3*ordenNumero]=='.' && respuestaBraille[2][1+3*ordenNumero]=='.'){
        return "0";
    }
    return "";
}