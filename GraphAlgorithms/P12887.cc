#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> P;

// Funcion para leer un grafo no dirigido con pesos
void leer(vector<vector<P> > &graf, int m) {
    for (int i = 0; i < m; ++i) {
        int u, v, w; // u vertice, v vertice y w peso
        cin >> u >> v >> w;
        // u, w empiezan desde 1, en nuestro grafo, el vertice 1 sera el 0...
        graf[u - 1].push_back({w, v - 1});
        graf[v - 1].push_back({w, u - 1});
    }
}

// Funcion que calcula el peso minimo arbol de expansion minimo
// usando el algoritmo de Prim (se basa en un algoritmo greedy)
int mst(const vector<vector<P> >& g) {
    int n = g.size();
    vector<bool> visit(n, false); // Vector de vertices visitados
    visit[0] = true; // Empezamos por el primero
    // Usaremos una cola de prioridad para almacenar las aristas eligiendo
    // siempre la de menor peso siempre
    priority_queue<P, vector<P>, greater<P> > pq;
    // Almacenamos los vertices vecinos del primer vertice
    for (P x : g[0]) pq.push(x);
    int verticAgreg = 1, sum = 0;
    // No pararemos hasta agregar todos los vertices
    while (verticAgreg < n) {
        int c = pq.top().first; // Peso
        int x = pq.top().second; // Vecino
        pq.pop();
        if (not visit[x]) {
            visit[x] = true;
            // Agregamos los vecinos del vecino
            for (P y : g[x]) pq.push(y);
            sum += c;
            ++verticAgreg;
        }
    }
    return sum;
}

int main () {
    int n, m; // n >= 1, w >= 1
    while (cin >> n >> m) {
        vector<vector<P> > graf(n, vector<P>(0));
        leer(graf, m);
        cout << mst(graf) << endl;
    }
}