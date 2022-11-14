#include <bits/stdc++.h>
using namespace std;

int t,n,m,a,b,dfsCounter,numSCC;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> S;
vector<bool> visited;
vector<vector<int>> graph;
vector<int> componentId;

void tarjanSCC(int u){
    //dfs_low[u] que representa el índice más pequeño de cualquier nodo en la pila que se sabe que es 
    //accesible desde u a través del subárbol DFS de u, incluido u mismo.
    dfs_num[u] = dfs_low[u] = dfsCounter++;//Enumeramos los nodos en el orden en el que se descubren
    visited[u] = true;
    S.push_back(u);
    for(auto& neigh : graph[u]){//Sucesores de u
        if(dfs_num[neigh] == -1)//neigh aun no ha sido visitado
            tarjanSCC(neigh);
        if(visited[neigh])//visitado
            dfs_low[u] = min(dfs_low[u],dfs_low[neigh]);//enl
    }
    // es una raiz de SCC
    if(dfs_low[u] == dfs_num[u]){//dfs_num indice
        numSCC++;
        while(true){
            int top = S.back(); S.pop_back();
            componentId[top] = numSCC; // asignar SCC  a vértice
            visited[top] = false;
            if(u == top) break;
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        dfsCounter = numSCC = 0;
        dfs_num.assign(n,-1);
        dfs_low.assign(n,0);
        S.clear();
        visited.assign(n,false);
        graph.assign(n,vector<int>());
        componentId.assign(n,-1);
        
        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            a--; b--;
            graph[a].push_back(b);
        }
        for(int i=0;i<n;i++)
            if(dfs_num[i] == -1){
                tarjanSCC(i);
            }
        // cuenta en grados de cada SCC (strongly connected components)
        vector<int> componentIndegree(numSCC,0);
        for(int i=0;i<n;i++)
            for(auto& neigh : graph[i]){
                // no dentro del mismo componente fuertemente conexo
                if(componentId[neigh] != componentId[i])
                    componentIndegree[componentId[neigh]]++;
            }
        int res = count(componentIndegree.begin(),componentIndegree.end(),0);
        printf("%d\n",res);
    }
}
/*
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
*/