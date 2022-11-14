#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> indegree;
vector<vector<int>> adyacente;

int main() {
    int a, b;
    int T;
    cin>>T;
    for(int j=0;j<T;j++){
        while (cin >> n) {
            indegree.assign(n, 0);
            adyacente.assign(n, {});

            cin >> m;

            if (n == 0 && m == 0) 
                break;

            while (m--) {
                cin >> a >> b;
                --a, --b;

                adyacente[a].push_back(b);//a hace caer b
                indegree[b]++;
            }

            queue<int> q;//cola
            int contFichas;//Fichas iniciales (que ninguna ficha las hace caer)
            vector<int> tomarFicha;//
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) {//i no tiene ningunj palo encima
                    //q.push(i);
                    tomarFicha.push_back(i);
                }
            }

            vector<int> resultado[tomarFicha.size()];

            for(int p=0;p<tomarFicha.size();p++){
                q.push(tomarFicha[p]);
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();

                    resultado[p].push_back(v);

                    for (int u: adyacente[v]) {
                        indegree[u]--;
                        if (indegree[u] == 0) {
                            q.push(u);
                        }
                    }
                }
            }
            int suma=0;
            for(int i=0;i<tomarFicha.size();i++){
                suma=suma+resultado[i].size();
            }
            if (suma == n) {
                cout << tomarFicha.size() << endl;
            } 
        }
    }
    

    return 0;
}