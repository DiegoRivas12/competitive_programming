#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int j=0;
    int n;//Cantidad de numero por caso
    while(!(cin >> n).eof() && j<10){
        
        //cin>>n;
        /*bool lectura_correcta = static_cast<bool>(std::cin); // !std::cin.fail()
        if (lectura_correcta==false) {
            //std::cout << "No lee numeros\n";
            break;
        } else {
            //std::cout << "Lo que ingreso no es un entero\n";
        }*/
        cout<<"n "<<n<<endl;
        bool evaluandoSaltos[n-1]={};
        int contadorSaltos=0;
        int numeros[n];//Numeros a evaluar por caso
        /*for(int i = 0; i < n-1; i++ )
			evaluandoSaltos[i] = false;*/
        for(int i=0;i<n;i++){//Ingreso de los numeros
            int pivot;
            cin>>pivot;
            numeros[i]=pivot;
        }

        for(int i=0;i<n-1;i++){//Ingreso de numeros a evaluar
            //cout<<"uno"<<endl;
            int valor=abs(numeros[i]-numeros[i+1]);//(getchar()) != '\n'c
            if(valor>=n || valor<1){//Excede limite
                //casos[j]="Not jolly";
                cout<<"Not jolly"<<endl;
                break;
            }
            else if(evaluandoSaltos[valor-1]==false){//Aun no se registro ese numero si esta en falso
                contadorSaltos++;//3
                evaluandoSaltos[valor-1]=true;
            }
            else if(evaluandoSaltos[valor-1]==true){//El numero ya esta registrado
                //casos[j]="Not jolly";1 4 2 3
                cout<<"Not jolly"<<endl;// {1,1,1}
                break;
            }
        }// 4 5 6 1 2
        if(contadorSaltos==n-1){// 1 2 3 4
            //casos[j]="Jolly";
            cout<<"Jolly"<<endl;
        }
        //cout<<casos[j]<<endl;
        j++;
        
    }
    return 0;
}