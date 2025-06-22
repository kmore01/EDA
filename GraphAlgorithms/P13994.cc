// Programa que imprimeix el cami mes curt x --> y

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>  // INT_MAX

using namespace std;

typedef vector<vector<pair<int, int> > > grafP;

// Funcio que llegeix un graf
void leer(grafP &g, int m) {
    for (int i = 0; i < m; ++i) {
        int u, v, c; // u != v, 1 <= c <= 10^4
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        // u --> v (pes v)
    }
}

// Funcio que calcula la minima distancia a tots els nodes desde x incloent el 
// node previ
void dijkstra(const grafP &g, int x, vector<int> &dist, vector<int> &prev) {
    int n = g.size();
    // Vector amb les distancies de x a cada node, incialment totes infinites
    dist = vector<int>(n, INT_MAX);
    dist[x] = 0; // Distancia del primer node a ell mateix 0
    // Vector amb els nodes previs
    prev = vector<int>(n, -1); 
    // Vector per els nodes ya vists
    vector<bool> removed(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
    pq.push({0, x});

    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        // Si no hem vist el node
        if (not removed[u]) {
            removed[u] = true;
            // Per a cada vei del node u... 
            for (int i = 0; i < g[u].size(); ++i) {
                int v = g[u][i].second; // Vei del node u
                int c = g[u][i].first; //  Pes de l'aresta
                // Si la distancia a v abans es major que la distancia a u mes 
                // el pes de l'aresta, actualitzem distancia de v i l'afegim
                if (dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }
}

// Funcio que imprimeix el cami x --> y mes curt
void reconstruirCami(const vector<int> &p, int x, int y) {
    stack<int> s;
    int nodePrev = y;
    while (nodePrev != -1 and nodePrev != x) {
        s.push(nodePrev);
        nodePrev = p[nodePrev];
    }
    if (nodePrev == x) s.push(x);
    bool blanc = false;
    while (not s.empty()) {
        if (blanc) cout << ' ';
        cout << s.top();
        s.pop();
        blanc = true;
    }
    cout << endl;
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
            reconstruirCami(previ, x, y); 
        }
        else cout << "no path from " << x << " to " << y << endl; // No trobat
    }
}