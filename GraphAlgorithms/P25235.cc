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

// Función que calcula la mínima distancia y el número mínimo de pasos desde x
void dijkstra(const grafP &g, int x, vector<int> &dist, vector<int> &prev) {
    int n = g.size();
    dist = vector<int>(n, INT_MAX);
    vector<int> steps(n, INT_MAX); // Almacena el número de pasos mínimos
    prev = vector<int>(n, -1);

    dist[x] = 0;
    steps[x] = 0;

    // Priority queue que almacena {{distancia, pasos}, nodo}
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<>> pq;
    pq.push({{0, 0}, x});

    while (not pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first.first;   // Distancia acumulada
        int s = top.first.second; // Número de pasos acumulados
        int u = top.second;       // Nodo actual

        // Ignorar si no es la mejor distancia
        if (d <= dist[u])  {
            // Vecinos
            for (pair f : g[u]) {
                int c = f.first, v = f.second;
                // Condición para actualizar: menor costo o igual costo con menos pasos
                if (dist[v] > d + c or (dist[v] == d + c and steps[v] > s + 1)) {
                    dist[v] = d + c;
                    steps[v] = s + 1;
                    prev[v] = u;
                    pq.push({{dist[v], steps[v]}, v});
                }
            }
        }
    }
}

// Función para reconstruir el número de pasos
int nodes(const vector<int> &p, int x, int y) {
    int cont = 0;
    int nodePrev = y;
    while (nodePrev != -1) {
        if (nodePrev == x) return cont; // Se llegó a x
        ++cont;
        nodePrev = p[nodePrev];
    }
    return -1; // Si no se llega a x, retornar -1
}

int main () {
    int n, m; // 1 <= n <= 10^4, 0 <= m <= 5n
    while (cin >> n >> m) {
        grafP entrada(n);
        leer(entrada,  m);
        int x, y;
        cin >> x >> y;
        vector<int> distancies, previ;
        dijkstra(entrada, x, distancies, previ);
        // No es pot fer servir prev (?)
        if (distancies[y] != INT_MAX) { // Si trobat
            int steps = nodes(previ, x, y);
            cout << "cost " << distancies[y] << ", "
                 << steps << " step(s)" << endl; 
        }
        else cout << "no path from " << x << " to " << y << endl; // No trobat
    }
}