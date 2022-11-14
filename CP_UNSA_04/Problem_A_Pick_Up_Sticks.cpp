#include <iostream>
#include <vector>

using namespace std;
#define maxN 100111

int color[maxN];
vector<int> adyacente[maxN], nodOrdenado;
bool posible;

void visit(int u);

int main() {
	
	int n, m, u, v;
	while (scanf("%d %d", &n, &m) && (n || m)) {
		for (int i = 1; i <= n; i++)//n CANTIDAD DE PALOS
			color[i] = 0, adyacente[i].clear();
		while (m--) {//Palo u encima del palo v
			scanf("%d %d", &u, &v);
			adyacente[u].push_back(v);
		}
		posible = true;
		nodOrdenado.clear();
		for (int i = 1; i <= n && posible; i++)
			if (color[i] == 0) visit(i);
		if (!posible)
			puts("IMPOSSIBLE");
		else {
			for (int i = nodOrdenado.size() - 1; i >= 0; i--)
				printf("%d\n", nodOrdenado[i]);
		}
	}
	return 0;
}
void visit(int u) {
	if (!posible) return;
	color[u] = 1;//GRIS
	for (int i = 0; i < adyacente[u].size(); i++) {
		int v = adyacente[u][i];//u nodo, i NODOS ADYACENTES
		if (color[v] == 0) visit(v);//BLANCO (NO FUE VISITADO)
		else if (color[v] == 1) {//GRIS (YA FUE VISITADO)
			posible = false;
			return;
		}
	}
	nodOrdenado.push_back(u);
	color[u] = 2;//NEGRO (YA ANALIZADO)
}