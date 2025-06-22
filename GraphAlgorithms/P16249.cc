#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef vector<vector<int> > grafo;

// Funcion para imprimir el orden de las tareas
void ordenacioTopologica(const grafo &g, vector <int> &grausEn, map <string, int> &num, map <int, string> &str) {
    int n = int(g.size());
    // Afegim a una cola de prioritat els nodes amb grau d'entrada 0
    // No utilitzem una pila perque necesitem ordenar els nodes
    priority_queue<string, vector<string>, greater<string>> pq;
    for (auto it = num.begin(); it != num.end(); ++it) {
        if (grausEn[it->second] == 0) pq.push(it->first);
    }

    // Anem esborrant cada node i afegint de nou, una vegada eliminat, els de 
    // grau d'entrada 0 nous
    queue<string> orden;
    while (not pq.empty()) {
        string u = pq.top();
        pq.pop();
        orden.push(u);
        for (int v : g[num[u]]) {
            --grausEn[v];
            if (grausEn[v] == 0) pq.push(str[v]);
        }
    }

    // Escriptura
    if (orden.size() != n) cout << "NO VALID ORDERING" << endl;
    else {
        while (not orden.empty()) {
            cout << orden.front();
            orden.pop();
        }
        cout << endl;
    }
}

int main () {
    int n;
    while (cin >> n) {
        // Leer entrada
        map <string, int> num;
		map <int, string> str;
        for (int i = 0; i < n; ++i) {
            string tarea;
            cin >> tarea;
            num[tarea] = i;
            str[i] = tarea;
        }
        int m;
        cin >> m;
        vector <int> grausEntrada(n, 0);
		grafo g(n);
        for (int i = 0; i < m; ++i) {
            string u, v;
			cin >> u >> v;
			g[num[u]].push_back(num[v]);
			++grausEntrada[num[v]];            
        }
        ordenacioTopologica(g, grausEntrada, num, str);
    }
}