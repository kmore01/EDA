#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > grafo;

const int DI[4] = {1, 0, -1, 0};
const int DJ[4] = {0, 1, 0, -1};

// Funcion para leer el grafo de entrada
grafo leer(int f, int c) {
    grafo aux(f, vector<char>(c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> aux[i][j];
        }
    }
    return aux;
}

// Funcion que devuelve true si existe e[i][j]
bool dinsLimit(const grafo &e, int i, int j) {
    return 0 <= i and i < e.size() and 0 <= j and j < e[0].size();
}

// Funcion que devuelve el numero de tesoros que puedes encontrar empezando 
// desde G[i][j]
int dfs(const grafo &G, vector<vector<bool> > &visit, int i, int j) {
    int contador = 0;
    if (not visit[i][j]) {
        visit[i][j] = true;
        if (G[i][j] == 't') ++contador;
        if (G[i][j] != 'X') {
            for (int k = 0; k < 4; ++k) {
                int ii = i + DI[k];
                int jj = j + DJ[k];
                if (dinsLimit(G, ii, jj)) contador += dfs(G, visit, ii, jj);
            }
        }
    }
    return contador;
}

int main ()  {
    int n, m; // n, m > 0
    cin >> n >> m;
    grafo mapa = leer(n, m);
    vector<vector<bool> > visitados(n, vector<bool>(m, false));
    int f, c; // 1 < f < n, 1 < c < m
    cin >> f >> c;
    cout << dfs(mapa, visitados, f - 1, c - 1) << endl;
}