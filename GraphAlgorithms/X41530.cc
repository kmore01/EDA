#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef vector< vector<int> > grafo;

// Funcion para leer el grafo de entrada
grafo leer(int f, int c) {
    grafo aux(f, vector<int>(0));
    for (int i = 0; i < c; ++i) {
        int nodo1, nodo2;
        cin >> nodo1 >> nodo2;
        aux[nodo1].push_back(nodo2);
        aux[nodo2].push_back(nodo1);
    }
    return aux;
}

// Funcion que se utiliza para saber el numero de componentes conexas y si hay 
// ciclos usando el DFS
void dfs_rec (const grafo &G, int u, vector<bool>& vis, vector<int> &padre, bool &ciclos) {
    vis[u] = true;
    for (int v : G[u]) {
        if (not vis[v]) {
            padre[v] = u; // El padre de v es u
            dfs_rec(G, v, vis, padre, ciclos);
        }
        else if (v != padre[u]) {
            ciclos = true;
        }
        if (ciclos) return;
    }
}

// Funcion que imprime no en caso de que G no sea un arbol o el numero de 
// componentes conexas si lo es
void dfs(const grafo &G) {
    int n = G.size();
    vector<bool> visit(n, false);
    vector<int> padre(n, -1); // Nos guardamos el padre de cada nodo
    int compConex = 0;
    bool ciclos = false;
    for (int u = 0; u < n; ++u) {
        if (not visit[u]) {
            dfs_rec(G, u, visit, padre, ciclos);   
            ++compConex;
            if (ciclos == 1) {
                cout << "no" << endl;
                return;
            }
        }
    }
    cout << compConex << endl;
}

int main () {
    int n, m; // 1 <= n <= 10^4, 0 <= m < n
    while (cin >> n >> m ) {
        grafo entrada = leer(n, m);
        dfs(entrada);
    }
}