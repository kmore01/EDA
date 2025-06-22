#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void llegir(vector<int> &v) {
    for (int i = 0; i < int(v.size()); ++i) {
        cin >> v[i];
    }
}

int combinacions(const vector<int> &m, vector<bool> &visit, vector<bool> &visit2, int x, int sum, int idx) {
    // Cas base
    if (sum == x) {
        return 1;
    }
    // Cas recursiu
    else if (sum < x and idx < int(m.size())) {
        int res = 0;
        if (not visit[idx] and sum + m[idx] <= x) {
            visit[idx] = true;
            res += combinacions(m, visit, visit2, x, sum + m[idx], idx);
            visit[idx] = false;
        }
        else if (not visit2[idx] and sum + m[idx] <= x) {
            visit2[idx] = true;
            res += combinacions(m, visit, visit2, x, sum + m[idx], idx + 1);
            visit2[idx] = false;
        }
        res += combinacions(m, visit, visit2, x, sum, idx + 1);
        return res;
    }
    return 0;
}

int main () {
    int x, n; // 1 <= n <= 20, 1 <= m <= x <= 1000
    while (cin >> x >> n) {
        vector<int> monedes(n);
        llegir(monedes);
        sort(monedes.begin(), monedes.end()); // Ordenar el vector de monedes
        vector<bool> visitats(n, false);
        vector<bool> visitats2(n, false);
        int i = 0, sumaActual = 0;
        cout << combinacions(monedes, visitats, visitats2, x, sumaActual, i) << endl;
    } 
}