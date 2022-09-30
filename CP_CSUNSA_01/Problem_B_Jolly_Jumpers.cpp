#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
char convertir(char a);
int main(){
	string entrada;
	string convertido;

	while(!cin.eof()){
		entrada.clear();
		convertido.clear();

		cin>>entrada;
		int ultimo = 0;

		for(int i=0;i<entrada.size();i++){
			convertido+= convertir(entrada[i]);
		}
		for(int i=0;i<convertido.size();i++){

			if(convertido[i] == 0){
				ultimo = 0;
				continue;
			}
			else if( ultimo != convertido[i])
			{
				cout<<convertido[i];
				ultimo = convertido[i];
			}
		}
		cout<<endl;
	}
}
char convertir(char a){
	switch(a){
	case 'B':
	case 'F':
	case 'P':
	case 'V':
		return '1';
	case 'C':
	case 'G':
	case 'J':
	case 'K':
	case 'Q':
	case 'S':
	case 'X':
	case 'Z':
		return '2';
	case 'D':
	case 'T':
		return '3';
	case 'L':
		return '4';
	case 'M':
	case 'N':
		return '5';
	case 'R':
		return '6';
	default:
		return 0;
	}
}