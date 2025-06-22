// PRIM (MST)

// El algoritmo de Prim te devuelve el coste mínimo para que el
// grafo sea conexo

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<pair<int, int>>> grafP;
typedef pair<int, int> P;

int llegir(grafP &g, int m) {
    int poble1, poble2, cost, total = 0;
    for (int i = 0; i < m; ++i) {
        cin >> poble1 >> poble2 >> cost;
        g[poble1].push_back({cost, poble2});
        g[poble2].push_back({cost, poble1});
        total += cost;
    }
    return total;
}

int mst(const grafP &g, int total) {
    int n = g.size();
    vector<bool> visit(n, false);
    visit[0] = true;
    priority_queue<P, vector<P>, greater<P>> pq;
    for (P x : g[0]) pq.push(x);
    int size = 1;
    int sum = 0;
    while (size < n) {
        int c = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (not visit[x]) {
            visit[x] = true;
            for (P y : g[x]) pq.push(y);
            sum += c;
            ++size;
        }
    }
    return total - sum;
}

int main() {
    int pobles, carreteres;
    while (cin >> pobles >> carreteres) {
        grafP graf(pobles);
        int total = llegir(graf, carreteres);
        cout << mst(graf, total) << endl;
    }
}
