#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NODE 1000010
struct Edge{
    int st;
    int en;
    int w;
}g[MAX_NODE];
bool comp(Edge e1, Edge e2){
    return (e1.w < e2.w);
}
int pre[MAX_NODE];
int findPre(int u){
    if(pre[u]==u)return u;
    else return pre[u]=findPre(pre[u]);
}

int main(){
    int  prest, preen, nodes, edges;
    int maxDist,treeEdge;
    while(scanf("%d %d", &nodes, &edges)==2 && nodes!=0){

        for(int i=0; i<=edges-1; i++){
            pre[i] = i;
        }
        for(int i=0; i<=edges-1; i++){
            cin >> g[i].st >> g[i].en >> g[i].w;
        }
        sort(&g[0],g+edges,comp);
        treeEdge = maxDist = 0;
        for(int i=0; i<=edges-1; i++){
            prest = findPre(g[i].st);
            preen = findPre(g[i].en);
            if(prest!=preen) {
                pre[prest] = preen;
                treeEdge++;
                maxDist = max(maxDist,g[i].w);
            }
        }
        if(treeEdge==nodes-1)printf("%d\n", maxDist);
        else printf("IMPOSSIBLE\n");
    }

  return 0;
}
//retorna el elemento representativo del conjunto en el que está el i-ésimo elemento
// kruskal lista de aristas