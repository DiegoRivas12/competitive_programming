#include <iostream>
#include <cstring>
using namespace std;

//minuscula ficha negra, mayuscula ficha blanca
//k rey r torre q reyna p peon
//b alfil n caballo

void llenarFilaTablero(bool [][8],char tablero[][8],int,string,int&);
int obtenerNumero(char);

void moverRey(bool [][8],char tablero[][8],int,int,int&);
void moverTorre(bool [][8],char tablero[][8],int,int,int&);
void moverAlfil(bool [][8],char tablero[][8],int,int,int&);
void moverReyna(bool [][8],char tablero[][8],int,int,int&);
void moverPeon(bool [][8],char tablero[][8],int,int,int&);
void moverCaballo(bool [][8],char tablero[][8],int,int,int&);
int main(){
    while(cin){
        
        string filas[8];
        for(int i=0;i<7;i++){
            getline(cin,filas[i],'/');
        }
        getline(cin,filas[7]);

        bool noAtacado[8][8]={};
        char tablero[8][8]={};
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                noAtacado[i][j]=false;
            }
        }
        //for(int i=0;i<8;i++){//Muestra las entradas iniciales
            //cout<<filas[i]<<" ";
        //}
        int suma_inicial=64;//Partimos del supuesto que ninguna ficha llega a ningun lado (tablero vacio)
        //Creamos el tablero
        for(int i=0;i<8;i++){
            llenarFilaTablero(noAtacado,tablero,i,filas[i],suma_inicial);
        }
        //Analizamos el tablero
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(noAtacado[i][j]==true && tablero[i][j]!=' '){//Una ficha encontrada
                    if(tolower(tablero[i][j])=='k'){//rey
                        moverRey(noAtacado,tablero,i,j,suma_inicial);
                    }
                    else if(tolower(tablero[i][j])=='r'){//torre
                        moverTorre(noAtacado,tablero,i,j,suma_inicial);
                    }
                    else if(tolower(tablero[i][j])=='q'){//reyna
                        moverReyna(noAtacado,tablero,i,j,suma_inicial);
                    }
                    else if(tolower(tablero[i][j])=='p'){//peon
                        moverPeon(noAtacado,tablero,i,j,suma_inicial);
                    }
                    else if(tolower(tablero[i][j])=='b'){//alfil
                        moverAlfil(noAtacado,tablero,i,j,suma_inicial);
                    }
                    else if(tolower(tablero[i][j])=='n'){//caballo
                        moverCaballo(noAtacado,tablero,i,j,suma_inicial);
                    }
                }       
            }
        }

        /*for(int i=0;i<8;i++){//Mostramos el tablero construido
            for(int j=0;j<8;j++){
                cout<<tablero[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Suma "<<suma_inicial<<endl;*/
        cout<<suma_inicial<<endl;
    }
    return 0;
}
void llenarFilaTablero(bool noAtacado[][8],char tablero[][8],int i,string fila,int& sumaInicial){
    int desplazar=0;
    for(int p=0;p<fila.size();p++){
        if('1'<=fila[p] && fila[p]<='8'){//Llenando espacios desocupados
            for(int l=0;l<obtenerNumero(fila[p]);l++){
                tablero[i][l+desplazar]=' ';
            }
            desplazar=desplazar+obtenerNumero(fila[p]);
        }
        else{//Fichas que estan en el tablero
            noAtacado[i][desplazar]=true;
            tablero[i][desplazar]=fila[p];
            sumaInicial--;//Los espacios ocupados por fichas no se consideran para el conteo
            desplazar++;
        }
    }
}

