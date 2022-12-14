#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define maxN 10
string code[maxN];

main() {

    string code[maxN];
    int n, Case = 0;
    while (cin >> code[0]) {
        n = 0;
        do {
            n++;
            cin >> code[n];
        } while (code[n][0]!='9');
        bool yes = true;
        for (int i=0; i<n && yes; i++)
            for (int j=i+1; j<n && yes; j++) {
                string s = code[i].substr(0, code[j].length());
                if (s==code[j]) yes = false;
                s = code[j].substr(0, code[i].length());
                if (s==code[i]) yes = false;
            }
        printf("Set %d is ", ++Case);
        if (!yes) printf("not ");
        printf("immediately decodable\n");
    }
}