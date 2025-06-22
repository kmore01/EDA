#include <iostream>
#include <vector>
#include <queue>

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

// Funcion que calcula la distancia minima para encontrar tesoro desde G[i][j]
int bfs(const grafo &G, int i, int j) {
    int nodos = G.size(), distMin = -1;
    queue<pair <pair <int, int>, int> > Q; // ((i, j), distancia)
    vector<vector<bool> >visit(nodos, vector<bool>(G[0].size(), false));
    Q.push({{i, j}, 0}); // La distancia del primer nodo es 0
    while (not Q.empty()) {
        int x = Q.front().first.first; // Posicion x del nodo
        int y = Q.front().first.second; // Posicion y del nodo
        int dist = Q.front().second; // Distancia del nodo respecto al comienzo
        visit[x][y] = true;
        if (G[x][y] == 't') {
            if (dist < distMin or distMin == -1) distMin = dist;
        }
        Q.pop(); // Ya hemos tratado el nodo
        // Miramos los nodos adyacentes (arriba, abajo, izquierda y derecha)
        for (int k = 0; k < 4; ++k) {
            int ii = x + DI[k];
            int jj = y + DJ[k];
            if (dinsLimit(G, ii, jj) and not visit[ii][jj] and G[ii][jj] != 'X') {
                // Agregamos el nodo con distancia + 1
                Q.push({{ii, jj}, dist + 1}); 
                visit[ii][jj] = true;
            }
        }
    }
    return distMin;
}

int main () {
    int n, m; // n, m > 0
    cin >> n >> m;
    grafo mapa = leer(n, m);
    int f, c; // 1 < f < n, 1 < c < m (comienzan desde 1)
    cin >> f >> c;
    int ans = bfs(mapa, f - 1, c - 1);
    if (ans != -1) cout << "distancia minima: " << ans << endl;
    else cout << "no es pot arribar a cap tresor" << endl;
}