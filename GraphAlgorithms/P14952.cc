#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

typedef vector<vector<int> > graf;


// Funcio que llegeix un graf
void llegir(graf &e, int m) {
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }
    // Una optimitzacio seria calcular aqui els graus d'entrada
}

// Funcio que retorna una llista amb la manera més petita d'ordenar les n 
// tasques lexicogràficament
list<int> ordenacioTipologica(graf &g) {
    int n = g.size();
    vector<int> graus(n, 0);
    // Calcular els graus d'entrada de cada node
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < g[u].size(); ++i) {
            ++graus[g[u][i]];
        }
    }

    // Afegim a una cola de prioritat els nodes amb grau d'entrada 0
    // No utilitzem una pila perque necesitem ordenar els nodes
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int u = 0; u < n; ++u) {
        if (graus[u] == 0) pq.push(u);
    }

    // Afegir els nodes de grau d'entrada 0 a la llista (actualitzan graus dels altres) 
    list<int> l;
    while(not pq.empty()) {
        int u = pq.top();
        pq.pop();
        l.push_back(u);
        // Actualizar els graus d'entrada 
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            --graus[v];
            if (graus[v] == 0) pq.push(v);
        }
    }
    return l;
}

// Funcio que imprimeix una llista
void imprimir(const list<int> &l) {
    bool blanc = false;
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (blanc) cout << ' ';
        cout << *it;
        blanc = true;
    }
    cout << endl;
}

int main () {
    int n, m; // 1 <= n <= 10^4, 0 <= 10 <= 10n
    while (cin >> n >> m) {
        graf entrada(n, vector<int>(0));
        llegir(entrada, m);
        list<int> ordre = ordenacioTipologica(entrada);
        imprimir(ordre);
    }
}