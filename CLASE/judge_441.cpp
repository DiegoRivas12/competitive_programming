#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int factorial(int);
int main(){

    int k;//6<k<13

    int contador=0;
    while(cin>>k){
        if(k==0){
            break;
        }
        else{
            int entrada[k+1]={};
            //Ingreso de datos
            
            for(int j=1;j<=k;j++){
                cin>>entrada[j];
            }
            //8 1 2 3 5 8 13 21 34
            int totalCombinacion=factorial(k)/(factorial(k-6)*factorial(6));
            cout<<" JAA"<<totalCombinacion<<endl;
            int posInicio=1;
            int inicio=1;//Recorrera todas las posibles conbinaciones
            int posUltimo=6;
            int guardarposUltimo=posUltimo;
            int restar=0;
            string parteDerecha="";
            while(inicio<=totalCombinacion){
                for(int i=posInicio;i<=posUltimo;i++){//Parte izquierda
                    //cout<<entrada[i]<<" ";
                    parteDerecha=parteDerecha+std::to_string(entrada[i])+" ";
                }
                int agregar=0;
                if(posUltimo==k){
                    
                    cout<<"assaas"<<endl;
                    cout<<parteDerecha<<endl;
                    //agregar=1;
                    break;
                }
                else{
                    //agregar=-1;
                }
                
                int numerosRestantes=k-(posUltimo)-1;//Numeros que sobran a la derecha quese pueden utilizar -1 para no contar el ultimo numero usado
                int posicionesDisponibles=abs(6-posUltimo);//Para saber si hay espacios a la derecha que se peudn llenar de la combinacion de 6
                int subCombinacion=factorial(numerosRestantes)/(factorial(numerosRestantes-(posicionesDisponibles))*factorial(posicionesDisponibles));
                int empieza=posUltimo+2;//Enpieza la segunda parte
                
                cout<<"restantes "<<numerosRestantes<<" ";
                cout<<" com "<<subCombinacion<<" posIni "<<posInicio<<" posFin "<<posUltimo<<" posiciones "<<posicionesDisponibles<<endl;
                for(int j=1;j<=abs(subCombinacion);j++){//Total de subcdenas agregando en la aprte derecha
                    cout<<parteDerecha; 
                    cout<<"a ";       
                    for(int p=0;p<posicionesDisponibles;p++){//Posiciones disponibles a llenar
                        //Se comportara como un ciclo la subcombinacion de la derecha
                        if(empieza+p<=k){
                            cout<<entrada[empieza+p]<<"f ";   
                        }
                        else{
                            cout<<entrada[(empieza+p)%6]<<" "; //Restamos menos 1, para ignorar el ultimoPos  
                        }
                        //inicio++;
                    }
                    empieza++;
                    //inicio++;
                    cout<<endl;
                }
                //inicio++;
                posUltimo--;
                if(posUltimo==posInicio-1){//posInicio-1==0
                    cout<<"ajjajaa"<<posInicio<<endl;
                    posUltimo=6+posInicio;
                    posInicio++;
                    restar++;
                }
                cout<<endl;
                parteDerecha="";
            }
           
        }
        //cout<<"entrada "<<entrada<<endl;
    }

    return 0;
}
int factorial(int numero){
    if(numero==0 || numero==1){
        return 1;
    }
    else if(numero>1){
        int inicio=1;
        for(int i=2;i<=numero;i++){
            inicio=inicio*i;
        }
        return inicio;
    }
    return -1;
}

/*
#include <iostream>
using namespace std;
int factorial(int);
int main(){

    int k;//6<k<13
    cin>>k;

    int contador=0;
    while(cin>>k){
        if(k==0){
            break;
        }
        else{
            int entrada[k+1]={};
            //Ingreso de datos
            
            for(int j=1;j<=k;j++){
                cin>>entrada[j];
            }

            int totalCombinacion=factorial(k)/(factorial(k-6)*factorial(6));
            cout<<" JAA"<<totalCombinacion<<endl;
            int inicio1=1;
            int inicio=1;
            while(inicio<=totalCombinacion){
                for(int i=inicio;i<=6-(inicio-1);i++){
                    cout<<entrada[i]<<" ";
                }
                for(int p=6-(inicio-1)+1;p<=k;p++){
                    cout<<entrada[p]<<" ";
                }
                cout<<endl;
                inicio++;
            }
        }
        //cout<<"entrada "<<entrada<<endl;
    }

    return 0;
}
int factorial(int numero){
    if(numero==0 || numero==1){
        return 1;
    }
    else if(numero>1){
        int inicio=1;
        for(int i=2;i<=numero;i++){
            inicio=inicio*i;
        }
        return inicio;
    }
    return -1;
}
*/