int obtenerNumero(char numero){
    if(numero=='1'){
        return 1;
    }
    else if(numero=='2'){
        return 2;
    }
    else if(numero=='3'){
        return 3;
    }
    else if(numero=='4'){
        return 4;
    }
    else if(numero=='5'){
        return 5;
    }
    else if(numero=='6'){
        return 6;
    }
    else if(numero=='7'){
        return 7;
    }
    else if(numero=='8'){
        return 8;
    }
    return 0;
}
void moverRey(bool noAtacado[][8],char tablero[][8],int x,int y,int& sumaInicial){//Para ficha blanca o negra el rey se mueve igual
    //x, y posicion de ka ficha del rey
    if(y-1>=0){//Mover izquierda
        if(noAtacado[x][y-1]==false && tablero[x][y-1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x][y-1]=true;tablero[x][y-1]='*';
        }
    }
    if(y+1<=8-1){//Mover Derecha
        if(noAtacado[x][y+1]==false && tablero[x][y+1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x][y+1]=true;tablero[x][y+1]='*';
        }
    }
    if(x-1>=0){//Mover arriba
        if(noAtacado[x-1][y]==false && tablero[x-1][y]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-1][y]=true;tablero[x-1][y]='*';
        }
    }
    if(x+1<=8-1){//Mover abajo
        if(noAtacado[x+1][y]==false && tablero[x+1][y]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+1][y]=true;tablero[x+1][y]='*';
        }
    }
    if(y-1>=0 && x-1>=0){//Diagonal superior izquierda
        if(noAtacado[x-1][y-1]==false && tablero[x-1][y-1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-1][y-1]=true;tablero[x-1][y-1]='*';
        }
    }
    if(y+1<=8-1 && x-1>=0){//Diagonal superior derecha
        if(noAtacado[x-1][y+1]==false && tablero[x-1][y+1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-1][y+1]=true;tablero[x-1][y+1]='*';
        }
    }
    if(y-1>=0 && x+1<=8-1){//Diagonal inferior izquierda
        if(noAtacado[x+1][y-1]==false && tablero[x+1][y-1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+1][y-1]=true;tablero[x+1][y-1]='*';
        }
    }
    if(y+1<=8-1 && x+1<=8-1){//Diagonal inferior derecha
        if(noAtacado[x+1][y+1]==false && tablero[x+1][y+1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+1][y+1]=true;tablero[x+1][y+1]='*';
        }
    }
}
void moverTorre(bool noAtacado[][8],char tablero[][8],int x,int y,int& sumaInicial){
    int movX=1;int movY=1;
    while(y+movY<=8-1){//Mover derecha
        if(noAtacado[x][y+movY]==false && tablero[x][y+movY]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x][y+movY]=true;tablero[x][y+movY]='*';movY++;
        }
        else if(noAtacado[x][y+movY]==true && tablero[x][y+movY]=='*'){//Para ignorar las posiciones vacias ya atacadas
            movY++;
        }
        else{//Nos encontramos una ficha en el camino
            break;
        }
    }
    movX=1;movY=1;
    while(y-movY>=0){//Mover izquierda
        if(noAtacado[x][y-movY]==false && tablero[x][y-movY]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x][y-movY]=true;tablero[x][y-movY]='*';movY++;
        }
        else if(noAtacado[x][y-movY]==true && tablero[x][y-movY]=='*'){//Para ignorar las posiciones vacias ya atacadas
            movY++;
        }
        else{//Nos encontramos una ficha en el camino
            break;
        }
    }
    movX=1;movY=1;
    while(x-movX>=0){//Mover arriba
        if(noAtacado[x-movX][y]==false && tablero[x-movX][y]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-movX][y]=true;tablero[x-movX][y]='*';movX++;
        }
        else if(noAtacado[x-movX][y]==true && tablero[x-movX][y]=='*'){//Para ignorar las posiciones vacias ya atacadas
            movX++;
        }
        else{//Nos encontramos una ficha en el camino
            break;
        }
    }
    movX=1;movY=1;
    while(x+movX<=8-1){//Mover abajo
        if(noAtacado[x+movX][y]==false && tablero[x+movX][y]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+movX][y]=true;tablero[x+movX][y]='*';movX++;
        }
        else if(noAtacado[x+movX][y]==true && tablero[x+movX][y]=='*'){//Para ignorar las posiciones vacias ya atacadas
            movX++;
        }
        else{//Nos encontramos una ficha en el camino
            break;
        }
    }
}
void moverAlfil(bool noAtacado[][8],char tablero[][8],int x,int y,int& sumaInicial){
    int movX=1;int movY=1;
    while(y-movY>=0 && x-movX>=0){//Mover diagonal superior izquierda
        if(noAtacado[x-movX][y-movY]==false && tablero[x-movX][y-movY]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-movX][y-movY]=true;tablero[x-movX][y-movY]='*';movY++;movX++;
        }
        else if(noAtacado[x-movX][y-movY]==true && tablero[x-movX][y-movY]=='*'){//Para ignorar las posiciones vacias ya atacadas
            movY++;movX++;
        }
        else{//Nos encontramos una ficha en el camino
            break;
        }
    }
    movX=1;movY=1;
    while(y+movY<=8-1 && x-movX>=0){//Mover diagonal superior derecha
        if(noAtacado[x-movX][y+movY]==false && tablero[x-movX][y+movY]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-movX][y+movY]=true;tablero[x-movX][y+movY]='*';movY++;movX++;
        }
        else if(noAtacado[x-movX][y+movY]==true && tablero[x-movX][y+movY]=='*'){//Para ignorar las posiciones vacias ya atacadas
            movY++;movX++;
        }
        else{//Nos encontramos una ficha en el camino
            break;
        }
    }
    movX=1;movY=1;
    while(y-movY>=0 && x+movX<=8-1){//Mover diagonal inferior izquierda
        if(noAtacado[x+movX][y-movY]==false && tablero[x+movX][y-movY]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+movX][y-movY]=true;tablero[x+movX][y-movY]='*';movX++;movY++;
        }
        else if(noAtacado[x+movX][y-movY]==true && tablero[x+movX][y-movY]=='*'){//Para ignorar las posiciones vacias ya atacadas
            movX++;movY++;
        }
        else{//Nos encontramos una ficha en el camino
            break;
        }
    }
    movX=1;movY=1;
    while(x+movX<=8-1 && y+movY<=8-1){//Mover diagonal inferior derecha
        if(noAtacado[x+movX][y+movY]==false && tablero[x+movX][y+movY]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+movX][y+movY]=true;tablero[x+movX][y+movY]='*';movX++;movY++;
        }
        else if(noAtacado[x+movX][y+movY]==true && tablero[x+movX][y+movY]=='*'){//Para ignorar las posiciones vacias ya atacadas
            movX++;movY++;
        }
        else{//Nos encontramos una ficha en el camino
            break;
        }
    }
}
void moverReyna(bool noAtacado[][8],char tablero[][8],int x,int y,int& sumaInicial){//Para ficha blanca o negra el rey se mueve igual
    //x, y posicion de ka ficha del rey
    moverTorre(noAtacado,tablero,x,y,sumaInicial);
    moverAlfil(noAtacado,tablero,x,y,sumaInicial);
}
void moverPeon(bool noAtacado[][8],char tablero[][8],int x,int y,int& sumaInicial){//Para ficha blanca o negra el rey se mueve igual
    //x, y posicion de ka ficha del rey
    if(tablero[x][y]=='p'){//ficha negra
        if(x+1<=8-1 && y-1>=0){//Mover diagonal izquierda
            if(noAtacado[x+1][y-1]==false && tablero[x+1][y-1]==' '){//Para ignorar las posiciones de las fichas
                sumaInicial--;noAtacado[x+1][y-1]=true;tablero[x+1][y-1]='*';
            }
        }
        if(x+1<=8-1 && y+1<=8-1){//Mover diagonal derecha
            if(noAtacado[x+1][y+1]==false && tablero[x+1][y+1]==' '){//Para ignorar las posiciones de las fichas
                sumaInicial--;noAtacado[x+1][y+1]=true;tablero[x+1][y+1]='*';
            }
        }
    }
    else{//ficha blanca
        if(x-1>=0 && y-1>=0){//Mover diagonal izquierda
            if(noAtacado[x-1][y-1]==false && tablero[x-1][y-1]==' '){//Para ignorar las posiciones de las fichas
                sumaInicial--;noAtacado[x-1][y-1]=true;tablero[x-1][y-1]='*';
            }
        }
        if(x-1>=0 && y+1<=8-1){//Mover diagonal derecha
            if(noAtacado[x-1][y+1]==false && tablero[x-1][y+1]==' '){//Para ignorar las posiciones de las fichas
                sumaInicial--;noAtacado[x-1][y+1]=true;tablero[x-1][y+1]='*';
            }
        }
    }
}
void moverCaballo(bool noAtacado[][8],char tablero[][8],int x,int y,int& sumaInicial){
    //8 movimientos a,b=+1,-1,+2,-2     x+b,y+a (b+a==3) && x+a,y+b (a+b==3)
    //seccion superior(x) izquierda(y)
    if(y-1>=0 && x-2>=0){
        if(noAtacado[x-2][y-1]==false && tablero[x-2][y-1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-2][y-1]=true;tablero[x-2][y-1]='*';
        }
    }
    if(y-2>=0 && x-1>=0){
        if(noAtacado[x-1][y-2]==false && tablero[x-1][y-2]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-1][y-2]=true;tablero[x-1][y-2]='*';
        }
    }

    //seccion superior derecha
    if(y+1<=8-1 && x-2>=0){
        if(noAtacado[x-2][y+1]==false && tablero[x-2][y+1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-2][y+1]=true;tablero[x-2][y+1]='*';
        }
    }
    if(y+2<=8-1 && x-1>=0){
        if(noAtacado[x-1][y+2]==false && tablero[x-1][y+2]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x-1][y+2]=true;tablero[x-1][y+2]='*';
        }
    }
    
    //seccion inferior izquierda
    if(y-2>=0 && x+1<=8-1){
        if(noAtacado[x+1][y-2]==false && tablero[x+1][y-2]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+1][y-2]=true;tablero[x+1][y-2]='*';
        }
    }
    if(y-1>=0 && x+2<=8-1){
        if(noAtacado[x+2][y-1]==false && tablero[x+2][y-1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+2][y-1]=true;tablero[x+2][y-1]='*';
        }
    }

    //seccion inferior derecha
    if(y+2<=8-1 && x+1<=8-1){
        if(noAtacado[x+1][y+2]==false && tablero[x+1][y+2]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+1][y+2]=true;tablero[x+1][y+2]='*';
        }
    }
    if(y+1<=8-1 && x+2<=8-1){
        if(noAtacado[x+2][y+1]==false && tablero[x+2][y+1]==' '){//Para ignorar las posiciones de las fichas
            sumaInicial--;noAtacado[x+2][y+1]=true;tablero[x+2][y+1]='*';
        }
    }
}