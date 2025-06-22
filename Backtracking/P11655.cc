#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int llegir(vector<int> &v) {
    int suma = 0, size = int(v.size());
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
        suma += v[i];
    }
    return suma;
}

void backtracking(vector<int> &v, int idx, const vector<int> &n, int s,
                  int sumaActual, int sumaTotal) {
    // Cas base
    if (sumaActual == s) {
        cout << '{';
        bool coma = false;
        int size = int(v.size());
        for (int i = 0; i < size; ++i) {
            if (coma) cout << ',';
            cout << v[i];
            coma = true;
        }
        cout << '}' << endl;
    }
    // Cas recursiu
    else {
        int size = int(n.size());
        for (int i = idx; i < size; ++i) {
            int elem = n[i];
            if (sumaActual > s or sumaTotal < s) return;
            v.push_back(elem);
            backtracking(v, i + 1, n, s, sumaActual + elem, sumaTotal);
            v.pop_back();
        }
    }
}

int main() {
    int s, n;  // n > 0
    cin >> s >> n;
    vector<int> num(n);
    int sumaTots = llegir(num);
    sort(num.begin(), num.end());  // Per afegir els 0's primer
    vector<int> solucio;
    backtracking(solucio, 0, num, s, 0, sumaTots);
}