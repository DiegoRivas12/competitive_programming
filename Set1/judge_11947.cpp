#include <iostream>

using namespace std;
//Enero 1 Febrero 2 Marzo 3 Abril 4 Mayo 5 Junio 6
//Julio 7 Agosto 8 Septiembre 9 Octubre 10 Noviembre 11 Diciembre 12
int diasMes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool anioBisiesto(int);
string devolverSigno(int,int);
int main(){

    string entrada;
    int N;
    string dia,mes,anio;
    cin>>N;
    for(int i=0;i<N;i++){
        
        cin.ignore();
        cin>>entrada;
        
        anio=entrada.substr(4,4);
        mes=entrada.substr(0,2);
        dia=entrada.substr(2,2);
        /*cout<<anio<<endl;
        cout<<mes<<endl;
        cout<<dia<<endl;*/

        int anioActual,mesActual,diaActual;
        anioActual=stoi(anio);
        mesActual=stoi(mes);
        diaActual=stoi(dia);
        if(anioBisiesto(anioActual)){
            diasMes[2]=29;
        }
        else{
            diasMes[2]=28;
        }
        //40 semanas=40*7dias=280 dias
        int duracionDias=0;//Recorremos las 40 semanas
        int limiteDias=280;
        while(limiteDias>0){
            diaActual++;
            if(diasMes[mesActual]<diaActual){
                mesActual++;
                //limiteDias=limiteDias-diaActual;
                //cout<<"limite1 "<<limiteDias<<"mes "<<mesActual<<endl;
                diaActual=1;
                if(mesActual>12){
                    anioActual++;
                    mesActual=1;
                    if(anioBisiesto(anioActual)){
                        diasMes[2]=29;
                    }
                    else{
                        diasMes[2]=28;
                    }
                    /*limiteDias=limiteDias-diaActual;
                    cout<<"limite2 "<<limiteDias<<endl;*/
                    //diaActual=1;
                }
                
            }
            
            limiteDias--;
        }
        //cout<<i+1<<" "<<mesActual<<"/"<<diaActual<<"/"<<anioActual<<" "<<devolverSigno(diaActual,mesActual)<<endl;
        printf("%d %02d/%02d/%0004d %s\n", i+1, mesActual, diaActual, anioActual, devolverSigno(diaActual,mesActual).c_str());
        /*cout<<"anio "<<anioActual<<endl;
        cout<<"mes "<<mesActual<<endl;
        cout<<"dia "<<diaActual<<endl;*/
    }
    return 0;
}
bool anioBisiesto(int anio){
    if(((anio%4 == 0) && (anio%100 != 0)) || anio%400 == 0)
       return true;
    return false;
}
string devolverSigno(int dia,int mes){
    if( (mes==1 && 21<=dia && dia<=diasMes[mes]) || (mes==2 && 1<=dia && dia<=19) ){//January, 21 February, 19
        return "aquarius";
    }
    else if( (mes==2 && 20<=dia && dia<=diasMes[mes]) || (mes==3 && 1<=dia && dia<=20) ){//February, 20 March, 20
        return "pisces";
    }
    else if( (mes==3 && 21<=dia && dia<=diasMes[mes]) || (mes==4 && 1<=dia && dia<=20) ){//March, 21 April, 20
        return "aries";
    }
    else if( (mes==4 && 21<=dia && dia<=diasMes[mes]) || (mes==5 && 1<=dia && dia<=21) ){//April, 21 May, 21
        return "taurus";
    }
    else if( (mes==5 && 22<=dia && dia<=diasMes[mes]) || (mes==6 && 1<=dia && dia<=21) ){//May, 22 June, 21
        return "gemini";
    }
    else if( (mes==6 && 22<=dia && dia<=diasMes[mes]) || (mes==7 && 1<=dia && dia<=22) ){//June, 22 July, 22
        return "cancer";
    }
    else if( (mes==7 && 23<=dia && dia<=diasMes[mes]) || (mes==8 && 1<=dia && dia<=21) ){//July, 23 August, 21

        return "leo";
    }
    else if( (mes==8 && 22<=dia && dia<=diasMes[mes]) || (mes==9 && 1<=dia && dia<=23) ){//August, 22 September, 23

        return "virgo";
    }
    else if( (mes==9 && 24<=dia && dia<=diasMes[mes]) || (mes==10 && 1<=dia && dia<=23) ){//September, 24 October, 23

        return "libra";
    }
    else if( (mes==10 && 24<=dia && dia<=diasMes[mes]) || (mes==11 && 1<=dia && dia<=22) ){//October, 24 November, 22

        return "scorpio";
    }
    else if( (mes==11 && 23<=dia && dia<=diasMes[mes]) || (mes==12 && 1<=dia && dia<=22) ){//November, 23 December, 22

        return "sagittarius";
    }
    else if( (mes==12 && 23<=dia && dia<=diasMes[mes]) || (mes==1 && 1<=dia && dia<=20) ){//December, 23 January, 20

        return "capricorn";
    }
    return " ";
}