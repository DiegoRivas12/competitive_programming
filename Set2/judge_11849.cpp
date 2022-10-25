#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 10010000;
LL jack, jill;
LL a[maxn];
int main() {
    while(cin >> jack >> jill) {//Discos de Jack y Jill
        if(jill == 0 && jack == 0)
            break;
        LL x, cnt = 0;
        memset(a, 0, sizeof(a));//Lenamos a de puro ceros
        for(LL i = 0; i < jack; i++) {//Registrando discos de Jack
            cin >> x;
            a[x] = 1;
        }
        for(LL i = 0; i < jill; i++) {//Registrando discos de Jill
            cin >> x;
            if(a[x])
                cnt++;
        }
        cout << cnt << endl;
    }
}