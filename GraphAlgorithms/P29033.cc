// Programa que escribe si se puede o no pintar todos los vertices de un grafo 
// no dirigido con solo dos colores sin que haya vecinos con el mismo color

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > grafo;

// Funcion para leer un grafo no dirigido
void leer(grafo &g, int m) {
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
}

// Funcion que devuelve true si un grafo se puede pintar con 2 colores sin que 
// haya 2 vertices con el mismo color
bool dfs(const grafo &g, vector<int> &color, int v, int colorActual) {
    color[v] = colorActual;
    int col = 0;
    if (colorActual == 0) col = 1;
    for (int u : g[v]) { // Nos recorremos los vecinos de v
        if (color[u] == color[v]) return false; // Caso base
        else if (color[u] == -1) { // Si el vecino no esta pintado
            if (not dfs(g, color, u, col)) return false;
        }
    }
    return true;
}

// Funcion auxiliar para determinar si um grafo se puede pintar con 2 colores 
// sin que haya 2 vertices con el mismo color
bool coloreable2(const grafo &g) {
    int n = g.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) { // Nos recorremos todos los vertices
        if (color[i] == -1) { // No pintado
            if (not dfs(g, color, i, 0)) return false;
        }
    }
    return true;
}

int main () {
    int n, m; // 1 <= n <= 10000, 0 <= m <= 5,
    while (cin >> n >> m) {
        grafo g(n, vector<int>(0));
        leer(g, m);
        if (coloreable2(g)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}