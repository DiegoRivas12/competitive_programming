/*
12503 - Robot Instructions
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    int z,x,ar[110],i,j;
    cin>>test;
    while(test--)
    {
        x = 0;
        cin>>z;
        string name,game;
        int ans;
        for(i=0; i<z; i++)
        {
            cin>>name;
            if(name[0]=='L')
            {
                ar[i]=-1;
                x--;
            }
            else if(name[0]=='R')
            {
                ar[i]=+1;
                x++;
            }
            else
            {
                cin>>game>>ans;
                ar[i]=ar[ans-1];
                x+=ar[i];

            }
        }
        cout<<x<<endl;
        name.erase(name.begin(), name.end());
    }
    return 0;
}
/*
Sample Input
2
3
LEFT
RIGHT
SAME AS 2
5
LEFT
SAME AS 1
SAME AS 2
SAME AS 1
SAME AS 4
Sample Output
1
-5
*/



/*#include <iostream>

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
}*/