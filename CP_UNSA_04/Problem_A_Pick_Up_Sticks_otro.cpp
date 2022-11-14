#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> indegree;
vector<vector<int>> adyacente;

int main() {
    int a, b;

    while (cin >> n) {
        indegree.assign(n, 0);
        adyacente.assign(n, {});

        cin >> m;

        if (n == 0 && m == 0) 
           break;

        while (m--) {
            cin >> a >> b;
            --a, --b;

            adyacente[a].push_back(b);//a esta encima de b
            indegree[b]++;
        }

        queue<int> q;//cola
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {//i no tiene ningunj palo encima
                q.push(i);
            }
        }

        vector<int> resultado;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            resultado.push_back(v);

            for (int u: adyacente[v]) {
                indegree[u]--;
                if (indegree[u] == 0) {
                    q.push(u);
                }
            }
        }

        if (resultado.size() != n) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int v: resultado) {
                cout << v + 1 << endl;
            }
        }
    }

    return 0;
}