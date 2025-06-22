#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int DI[4] = {0, -1, 0, 1};
const int DJ[4] = {1, 0, 1, 0};

void llegir(vector<vector<char>> &t, int &fa, int &ca) {
    int n = t.size();
    int m = t[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t[i][j];
            if (t[i][j] == 'K') {
                fa = i;
                ca = j;
            }
        }
    }
}

bool isOk(int i, int j, int n, int m) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

int bfs(const vector<vector<char>> &t, int i, int j) {
    int nodos = t.size(), distMin = -1;
    queue<pair<pair<int, int>, int>> Q;  // ((i, j), distancia)
    vector<vector<bool>> visit(nodos, vector<bool>(t[0].size(), false));
    Q.push({{i, j}, 0});  // La distancia del primer nodo es 0

    vector<vector<int>> camins;
    if (i == 1) {
        camins.push_back({j});
    } else
        camins.push_back({i + j});

    while (not Q.empty()) {
        if (i == 1) {
            camins.push_back({j});
        } else
            camins.push_back({i + j});

        int x = Q.front().first.first;   // Posicion x del nodo
        int y = Q.front().first.second;  // Posicion y del nodo
        int dist = Q.front().second;  // Distancia del nodo respecto al comienzo
        visit[x][y] = true;
        if (t[x][y] == 'F') {
            if (dist < distMin or distMin == -1) {
                distMin = dist;
            }
        }
        Q.pop();  // Ya hemos tratado el nodo
        // Miramos los nodos adyacentes (arriba, abajo, izquierda y derecha)
        for (int k = 0; k < 4; ++k) {
            int ii = x + DI[k];
            int jj = y + DJ[k];
            if (isOk(ii, jj, t.size(), t[0].size()) and not visit[ii][jj] and
                t[ii][jj] != 'X') {
                // Agregamos el nodo con distancia + 1
                Q.push({{ii, jj}, dist + 1});
                visit[ii][jj] = true;
            }
        }
    }
    return distMin;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> tauler(n, vector<char>(m));
        int filaActual, columnaActual;
        llegir(tauler, filaActual, columnaActual);
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        cout << bfs(tauler, filaActual, columnaActual) + 1 << endl;
    }
}