#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // INT_MAX

using namespace std;

typedef vector<vector<pair<int, int>>> grafP;

// Función que lee un grafo dirigido con pesos
void leer(grafP &g, int m) {
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({c, v});
    }
}

// Función que calcula la mínima distancia y el número de caminos
void dijkstra(const grafP &g, int x, vector<int> &dist, vector<int> &ways) {
    int n = g.size();
    dist = vector<int>(n, INT_MAX);
    ways = vector<int>(n, 0); // Almacena el número de caminos hacia cada nodo

    dist[x] = 0;
    ways[x] = 1;  // Solo hay una forma de estar en el nodo de inicio

    // Priority queue que almacena {distancia, nodo}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, x});

    while (not pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;   // Distancia acumulada
        int u = top.second;  // Nodo actual

        // Ignorar si no es la mejor distancia
        if (d <= dist[u]) {
            // Vecinos
            for (pair f : g[u]) {
                int c = f.first, v = f.second;
                // Si encontramos un camino mejor, actualizamos la distancia y los caminos
                if (dist[v] > d + c) {
                    dist[v] = d + c;
                    ways[v] = ways[u];  // Si encontramos un nuevo camino mínimo
                    pq.push({dist[v], v});
                }
                else if (dist[v] == d + c) {
                    // Si encontramos otro camino con la misma distancia mínima
                    ways[v] += ways[u];  // Sumamos el número de caminos
                }
            }
        }

    }
}

int main () {
    int n, m; // 1 <= n <= 10^4, 0 <= m <= 5n
    while (cin >> n >> m) {
        grafP entrada(n);
        leer(entrada,  m);
        int x, y;
        cin >> x >> y;
        vector<int> distancies, ways;
        dijkstra(entrada, x, distancies, ways);
        // No es pot fer servir prev (?)
        if (distancies[y] != INT_MAX) { // Si trobat
            cout << "cost " << distancies[y] << ", "
                 << ways[y] << " way(s)" << endl; 
        }
        else cout << "no path from " << x << " to " << y << endl; // No trobat
    }
}
