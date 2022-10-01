#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<queue>
#include<stdlib.h>
#include<algorithm>
#include<map>

 
int main(){
	int n;
	cin>>n;
	while( n!=0){
		string s[10001];
		int a[5];

		for( int i=0; i!=n; ++i){
			s[i]="";

			cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
			sort(a,a+5);

			for( int j=0; j!=5; ++j){
				s[i]+=char(a[j]/100+'0');
				s[i]+=char((a[j]/10)%10+'0');
				s[i]+=char(a[j]%10+'0');
			}

		}

		map<string, int> word;
		for( int i=0; i!=n; ++i)
		++word[s[i]];

		int max=0; 
		map<string, int>::iterator iter=word.begin();
		while( iter!=word.end()){
			if( iter->second >max) max=iter->second;
			iter++;
		}

		int num=0; 
		iter=word.begin();

		while( iter!=word.end()){
			if( iter->second == max) num+=iter->second; 
			iter++;
		}

		cout<<num<<endl;

		cin>>n;
}

 
return 0;

}