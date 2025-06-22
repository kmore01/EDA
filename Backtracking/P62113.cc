#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void llegir(vector<int> &v) {
    for (int i = 0; i < int(v.size()); ++i) {
        cin >> v[i];
    }
}

void combinacions(const vector<int> &m, vector<bool> &visit, vector<bool> &visit2, int x, int sum, int idx) {
    // Cas base
    if (sum == x) {
        int current = 0;
        cout << x << " = ";
        for (int i = 0; i < int(m.size()); ++i) {
            if (visit[i]) {
                cout << m[i];
                current += m[i];
                if (current != x)  cout << " + ";
            }
            if (visit2[i]) {
                cout << m[i] << 'p';
                current += m[i];
                if (current != x)  cout << " + ";
            }
        }
        cout << endl;
    }
    // Cas recursiu
    else if (sum < x and idx < int(m.size())) {
        if (not visit[idx] and sum + m[idx] <= x) {
            visit[idx] = true;
            combinacions(m, visit, visit2, x, sum + m[idx], idx);
            visit[idx] = false;
        }
        if (not visit2[idx] and sum + m[idx] <= x) {
            visit2[idx] = true;
            combinacions(m, visit, visit2, x, sum + m[idx], idx + 1);
            visit2[idx] = false;
        }
        combinacions(m, visit, visit2, x, sum, idx + 1);
    }
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
        combinacions(monedes, visitats, visitats2, x, sumaActual, i);
        cout << "----------" << endl;
    } 
}